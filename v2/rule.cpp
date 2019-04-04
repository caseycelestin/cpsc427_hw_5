#include "rule.hpp"

#include "diceroll.hpp"
#include "scoresheet.hpp"
#include "ruletypes.hpp"

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

    int Rule::points(DiceRoll roll)
    {
	return pointRule->points(roll);
    }

    bool Rule::applyPoints(DiceRoll roll)
    {
	return applyRule->applyPoints(roll);
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
