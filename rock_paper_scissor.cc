#include "rock_paper_scissor.h"
#include "string"
#include "iostream"
#include "map"
#include <random>

namespace
{
    using rock_paper_scissor::Action;
    using UserAction = rock_paper_scissor::Action;
    using ComputerAction = rock_paper_scissor::Action;

    const std::map<std::string, Action> inputToActionMap = {
        {"R", Action::ROCK},
        {"P", Action::PAPER},
        {"S", Action::SCISSOR},
        {"exit", Action::EXIT}};

    std::string getActionStringName(Action action)
    {
        switch (action)
        {
        case Action::ROCK:
            return "Rock";
            break;
        case Action::PAPER:
            return "Paper";
            break;
        case Action::SCISSOR:
            return "Scissor";
            break;
        case Action::EXIT:
            return "Exit";
            break;
        default:
            return "";
            break;
        }
    }
}

namespace rock_paper_scissor
{

    std::string getUserInput()
    {
        std::cout << "Enter your move(R/P/S/exit)" << std::endl;
        std::string in;
        std::cin >> in;
        // Maybe check input here to prevent security threats.
        return in;
    }

    bool isValidUserAction(const std::string &input)
    {
        return inputToActionMap.find(input) != inputToActionMap.end();
    }

    std::variant<Action, Error> parseUserAction(const std::string &input)
    {
        if (!isValidUserAction(input))
            return Error{"Invalid user action : " + input};
        return inputToActionMap.find(input)->second;
    }

    Action generateRandomAction()
    {
        return static_cast<Action>(rand() % kNumActions);
    }

    Result makeDecision(Action userAction, Action computerAction)
    {
        static const std::map<std::pair<UserAction, ComputerAction>, Result> decisonMap = {
            {{Action::ROCK, Action::ROCK}, Result::DRAW},
            {{Action::ROCK, Action::PAPER}, Result::LOSE},
            {{Action::ROCK, Action::SCISSOR}, Result::WIN},
            {{Action::PAPER, Action::ROCK}, Result::WIN},
            {{Action::PAPER, Action::PAPER}, Result::DRAW},
            {{Action::PAPER, Action::SCISSOR}, Result::LOSE},
            {{Action::SCISSOR, Action::ROCK}, Result::LOSE},
            {{Action::SCISSOR, Action::PAPER}, Result::WIN},
            {{Action::SCISSOR, Action::SCISSOR}, Result::DRAW}};

        if (auto iter = decisonMap.find({userAction, computerAction}); iter != decisonMap.end())
        {
            std::cout << "You choose " << getActionStringName(userAction) << " & computer choose " << getActionStringName(computerAction) << std::endl;
            return iter->second;
        }
        else
        {
            LOG(ERROR) << "Not found in decisonMap";
            return Result::UNDEFINED;
        }
    }
} // rock_paper_scissor
