#ifndef __RULES_HPP__
#define __RULES_HPP__

#include "diceroll.hpp"

#include <string>
#include <memory>

using std::string;
using std::shared_ptr;

namespace cs427_527
{
    class Scoresheet;

    class PointAmount
    {
    public:
	virtual ~PointAmount();
	virtual int points(DiceRoll, string, Scoresheet) = 0;
    };

    class RuleCheck
    {
    public:
	virtual ~RuleCheck();
	virtual bool applyPoints(DiceRoll, string, Scoresheet) = 0;
    };

    class Rule
    {
    public:
	Rule(string, string, shared_ptr<PointAmount>, shared_ptr<RuleCheck>, bool);
	int points(DiceRoll, string, Scoresheet);
	bool applyPoints(DiceRoll, string, Scoresheet);
    private:
	string name;
	string abbrev;
	shared_ptr<PointAmount> pointRule;
	shared_ptr<RuleCheck> applyRule;
	bool playable;
    };

    class AllSum : public PointAmount
    {
    public:
	virtual int points(DiceRoll, string, Scoresheet) override;
    };

    class NoCheck : public RuleCheck
    {
    public: 
	virtual bool applyPoints(DiceRoll, string, Scoresheet) override;
    };
}
#endif
