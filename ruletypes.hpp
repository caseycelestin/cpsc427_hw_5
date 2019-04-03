#ifndef __RULETYPES_HPP__
#define __RULETYPES_HPP__

#include <string>

#include "diceroll.hpp"
#include "scoresheet.hpp"

using std::string;


namespace cs427_527
{
    // Classes that make up different rules	

    class PointAmount
    {
    public:
	// PointAmount Destructor
	virtual ~PointAmount();

	// Function that determines point amount fo given rule
	// to be overriden
	virtual int points(DiceRoll, string, Scoresheet) = 0;
    };

    class RuleCheck
    {
    public:
	// RuleCheck destructor
	virtual ~RuleCheck();

	// Funtion that determines if points are applied
	// To be overriden
	virtual bool applyPoints(DiceRoll, string, Scoresheet) = 0;
	
    };

    //// Classes to implement basic yahtzee
    
    /// Different Point Amounts
    
    // Sums all of the dice
    class AllSum : public PointAmount
    {
    public:
	// Returns sum of all dice
	virtual int points(DiceRoll, string, Scoresheet) override;
    };

    // Fized value
    class Fixed : public PointAmount
    {
    public:
	Fixed(int v);

	// Returns fixed value
	virtual int points(DiceRoll, string, Scoresheet) override;
	  
    private:
	int value;
    };

    // Sum of one type of number
    class OneSum : public PointAmount
    {
    public:
	// Returns sum of all dice of one number
	virtual int points(DiceRoll, string, Scoresheet) override;
    };

    /// Diffent rule checkers

    // No need to check for rule
    class NoCheck : public RuleCheck
    {
    public:
	// Returns true
	virtual bool applyPoints(DiceRoll, string, Scoresheet) override;	
    };

    // Check for upper bonus
    class UpperBonus : public RuleCheck
    {
    public:
	// initializes UpperBonus with unique threshold amount
	UpperBonus(int t);
	// Returns true when upper section upper section meets thereshol amount
	virtual bool applyPoints(DiceRoll, string, Scoresheet) override;	
    private:
	int threshold;
    };

    // Check for full house
    class FullHouse : public RuleCheck
    {
    public:
	// Returns true when there is a three of a kind and two of a kind
	virtual bool applyPoints(DiceRoll, string, Scoresheet) override;		
    };

    // Check for straights
    class Straight : public RuleCheck
    {
    public:
	// Initializes straight with unique length
	Straight(int l);

	// Returns true if sequential dice of length L is present
	virtual bool applyPoints(DiceRoll, string, Scoresheet) override;	

    private:
	int length;
    };

    // Check for n of a kind
    class OfAKind : public RuleCheck
    {
    public:
	// initializes OfAKind with unique n
	OfAKind(int number);

	// Returns true if n of a kind exist
	virtual bool applyPoints(DiceRoll, string, Scoresheet) override;	

    private:
	int n;
    };
}

#endif
