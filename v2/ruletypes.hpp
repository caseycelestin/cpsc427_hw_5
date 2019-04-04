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
	virtual int points(DiceRoll) = 0;
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
	virtual int points(DiceRoll) override;
    };

    class NoCheck : public RuleCheck
    {
    public: 
	virtual bool applyPoints(DiceRoll) override;
    };
}
#endif
