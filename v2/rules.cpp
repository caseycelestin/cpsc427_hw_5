#include "rules.hpp"
#include "yahtzee.hpp"
namespace cs427_527
{
    PointAmount::~PointAmount()
    {
    }

    RuleCheck::~RuleCheck()
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

    int AllSum::points(DiceRoll roll, string cat, Scoresheet sheet)
    {
	return 10;
    }

    bool NoCheck::applyPoints(DiceRoll roll, string cat, Scoresheet sheet)
    {
	return true;
    }
}
