#include "factory.hpp"

#include "yahtzee.hpp"
#include "rule.hpp"
#include "rules.hpp"

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

	Rule test(string("long"), string("short"), make_shared<AllSum>(), make_shared<NoCheck>(), true);
	
	ruleList.push_back(test);

	return YahtzeeGame(ruleList);
    }
}
