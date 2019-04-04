#include "ruletypes.hpp"

#include "diceroll.hpp"
#include "scoresheet.hpp"

namespace cs427_527
{
    PointAmount::~PointAmount()
    {
    }

    RuleCheck::~RuleCheck()
    {
    }
    
    int AllSum::points(DiceRoll roll)
    {
	return 10;
    }

    bool NoCheck::applyPoints(DiceRoll roll)
    {
	return true;
    }
}
