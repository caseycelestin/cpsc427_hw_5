#ifndef __RULE_HPP__
#define __RULE_HPP__

#include <string>
#include <memory>

using std::string;
using std::shared_ptr;

namespace cs427_527
{
    class DiceRoll;
    class Scoresheet;

    class PointAmount;
    class RuleCheck;

    class Rule
    {
    public:
	Rule();
	Rule(string, string, shared_ptr<PointAmount>, shared_ptr<RuleCheck>, bool);
	int points(DiceRoll, string, Scoresheet);
	bool applyPoints(DiceRoll, string, Scoresheet);
	string getName();
	string getAbbrev();
	bool isPlayable();
    private:
	string name;
	string abbrev;
	shared_ptr<PointAmount> pointRule;
	shared_ptr<RuleCheck> applyRule;
	bool playable;
    };
}

#endif

