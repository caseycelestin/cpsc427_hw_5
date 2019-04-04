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
	return roll.total();
    }

    Fixed::Fixed(int v)
    {
	value = v;
    }

    int Fixed::points(DiceRoll roll)
    {
	return value;
    }

    OneSum::OneSum(int n)
    {
	number = n;
    }

    int OneSum::points(DiceRoll roll)
    {
	return number * roll.count(number);
    }

    bool NoCheck::applyPoints(DiceRoll roll)
    {
	return true;
    }

    bool FullHouse::applyPoints(DiceRoll roll)
    {
	bool three = false;
	bool two = false;

	for(int i = 1; i <= roll.NUM_SIDES; i++)
	{
	    if(roll.count(i) == 2)
	    {
		two = true;
	    }
	    if(roll.count(i) == 3)
	    {
		three = true;
	    }
	}

	return two && three;
    }

    Straights::Straights(int s)
    {
	size = s;
    }

    bool Straights::applyPoints(DiceRoll roll)
    {
	int i = 1;
	int ref = 1;
	int count = 0;

	while(count < size)
	{
	    if(ref == (roll.NUM_SIDES - size + 2))
	    {
		return false;
	    }


	    if(roll.count(i) != 1)
	    {
		count++;
		i++;
	    }
	    else
	    {
		count = 0;
		ref++;
		i = ref;
	    }
	}

	return true;
    }

    OfAKind::OfAKind(int n)
    {
	number = n;
    }

    bool OfAKind::applyPoints(DiceRoll roll)
    {
	for(int i; i < roll.NUM_SIDES; i++)
	{
	    if(roll.count(i) == number)
	    {
		return true;
	    }
	}

	return false;
    }
}
