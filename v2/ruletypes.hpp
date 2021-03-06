#ifndef __RULETYPES_HPP__
#define __RULETYPES_HPP__

#include <string>
#include <memory>

using std::string;
using std::shared_ptr;

namespace cs427_527
{
    class Scoresheet;
    class DiceRoll;

    class PointAmount
    {
    public:
	virtual ~PointAmount();
	virtual int points(DiceRoll, Scoresheet) = 0;
    };

    class RuleCheck
    {
    public:
	virtual ~RuleCheck();
	virtual bool applyPoints(DiceRoll) = 0;
    };
    
    class AllSum : public PointAmount
    {
    public:
	virtual int points(DiceRoll, Scoresheet) override;
    };

    class Fixed : public PointAmount
    {
    public:
	Fixed(int v);
	virtual int points(DiceRoll, Scoresheet) override;
    private:
	int value;
    };

    class OneSum : public PointAmount
    {
    public:
	OneSum(int n);
	virtual int points(DiceRoll, Scoresheet) override;
    private:
	int number;
    };

    class Bonus : public PointAmount
    {
    public:
	Bonus(int t, int b);
	virtual int points(DiceRoll, Scoresheet) override;
    private:
	int threshold;
	int bonus;

    };		

    class Total : public PointAmount
    {
    public:
	virtual int points(DiceRoll, Scoresheet) override;
    };

    class NoCheck : public RuleCheck
    {
    public: 
	virtual bool applyPoints(DiceRoll) override;
    };

    class FullHouse : public RuleCheck
    {
    public:
	virtual bool applyPoints(DiceRoll) override;
    };

    class Straights : public RuleCheck
    {
    public:
	Straights(int s);
	virtual bool applyPoints(DiceRoll) override;
    private:
	int size;
    };

    class OfAKind : public RuleCheck
    {
    public:
	OfAKind(int n);
	virtual bool applyPoints(DiceRoll) override;
    private:
	int number;
    };
}
#endif
