
#include "scoresheet.hpp"

#include <vector>
#include <string>
#include <utility>
#include <iostream>

using std::vector;
using std::string;
using std::pair;
using std::ostream;


namespace cs427_527
{
    Scoresheet::Scoresheet(vector<pair<int,string>> s, vector<string> u) 
    {
	score = s;
	unused = u;
    }

    ostream& operator<<(ostream& stream, const Scoresheet& sheet)
    {
	return stream;
    }

    vector<string> Scoresheet::unusedCategories() const
    {
	return unused;
    }

}
