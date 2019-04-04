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

namespace cs427_527
{
    
    YahtzeeGame::YahtzeeGame()
    {	
    }
	
    YahtzeeGame::YahtzeeGame(vector<Rule> r)
    {
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

    void YahtzeeGame::scoreRoll(DiceRoll roll, string cat, Scoresheet sheet)
    {
	vector<Rule> scoreable;

	for(auto it = ruleList.begin(); it != ruleList.end(); it++)
	{
	    Rule test = *it;

	    if(!(test.isPlayable()))
	    {
		score(test, roll, sheet);
	    }
	    else 
	    {
		if(test.getAbbrev() == cat)
		{
		    score(test, roll, sheet);
		}
	    }
	}
    }

    void YahtzeeGame::score(Rule rule, DiceRoll roll, Scoresheet sheet)
    {
	int value = 0;

	if(rule.applyPoints(roll))
	{
	    value = rule.points(roll);
	}
	
	sheet.update(value, rule.getName(), rule.getAbbrev());
    }

}

