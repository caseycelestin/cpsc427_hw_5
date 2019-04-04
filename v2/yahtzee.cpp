#include "yahtzee.hpp"

#include <vector>
#include <utility>
#include <string>

using std::vector;
using std::pair;
using std::string;

#include <iostream>

namespace cs427_527
{
    Scoresheet::Scoresheet()
    {
    }
    /*
    Scoresheet::Scoresheet(vector<pair<int, string>> s, vector<string> u)
    {
	score = s;
	unused = u;
    }
    
    vector<string> Scoresheet::unusedCategories()
    {
	return unused;
    }
    */
    YahtzeeGame::YahtzeeGame()
    {
	
    }
	
    YahtzeeGame::YahtzeeGame(vector<Rule> r)
    {
	std::cout << "woop" << std::endl;
	ruleList = r;
    }

    Scoresheet YahtzeeGame::initialSheet()
    {
	return Scoresheet();
    }
    
    bool YahtzeeGame::isTerminal(Scoresheet)
    {
	return false;
    }

    void YahtzeeGame::scoreRoll(DiceRoll, string, Scoresheet)
    {
    }

}

