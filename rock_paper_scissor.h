#include "string"
#include "iostream"
#include "map"
#include <random>
#include <glog/logging.h>

namespace rock_paper_scissor
{

    enum class Action
    {
        ROCK,
        PAPER,
        SCISSOR,
        EXIT
    };
    constexpr int kNumActions = 3;

    enum class Result
    {
        WIN,
        LOSE,
        DRAW,
        UNDEFINED
    };

    struct Error
    {
        std::string error_message;
    };

    std::string getUserInput();

    // Returns true if the input string is a valid user action.
    bool isValidUserAction(const std::string &input);

    // Parses input string to  Action, return Error if input is not a vaid user action.
    std::variant<Action, Error> parseUserAction(const std::string &input);

    // Generates a random Action based on kNumActions
    Action generateRandomAction();

    // Returns the result for the given userAction, computerAction. 
    // For invalid inputs returns UNDEFINED
    Result makeDecision(Action userAction, Action computerAction);

} // rock_paper_scissor