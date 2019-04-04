#include "scoresheet.hpp"

#include "rule.hpp"

using std::make_pair;

namespace cs427_527
{
    Scoresheet::Scoresheet()
    {
    }
    
    Scoresheet::Scoresheet(vector<Rule> ruleList)
    {
	vector<pair<int,string>> s;
	vector<string> u;

	for (auto it = ruleList.begin(); it != ruleList.end(); it++)
	{
	    Rule add = *it;

	    if(add.isPlayable())
	    {
		u.push_back(add.getAbbrev());
	    }

	    s.push_back(make_pair(-1, add.getName()));
	}
	score = s;
	unused = u;
    }
    
    vector<string> Scoresheet::unusedCategories()
    {
	return unused;
    }
}
