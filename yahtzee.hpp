#ifndef __YAHTZEE_HPP__
#define __YAHTZEE_HPP__

#include <vector>
#include <string>
#include <iostream>

#include "diceroll.hpp"
#include "scoresheet.hpp"
#include "ruletypes.hpp"
#include "rule.hpp"

using std::vector;
using std::string;
using std::ostream;

namespace cs427_527
{

    class YahtzeeGame
    {
    public:
	// Basic constructor for testing
	YahtzeeGame();
	// Constructs a yahtzee game from a set of rules
	YahtzeeGame(vector<Rule>);

	// Creates a scoresheet for this yahtzee game
	Scoresheet initialSheet() const;

	// Checks scoresheeet to see if the game is over
	bool isTerminal(const Scoresheet) const;

	// Scores a turn by the player
	void scoreRoll(DiceRoll, string, Scoresheet) const;
    private:
	// Saved list of rules
	vector<Rule> rules;
    };
}
#endif
