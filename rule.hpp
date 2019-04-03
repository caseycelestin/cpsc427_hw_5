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
	Rule();
	
	// Returns the amount of points rewarded for this rule
	int points(DiceRoll, string, Scoresheet);

	// Checks to see if points can be applied
	bool applyPoints(DiceRoll, string, Scoresheet);

    private:
	// Pointer to appropriate points class
	shared_ptr<PointAmount> pointAmount;

	// Pointer to appropriate checker class
	shared_ptr<RuleCheck> ruleCheck;	
    };
}
#endif
