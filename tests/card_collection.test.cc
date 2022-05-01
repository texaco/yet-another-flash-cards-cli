#include "card_collection.test.h"

#include <stdlib.h>
#include "gtest/gtest.h"

#include "card_collection.h"

namespace yet {
  namespace another_flash_cards_cli {
    namespace card_collection {

      // The fixture for testing.
      // You can remove any or all of the following functions if their bodies would
      // be empty.

      CardCollectionTest::CardCollectionTest() {
        // Constructor needed if fixture is needed. It is only needed
        // if TEST_F is in use.
      }

      CardCollectionTest::~CardCollectionTest() {
        // You can do clean-up work that doesn't throw exceptions here.
      }

      // If the constructor and destructor are not enough for setting up
      // and cleaning up each test, you can define the following methods:

      void CardCollectionTest::SetUp() {
        // Code here will be called immediately after the constructor (right
        // before each test).

      }

      void CardCollectionTest::TearDown() {
        // Code here will be called immediately after each test (right
        // before the destructor).
      }

      // Class members declared here can be used by all tests in the test suite
      // for CardModel.
      TEST(CardCollectionTest, Factory) {

        CardCollection* collection = createCardCollection();
        EXPECT_NE(collection, nullptr) << "Collection should NOT be NULL";
        EXPECT_EQ((*collection).data.id, 0) << "Collection node data.id should be 0";
        EXPECT_STREQ((*collection).data.name, "") << "Collection node data.name should be empty string";
        EXPECT_STREQ((*collection).data.content, "") << "Collection node data.content should be empty string";
        EXPECT_EQ((*collection).next, nullptr) << "Collection Next should be NULL";

        destroyCardCollection(collection);
        collection = NULL;

        EXPECT_EQ(collection, nullptr) << "Collection should be NULL";
      }
    }  // namespace card_collection
  }  // namespace another_flash_cards_cli
}  // namespace yet
