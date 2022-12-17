#include <gtest/gtest.h>
#include "gmock/gmock-matchers.h"
#include "rock_paper_scissor.h"

namespace rock_paper_scissor
{
    namespace
    {
        using ::testing::AllOf;
        using ::testing::AnyOfArray;
        using testing::Eq;
        using ::testing::Field;
        using ::testing::HasSubstr;
        using ::testing::VariantWith;

        TEST(RockPaperScissorTest, UserEntersValidUserAction)
        {
            EXPECT_TRUE(isValidUserAction("R"));
            EXPECT_TRUE(isValidUserAction("P"));
            EXPECT_TRUE(isValidUserAction("S"));
            EXPECT_TRUE(isValidUserAction("exit"));
        }

        TEST(RockPaperScissorTest, UserEntersInvalidUserAction)
        {
            EXPECT_FALSE(isValidUserAction("r"));
            EXPECT_FALSE(isValidUserAction("rsd"));
            EXPECT_FALSE(isValidUserAction("rck"));
        }

        TEST(RockPaperScissorTest, ParseUserActionSuccess)
        {
            EXPECT_THAT(parseUserAction("R"), VariantWith<Action>(Action::ROCK));
            EXPECT_THAT(parseUserAction("P"), VariantWith<Action>(Action::PAPER));
            EXPECT_THAT(parseUserAction("S"), VariantWith<Action>(Action::SCISSOR));
        }

        TEST(RockPaperScissorTest, ParseUserActionError)
        {
            EXPECT_THAT(parseUserAction("Re"),
                        VariantWith<Error>(Field(&Error::error_message, HasSubstr("Invalid user action"))));
        }

        TEST(RockPaperScissorTest, RandomActionGeneration)
        {
            EXPECT_THAT(generateRandomAction(), AnyOfArray({Action::PAPER, Action::ROCK, Action::SCISSOR}));
        }

        TEST(RockPaperScissorTest, MakeDecision)
        {
            EXPECT_EQ(makeDecision(/*userAction=*/Action::ROCK, /*computerAction=*/Action::ROCK), Result::DRAW);
            EXPECT_EQ(makeDecision(/*userAction=*/Action::ROCK, /*computerAction=*/Action::PAPER), Result::LOSE);
            EXPECT_EQ(makeDecision(/*userAction=*/Action::ROCK, /*computerAction=*/Action::SCISSOR), Result::WIN);
            EXPECT_EQ(makeDecision(/*userAction=*/Action::PAPER, /*computerAction=*/Action::ROCK), Result::WIN);
            EXPECT_EQ(makeDecision(/*userAction=*/Action::PAPER, /*computerAction=*/Action::PAPER), Result::DRAW);
            EXPECT_EQ(makeDecision(/*userAction=*/Action::PAPER, /*computerAction=*/Action::SCISSOR), Result::LOSE);
            EXPECT_EQ(makeDecision(/*userAction=*/Action::SCISSOR, /*computerAction=*/Action::ROCK), Result::LOSE);
            EXPECT_EQ(makeDecision(/*userAction=*/Action::SCISSOR, /*computerAction=*/Action::PAPER), Result::WIN);
            EXPECT_EQ(makeDecision(/*userAction=*/Action::SCISSOR, /*computerAction=*/Action::SCISSOR), Result::DRAW);
        }

        TEST(RockPaperScissorTest, MakeDecisionWithInvalidInput)
        {
            EXPECT_EQ(makeDecision(/*userAction=*/static_cast<Action>(123), /*computerAction=*/Action::PAPER), Result::UNDEFINED);
        }
    }
}