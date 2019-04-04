#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include "yahtzee.hpp"
#include "ruletypes.hpp"
#include "rule.hpp"

namespace cs427_527
{
    // Interface for yahtzee factory
    // makeGame needs to be overridden
    class YahtzeeFactory
    {
    public:
	virtual ~YahtzeeFactory() = default;
	virtual YahtzeeGame makeGame() const = 0;
    
    };

    // Creates basic yahtzee game
    class BasicYahtzeeFactory : public YahtzeeFactory
    {
    public:
	virtual YahtzeeGame makeGame() const;	
    };
    
    // Creates basic yahtzee game
    class MysteryYahtzeeFactory : public YahtzeeFactory
    {
    public:
	virtual YahtzeeGame makeGame() const;	
    };

}

#endif
