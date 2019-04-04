#include "factory.hpp"

#include "yahtzee.hpp"
#include "rule.hpp"
#include "ruletypes.hpp"

#include <string>
#include <memory>
#include <vector>

using std::string;
using std::make_shared;
using std::vector;

namespace cs427_527
{

    YahtzeeGame BasicYahtzeeFactory::makeGame() const
    {
	
	vector<Rule> ruleList;

	ruleList.push_back(Rule(string("Aces"), string("1"), make_shared<OneSum>(1), make_shared<NoCheck>(), true));
	
	ruleList.push_back(Rule(string("Deuces"), string("2"), make_shared<OneSum>(2), make_shared<NoCheck>(), true));
	
	ruleList.push_back(Rule(string("Treys"), string("3"), make_shared<OneSum>(3), make_shared<NoCheck>(), true));
	
	ruleList.push_back(Rule(string("Fours"), string("4"), make_shared<OneSum>(4), make_shared<NoCheck>(), true));

	ruleList.push_back(Rule(string("Fives"), string("5"), make_shared<OneSum>(5), make_shared<NoCheck>(), true));

	ruleList.push_back(Rule(string("Sixes"), string("6"), make_shared<OneSum>(6), make_shared<NoCheck>(), true));

	ruleList.push_back(Rule(string("Three of a Kind"), string("3K"), make_shared<AllSum>(), make_shared<OfAKind>(3), true));

	ruleList.push_back(Rule(string("Four of a Kind"), string("4K"), make_shared<AllSum>(), make_shared<OfAKind>(4), true));
	
	ruleList.push_back(Rule(string("Full House"), string("FH"), make_shared<Fixed>(25), make_shared<FullHouse>(), true));

	ruleList.push_back(Rule(string("Small Straight"), string("SS"), make_shared<Fixed>(30), make_shared<Straights>(4), true));

	ruleList.push_back(Rule(string("Large Straight"), string("LS"), make_shared<Fixed>(40), make_shared<Straights>(5), true));
	

	

	return YahtzeeGame(ruleList);
    }

    YahtzeeGame MysteryYahtzeeFactory::makeGame() const
    {
	return YahtzeeGame();
    }
}
