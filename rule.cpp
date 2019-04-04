#include "rule.hpp"

#include "diceroll.hpp"
#include "scoresheet.hpp"
#include "ruletypes.hpp"

#include <string>
#include <memory>

using std::string;
using std::shared_ptr;

namespace cs427_527
{
    Rule::Rule(string n, string a, shared_ptr<PointAmount> p, shared_ptr<RuleCheck> c, bool b) : name{n}, abbrev{a}, pointAmount{p}, ruleCheck{c}, playable{b}
    {
    }

    int Rule::points(DiceRoll roll, string cat, Scoresheet sheet)
    {
	return pointAmount->points(roll, cat, sheet);
    }

    bool Rule::applyPoints(DiceRoll roll, string cat, Scoresheet sheet)
    {
	return ruleCheck->applyPoints(roll, cat, sheet);
    }


    bool Rule::isPlayable() const
    {
	return playable;
    }

    string Rule::getName() const
    {
	return name;
    }

    string Rule::getAbbrev() const
    {
	return abbrev;
    }
}
