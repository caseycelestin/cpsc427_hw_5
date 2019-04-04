#ifndef __YAHZTEE_HPP__
#define __YAHTZEE_HPP__

#include "diceroll.hpp"
#include "rules.hpp"

#include <vector>
#include <utility>
#include <string>

using std::vector;
using std::pair;
using std::string;
namespace cs427_527
{
    class Scoresheet
    {
    public:
	Scoresheet();
    };
   /* 
    class Scoresheet
    {
    public:
	Scoresheet(vector<pair<int, string>>, vector<string>);

	vector<strings> unusedCategories();
    private:
	vector<pair<int, string>> score;

	vector<string> unused;
    }*/

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
