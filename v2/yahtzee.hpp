#ifndef __YAHZTEE_HPP__
#define __YAHTZEE_HPP__

#include <vector>
#include <utility>
#include <string>

#include "rule.hpp"

using std::vector;
using std::pair;
using std::string;

namespace cs427_527
{
    class Rule;
    class DiceRoll;
    class Scoresheet;

    class YahtzeeGame
    {
    public:
	YahtzeeGame();

	// Initilizes yahtzee with list of rules
	YahtzeeGame(vector<Rule>);

	// Creates scoresheet
	// first param is score and full name, second param is unused list
	Scoresheet initialSheet();

	// Cecks for end of game
	bool isTerminal(Scoresheet);

	// Scores players turn
	void scoreRoll(DiceRoll, string, Scoresheet);

    private:
	// List of rules
	vector<Rule> ruleList;
    };
}

#endif
