#include "gtest/gtest.h"
#include "cards_model.test.h"

namespace yet {
  namespace another_flash_cards_cli {
    namespace {
      // The fixture for testing class CardModel.
      // You can remove any or all of the following functions if their bodies would
      // be empty.

      CardModelTest::~CardModelTest() {
        // You can do clean-up work that doesn't throw exceptions here.
      }

      // If the constructor and destructor are not enough for setting up
      // and cleaning up each test, you can define the following methods:

      void CardModelTest::SetUp() {
        // Code here will be called immediately after the constructor (right
        // before each test).
      }

      void CardModelTest::TearDown() {
        // Code here will be called immediately after each test (right
        // before the destructor).
      }

      // Class members declared here can be used by all tests in the test suite
      // for CardModel.

      TEST(DummySuit, DummyTest) {
        EXPECT_EQ(1, 1);
      }

    }  // namespace
  }  // namespace another_flash_cards_cli
}  // namespace yet
