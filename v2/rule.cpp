#include "rule.hpp"

#include "diceroll.hpp"
#include "scoresheet.hpp"
#include "rules.hpp"

namespace cs427_527
{
    Rule::Rule()
    {
    }

    Rule::Rule(string n, string a, shared_ptr<PointAmount> p, shared_ptr<RuleCheck> r, bool play)
    {
	name = n;
	abbrev = a;
	pointRule = p;
	applyRule = r;
	playable = play;
    }

    int Rule::points(DiceRoll roll, string cat, Scoresheet sheet)
    {
	return pointRule->points(roll, cat, sheet);
    }

    bool Rule::applyPoints(DiceRoll roll, string cat, Scoresheet sheet)
    {
	return applyRule->applyPoints(roll, cat, sheet);
    }

    string Rule::getName()
    {
	return name;
    }

    string Rule::getAbbrev()
    {
	return abbrev;
    }

    bool Rule::isPlayable()
    {
	return playable;
    }
}
