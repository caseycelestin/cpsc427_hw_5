#include "scoresheet.hpp"

#include "rule.hpp"

#include <iomanip>

using std::make_pair;
using std::setw;
using std::endl;

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
		s.push_back(make_pair(-1, add.getName()));
	    }
	    else
	    {
		s.push_back(make_pair(0, add.getName()));
	    }
	}
	score = s;
	unused = u;
    }
    
    vector<string> Scoresheet::unusedCategories()
    {
	return unused;
    }

    void Scoresheet::update(int value, string name, string abbrev)
    {

    }

    void Scoresheet::used(string abbrev)
    {
    }

    void Scoresheet::output(ostream& os) const
    {
	for(auto it = score.begin(); it < score.end(); it++)
	{
	    pair<int, string> line = *it;

	    os << setw(5);

	    if(line.first != -1)
	    {
		os << line.first;
	    }
	    else
	    {
		os << "";
	    }

	    os << " " << line.second << endl;
	}
    }

    ostream& operator<<(ostream& os, const Scoresheet& sheet)
    {
	sheet.output(os);

	return os;
    }
}
