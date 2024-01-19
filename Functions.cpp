#include "Functions.h"

#include <windows.h>
#include <random>
#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include <ctime>

namespace df
{
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
            if (amount <= 0 || amount == 69)
            {
                print("\nFunny enough.", true);
            }
            else if (amount >= 6)
            {
                print("\nARE YOU SURE?", true, 120000000);
                std::string answer;
                std::cin >> answer;
                if (answer == "YES")
                {
                    return 6;
                }
            }
            else
            {
                return amount;
            }
        }
    }

    void game(int bullets, int& money, int& round, bool& game_desire)
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
}