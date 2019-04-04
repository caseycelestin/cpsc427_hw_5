#include "factory.hpp"

#include "yahtzee.hpp"
#include "ruletypes.hpp"
#include "rule.hpp"

#include <vector>
#include <memory>
#include <string>

using std::vector;
using std::make_shared;
using std::string;

namespace cs427_527
{
    YahtzeeGame BasicYahtzeeFactory::makeGame() const
    {
	vector<Rule> ruleList;

	ruleList.push_back(Rule(string("Aces"), string("1"), make_shared<OneSum>(), make_shared<NoCheck>(), true));

	return YahtzeeGame(ruleList);
    }

    YahtzeeGame MysteryYahtzeeFactory::makeGame() const
    {
	return YahtzeeGame();
    }
}
