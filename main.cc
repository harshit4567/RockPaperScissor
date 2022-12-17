#include "rock_paper_scissor.h"
#include <iostream>
#include <glog/logging.h>

using rock_paper_scissor::Action;
using rock_paper_scissor::Error;
using rock_paper_scissor::generateRandomAction;
using rock_paper_scissor::getUserInput;
using rock_paper_scissor::isValidUserAction;
using rock_paper_scissor::makeDecision;
using rock_paper_scissor::parseUserAction;
using rock_paper_scissor::Result;

int main(int argc, char *argv[])
{

    google::InitGoogleLogging(argv[0]);
    // This is to disable logging to stderr and instead log to log files.
    google::SetStderrLogging(3);
    // Set seed so that random does not return the same set of numbers.
    srand(time(0));

    std::cout << "Welcome to Rock, Paper, Scissors game " << std::endl;
    std::cout << "R, P, S are the valid input options for Rock, Paper & Scissors respectively" << std::endl;
    std::cout << "enter \"exit\" to exit the game" << std::endl;

    while (1)
    {
        std::string input = getUserInput();
        LOG_EVERY_N(INFO, 5) << "Input is : " << input;
        std::variant<Action, Error> userAction = parseUserAction(input);
        if (std::holds_alternative<Error>(userAction))
        {
            LOG(ERROR) << std::get<Error>(userAction).error_message;
            std::cout << "Invalid user action, try again" << std::endl;
            continue;
        }
        if (std::get<Action>(userAction) == Action::EXIT)
        {
            std::cout << "Exiting the program. Thank you!!\n";
            return 0;
        }
        Action computerAction = generateRandomAction();
        Result result = makeDecision(std::get<Action>(userAction), computerAction);
        switch (result)
        {
        case Result::WIN:
            std::cout << "Congrats!! you won" << std::endl;
            break;
        case Result::DRAW:
            std::cout << "Nice!! you made it a draw" << std::endl;
            break;
        case Result::LOSE:
            std::cout << "You lost :(  dont worry, you were playing against a computer" << std::endl;
            break;
        default:
            std::cout << "Undefined result, please check the inputs" << std::endl;
            break;
        }
    }
    return 0;
}