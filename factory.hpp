#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

namespace cs427_527
{
    // Interface for yahtzee factory
    // makeGame needs to be overridden
    class YahtzeeFactory
    {
    public:
	virtual ~YahtzeeFactory();
	virtual YahtzeeGame makeGame() = 0;
    
    };

    // Creates basic yahtzee game
    class BasicYahtzeeFactory : public YahtzeeFactory
    {
    public:
	virtual YahtzeeGame makeGame();	
    };
    
    // Creates basic yahtzee game
    class MysteryYahtzeeFactory : public YahtzeeFactory
    {
    public:
	virtual YahtzeeGame makeGame();	
    };

}

#endif
