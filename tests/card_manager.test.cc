#include "card_manager.test.h"

#include "gtest/gtest.h"
#include "card_model.h"
#include "card_collection.h"
#include "card_manager.h"

namespace yet {
  namespace another_flash_cards_cli {
    namespace card_manager {

      CardCollection* cardCollection;
      unsigned int CARD_ID = 33;
      char CARD_NAME[] = "a card name";
      char CARD_CONTENT[] = "a card content";

      // The fixture for testing class CardModel.
      // You can remove any or all of the following functions if their bodies would
      // be empty.

      CardManagerTest::CardManagerTest() {
        // Constructor needed if fixture is needed. It is only needed
        // if TEST_F is in use.
      }

      CardManagerTest::~CardManagerTest() {
        // You can do clean-up work that doesn't throw exceptions here.
      }

      // If the constructor and destructor are not enough for setting up
      // and cleaning up each test, you can define the following methods:

      void CardManagerTest::SetUp() {
        // Code here will be called immediately after the constructor (right
        // before each test).
        cardCollection = createCardCollection();
      }

      void CardManagerTest::TearDown() {
        // Code here will be called immediately after each test (right
        // before the destructor).
        destroyCardCollection(cardCollection);
      }

      // Class members declared here can be used by all tests in the test suite
      // for CardModel.
      TEST_F(CardManagerTest, AddsNewCard) {
        Card card = addNewCard(&cardCollection, CARD_ID, CARD_NAME, CARD_CONTENT);
        EXPECT_NE(&card, nullptr) << "Result should be NULL.";
        EXPECT_EQ(card.id, CARD_ID) << "Result id should be settled.";
        EXPECT_STREQ(card.name, CARD_NAME) << "Result name should be settled.";
        EXPECT_STREQ(card.content, CARD_CONTENT) << "Result content should be settled.";
        EXPECT_EQ((*cardCollection).data.id, CARD_ID) << "CardCollection node id should be settled.";
        EXPECT_STREQ((*cardCollection).data.name, CARD_NAME) << "CardCollection node name should be settled.";
        EXPECT_STREQ((*cardCollection).data.content, CARD_CONTENT)<< "CardCollection node content should be settled.";
        EXPECT_NE((*cardCollection).next, nullptr) << "CardCollection node next should NOT be NULL.";

        CardCollection* finalNode = (CardCollection*)(*cardCollection).next;
        EXPECT_EQ((*finalNode).next, nullptr) << "CardCollection final node next shuld be NULL.";
      }

      TEST_F(CardManagerTest, AddsMultipleNewCard) {
        for(int i = 0; i < 5; i++ ){
          addNewCard(&cardCollection, CARD_ID + i, CARD_NAME, CARD_CONTENT);
        }

        CardCollection* cardCollectionPivot = cardCollection;
        for(int i = 0; i < 5; i++ ){
          EXPECT_EQ((CARD_ID + 4) - i, (*cardCollectionPivot).data.id) << "Each node ID should have a given ID.";
          cardCollectionPivot = (CardCollection*)(*cardCollectionPivot).next;
        }

        EXPECT_EQ((*cardCollectionPivot).next, nullptr) << "The last collection node next should point to NULL.";
      }

      TEST_F(CardManagerTest, GetCardById) {
        for(int i = 0; i < 5; i++ ){
          addNewCard(&cardCollection, i + 1, CARD_NAME, CARD_CONTENT);
        }

        Card card;
        for(int i = 0; i < 5; i++ ){
          card = *getCardById(cardCollection, i + 1);
          EXPECT_EQ(card.id, i+1) << "getCardById should return a Card with the right card id.";
        }

        const unsigned int NON_EXISTANT_ID = 99;
        EXPECT_EQ(nullptr, getCardById(cardCollection, NON_EXISTANT_ID)) << "getCardById should return a NULL pointer if a non existant ID is passed.";
      }

      TEST_F(CardManagerTest, destroyCardById) {
        for(int i = 0; i < 5; i++ ){
          addNewCard(&cardCollection, i + 1, CARD_NAME, CARD_CONTENT);
        }

        for(int i = 0; i < 5; i++ ){
          EXPECT_NE(nullptr, getCardById(cardCollection, i+1)) << "Card ID should exists before to be freed.";
          destroyCardById(&cardCollection, i + 1);
          EXPECT_EQ(nullptr, getCardById(cardCollection, i+1)) << "destroyCardById should delete the card node so after trying to get it by ID should return a NULL pointer.";
        }
      }

    }  // namespace cards_manager
  }  // namespace another_flash_cards_cli
}  // namespace yet
