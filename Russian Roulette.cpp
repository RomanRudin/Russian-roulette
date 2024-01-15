
#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <random>
#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include <ctime>

void print(std::string line, bool endl)
{
    for (int i = 0; i < size(line); i++)
    {
        std::cout << line[i];
        std::this_thread::sleep_for(std::chrono::nanoseconds(70000000));
    }

    if (endl)
    {
        std::cout << std::endl;
    }
}

void print(std::string line, bool endl, int nanosec)
{
    for (int i = 0; i < size(line); i++)
    {
        std::cout << line[i];
        std::this_thread::sleep_for(std::chrono::nanoseconds(nanosec));
    }

    if (endl)
    {
        std::cout << std::endl;
    }
}

bool spinning()
{
    std::cout << "\nBrrrrrr.." << std::endl;
    std::this_thread::sleep_for(std::chrono::nanoseconds(100000000));
    std::cout << "Brrrrrr.." << std::endl;
    std::this_thread::sleep_for(std::chrono::nanoseconds(300000000));
    std::cout << "Brrrrrr.." << std::endl;
    std::this_thread::sleep_for(std::chrono::nanoseconds(500000000));
    std::cout << "Brrrrrr.." << std::endl;
    std::this_thread::sleep_for(std::chrono::nanoseconds(700000000));
    std::cout << "Brrrrrr.." << std::endl;
    std::this_thread::sleep_for(std::chrono::nanoseconds(1000000000));
    std::cout << "Brrrrrr.." << std::endl;
    std::this_thread::sleep_for(std::chrono::nanoseconds(1000000000));
    std::cout << "\n*flick*\n" << std::endl;
    std::this_thread::sleep_for(std::chrono::nanoseconds(500000000));
    std::cout << "The revolver is ready, but are you?" << std::endl;
    std::cout << "               YES\n" << std::endl;

    std::string answer;
    std::cin >> answer;

    if (answer == "YES")
    {
        return true;
    }
    else
    {
        std::this_thread::sleep_for(std::chrono::nanoseconds(500000000));
        std::cout << "\n.";
        std::this_thread::sleep_for(std::chrono::nanoseconds(500000000));
        std::cout << ".";
        std::this_thread::sleep_for(std::chrono::nanoseconds(500000000));
        std::cout << "." << std::endl;
        std::this_thread::sleep_for(std::chrono::nanoseconds(900000000));
        print("\nYou are not ready yet. But there is no escape.\n", true);
        std::this_thread::sleep_for(std::chrono::nanoseconds(300000000));
        return false;
    }
}

short choice()
{
    while (true)
    {
        print("\nHow many bullets do you need? It's maximum 6 bullets in the cylinder..", true);
        short amount;
        std::cin >> amount;
        if (amount >= 6)
        {
            print("\nARE YOU SURE?", true, 120000000);
            std::string answer;
            std::cin >> answer;
            if (answer == "YES")
            {
                return 6;
            }
        }
        else if (amount < 0)
        {
            print("\nFunny enough.", true);
        }
        else
        {
            return amount;
        }
    }
}

void game(int bullets ,int &money, int &round, bool &game_desire) 
{
    if (rand() % 6 + 1 > bullets)
    {
        print("\nYou survived.. For this time.", true);
        money += bullets * 100;
        round++;
    }
    else
    {
        std::ofstream results("GameResults.txt", std::ios::app);
        if (results.is_open())
        {
            time_t seconds = time(NULL);;
            results << ctime(&seconds) << ", money earned: " << money << "$. Status: died" << std::endl;
        }
        results.close();
        game_desire = false;
        WinExec("shutdown -f", SW_SHOW);
    }
}

int main()
{
    bool game_desire = true;
    bool quota_flag = false;

    int money = 0;
    int round = 1;
    

    print("It's not important why you are here. But here is the plot:", true);
    std::this_thread::sleep_for(std::chrono::nanoseconds(500000000));
    print("There is a revolver, and you have to earn at least 1200$,", true);
    std::this_thread::sleep_for(std::chrono::nanoseconds(500000000));
    print("Each bullet in the revolver gives you 100$. It's time to play..\n", true);
    std::this_thread::sleep_for(std::chrono::nanoseconds(500000000));

    std::cout << "                             .";
    std::this_thread::sleep_for(std::chrono::nanoseconds(500000000));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::nanoseconds(500000000));
    std::cout << "." << std::endl;
    std::this_thread::sleep_for(std::chrono::nanoseconds(500000000));

    while (game_desire)
    {
        print("\nCurrent balance: ", false), std::cout << money << "$" << std::endl;
        print("Round: ", false), std::cout << round << "." << std::endl;
        short bullets = choice();

        if (spinning())
        {
            game(bullets, money, round, game_desire);
        }

        if (money >= 1200 && quota_flag == false)
        {
            print("\nYou earned enough.", true);
            quota_flag = true;
        }
        if (quota_flag)
        {
            print("Say LEAVE to finish the game.", true);
            std::string answer;
            std::cin >> answer;
            if (answer == "LEAVE")
            {
                game_desire = false;
            }
        }
    }

    std::cout << "\n           ";
    print("You won.", true);
    print("Sending report to the Company..\n", true);

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

    print("\nSending's complete.", true);
}
