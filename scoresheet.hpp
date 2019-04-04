#ifndef __SCORESHEET_HPP__
#define __SCORESHEET_HPP__

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
    class Scoresheet
    {
    public:
	Scoresheet(vector<pair<int,string>>, vector<string>);

	// returns unused catagories
	vector<string> unusedCategories() const;
	
	// << operator overload to print scoresheet
	friend ostream& operator<<(ostream&, const Scoresheet&);

    private:
	vector<pair<int, string>> score;

	vector<string> unused;
    };

    ostream& operator<<(ostream& stream, const Scoresheet&);

}

#include "scoresheet.cpp"

#endif
