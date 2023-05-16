#ifndef __CARD_COLLECTION_TEST_H__
#define __CARD_COLLECTION_TEST_H__

#include "gtest/gtest.h"

namespace yet {
  namespace another_flash_cards_cli {
    namespace card_collection {
      // The fixture for testing class.
      class CardCollectionTest : public ::testing::Test {
      protected:
        // You can remove any or all of the following functions if their bodies would
        // be empty.

        // You can do set-up work for each test here.
        CardCollectionTest();

        // You can do clean-up work that doesn't throw exceptions here.
        ~CardCollectionTest();

        // If the constructor and destructor are not enough for setting up
        // and cleaning up each test, you can define the following methods:

        // Code here will be called immediately after the constructor (right
        // before each test).
        void SetUp();

        // Code here will be called immediately after each test (right
        // before the destructor).
        void TearDown();

        // Class members declared here can be used by all tests in the test suite
        // for CardManager.
      };

    }  // namespace card_collection
  }  // namespace another_flash_cards_cli
}  // namespace yet

#endif
