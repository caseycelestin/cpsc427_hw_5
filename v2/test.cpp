
#include "yahtzee.hpp"
#include "factory.hpp"
#include "diceroll.hpp"

#include <string>
#include <memory>
#include <iostream>

using std::string;
using std::make_shared;
using std::shared_ptr;
using std::cout;
using std::endl;

using cs427_527::Rule;
using cs427_527::YahtzeeGame;
using cs427_527::BasicYahtzeeFactory;
using cs427_527::YahtzeeFactory;
using cs427_527::Scoresheet;

int main(int argc, char **argv)
{
    shared_ptr<YahtzeeFactory> factory;
	    
    factory = make_shared<BasicYahtzeeFactory>();

    YahtzeeGame game = factory->makeGame();

    Scoresheet sheet = game.initialSheet();

    cout << sheet; 
    
}
