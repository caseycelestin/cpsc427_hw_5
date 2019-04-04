#include "yahtzee.hpp"

#include "diceroll.hpp"
#include "rule.hpp"
#include "scoresheet.hpp"

#include <vector>
#include <utility>
#include <string>

using std::vector;
using std::pair;
using std::string;

#include <iostream>

namespace cs427_527
{
    
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
	return Scoresheet(ruleList);
    }
    
    bool YahtzeeGame::isTerminal(Scoresheet sheet)
    {
	return (sheet.unusedCategories()).empty();
    }

    void YahtzeeGame::scoreRoll(DiceRoll, string, Scoresheet)
    {
	
    }

}

