
#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <random>
#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include <ctime>
#include "Functions.h"

int main()
{
    bool game_desire = true;
    bool quota_flag = false;

    int money = 0;
    int round = 1;
    
    df::print("It's not important why you are here. But here is the rules:", true);

    print("It's not important why you are here. But here is the rules:", true);
    std::this_thread::sleep_for(std::chrono::nanoseconds(500000000));
    df::print("There is a revolver, and you have to earn at least 1200$,", true);
    std::this_thread::sleep_for(std::chrono::nanoseconds(500000000));
    df::print("Each bullet in the revolver gives you 100$. It's time to play..\n", true);
    std::this_thread::sleep_for(std::chrono::nanoseconds(500000000));

    std::cout << "                             .";
    std::this_thread::sleep_for(std::chrono::nanoseconds(500000000));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::nanoseconds(500000000));
    std::cout << "." << std::endl;
    std::this_thread::sleep_for(std::chrono::nanoseconds(500000000));

    while (game_desire)
    {
        df::print("\nCurrent balance: ", false), std::cout << money << "$" << std::endl;
        df::print("Round: ", false), std::cout << round << "." << std::endl;
        short bullets = df::choice();

        if (df::spinning())
        {
            df::game(bullets, money, round, game_desire);
        }

        if (money >= 1200 && quota_flag == false)
        {
            df::print("\nYou earned enough.", true);
            quota_flag = true;
        }
        if (quota_flag)
        {
            df::print("Say LEAVE to finish the game.", true);
            std::string answer;
            std::cin >> answer;
            if (answer == "LEAVE")
            {
                game_desire = false;
            }
        }
    }

    std::cout << "\n           ";
    df::print("You won.", true);
    df::print("Sending report to the Company..\n", true);

    std::cout << "[";
    for (int i = 0; i < 29; i++)
    {
        std::cout << "|";
        std::this_thread::sleep_for(std::chrono::nanoseconds(rand()*21360));
    }
    std::cout << "]" << std::endl;

    std::ofstream results("GameResults.txt", std::ios::app);
    if (results.is_open())
    {
        time_t seconds = time(NULL);;
        results << "Money earned: " << money << "$. Status: alive. " << "Date: " << ctime(&seconds) << std::endl;
    }
    results.close();

    df::print("\nSending's complete.", true);
}
