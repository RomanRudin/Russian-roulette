#pragma once

#include <string>

namespace df
{
	void print(std::string line, bool endl);
	void print(std::string line, bool endl, int nanosec);
	bool spinning();
	short choice();
	void game(int bullets, int& money, int& round, bool& game_desire);
}
