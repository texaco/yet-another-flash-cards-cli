#include "gtest/gtest.h"

namespace yet {
  namespace another_flash_cards_cli {
    namespace {
      // The fixture for testing class CardModel.
      class CardModelTest : public ::testing::Test {
      protected:
        // You can remove any or all of the following functions if their bodies would
        // be empty.

        CardModelTest() {
          // You can do set-up work for each test here.
        }

        ~CardModelTest() override {
          // You can do clean-up work that doesn't throw exceptions here.
        }

        // If the constructor and destructor are not enough for setting up
        // and cleaning up each test, you can define the following methods:

        void SetUp() override {
          // Code here will be called immediately after the constructor (right
          // before each test).
        }

        void TearDown() override {
          // Code here will be called immediately after each test (right
          // before the destructor).
        }

        // Class members declared here can be used by all tests in the test suite
        // for CardModel.
      };

      TEST(DummySuit, DummyTest) {
        EXPECT_EQ(1, 1);
      }

    }  // namespace
  }  // namespace another_flash_cards_cli
}  // namespace yet




/*

this scope must be included in cards_model_test.h

namespace yet {
  namespace another_flash_cards_cli {
    namespace {
      // The fixture for testing class CardModel.
      class CardModelTest : public ::testing::Test {
      protected:
        // You can remove any or all of the following functions if their bodies would
        // be empty.

        CardModelTest(); // You can do set-up work for each test here.

        ~CardModelTest() override; // You can do clean-up work that doesn't throw exceptions here.

        // If the constructor and destructor are not enough for setting up
        // and cleaning up each test, you can define the following methods:

        void SetUp() override;
          // Code here will be called immediately after the constructor (right
          // before each test).

        void TearDown() override;
          // Code here will be called immediately after each test (right
          // before the destructor).

        // Class members declared here can be used by all tests in the test suite
        // for CardModel.
      };

      TEST(DummySuit, DummyTest) {
        EXPECT_EQ(1, 1);
      }

    }  // namespace
  }  // namespace another_flash_cards_cli*/
}  // namespace yet

