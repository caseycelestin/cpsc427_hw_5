#ifndef __RULE_HPP__
#define __RULE_HPP__

#include <string>
#include <memory>

#include "diceroll.hpp"
#include "scoresheet.hpp"
#include "ruletypes.hpp"

using std::string;
using std::shared_ptr;

namespace cs427_527
{
    class Rule
    {
    public:
	Rule(string, string, shared_ptr<PointAmount>, shared_ptr<RuleCheck>, bool);
	
	// Returns the amount of points rewarded for this rule:
	int points(DiceRoll, string, Scoresheet);

	// Checks to see if points can be applied
	bool applyPoints(DiceRoll, string, Scoresheet);

	// Returns if it is playable or not
	bool isPlayable() const;

	// Return name
	string getName() const;

	// Returns abbrev
	string getAbbrev() const;

    private:
	// Name of category
	string name;

	// Abbreviation of name
	string abbrev;

	// Pointer to appropriate points class
	shared_ptr<PointAmount> pointAmount;

	// Pointer to appropriate checker class
	shared_ptr<RuleCheck> ruleCheck;	

	// Playable or not (hand or bonus)
	bool playable;
    };
}

//#include "rule.cpp"

#endif
