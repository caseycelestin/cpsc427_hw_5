#include "yahtzee.hpp"

#include <vector>
#include <string>
#include <iostream>
#include <utility>

#include "diceroll.hpp"
#include "scoresheet.hpp"
#include "ruletypes.hpp"
#include "rule.hpp"

using std::vector;
using std::string;
using std::ostream;
using std::pair;
using std::make_pair;

namespace cs427_527
{
    YahtzeeGame::YahtzeeGame(vector<Rule> r ) : rules{r} 
    {
    }

    Scoresheet YahtzeeGame::initialSheet() const
    {
	vector<string> unused;
	vector<pair<int, string>> score;
	for(auto it = rules.begin(); it != rules.end(); it++)
	{
	    if((*it).isPlayable())
	    {
		unused.push_back((*it).getAbbrev());
	    }
	    score.push_back(make_pair(-1, (*it).getName()));
	}

	return Scoresheet(score, unused);
    }

    bool YahtzeeGame::isTerminal(const Scoresheet sheet) const
    {
	return true;
    }

    void YahtzeeGame::scoreRoll(DiceRoll roll, string cat, Scoresheet sheet) const
    {
    }


}
