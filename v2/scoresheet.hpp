#ifndef __SCORESHEET_HPP__
#define __SCORESHEET_HPP__

#include <vector>
#include <string>
#include <utility>

using std::vector;
using std::string;
using std::pair;

namespace cs427_527
{
    class Rule;

    class Scoresheet
    {
    public:
	Scoresheet();

	Scoresheet(vector<Rule>);

	vector<string> unusedCategories();

    private:
	vector<pair<int, string>> score;

	vector<string> unused;
    };

}

#endif
