#include "ruletypes.hpp"

#include "diceroll.hpp"
#include "scoresheet.hpp"

#include <string>

using std::string;

namespace cs427_527
{
    PointAmount::~PointAmount()
    {
    }

    RuleCheck::~RuleCheck()
    {
    }

    int OneSum::points(DiceRoll roll, string cat, Scoresheet sheet)
    {
	return 0;
    }


    bool NoCheck::applyPoints(DiceRoll roll, string cat, Scoresheet sheet)
    {
	return true;
    }

}
