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
    class Scoresheet
    {
    public:
	Scoresheet(vector<string>);

	// << operator overload to print scoresheet
	friend ostream& operator<<(ostream&, const Scoresheet&);
	// returns unused catagories
	vector<string> unusedCategories() const;

    private:
	vector<pair<int, string>> score;
    };
}

#endif
