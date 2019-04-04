
#include "yahtzee.hpp"
#include "factory.hpp"
#include "diceroll.hpp"

#include <string>
#include <memory>
#include <iostream>
#include <iterator>
#include <algorithm>

using std::string;
using std::make_shared;
using std::shared_ptr;
using std::cout;
using std::endl;
using std::ostream_iterator;
using std::copy;
using std::cin;

using cs427_527::Rule;
using cs427_527::YahtzeeGame;
using cs427_527::BasicYahtzeeFactory;
using cs427_527::YahtzeeFactory;
using cs427_527::Scoresheet;
using cs427_527::DiceRoll;

int main(int argc, char **argv)
{
    shared_ptr<YahtzeeFactory> factory;
	    
    factory = make_shared<BasicYahtzeeFactory>();

    YahtzeeGame game = factory->makeGame();

    Scoresheet sheet = game.initialSheet();

    DiceRoll roll;


    cout << sheet << roll << endl; 
    vector<string> options = sheet.unusedCategories();

    copy(options.begin(), options.end(), ostream_iterator<string>(cout, " "));
    cout << endl;

    string cat;

    getline(cin,cat);

    game.scoreRoll(roll, cat, sheet);

    cout << sheet;

    
}
