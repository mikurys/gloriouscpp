
#pragma once

#include <ostream>

#include <vector>
#include <map>

template <typename T> std::ostream& operator<<(std::ostream &ostr , const std::vector<T> & tab) {
	using namespace std;
	bool first=0; // first was done yet
	for (const auto & obj : tab) {
		if (first) ostr << ", ";
		first=1;
		ostr<<obj;
	}
	return ostr;
}

template <typename TKey, typename TVal> std::ostream& operator<<(std::ostream &ostr , const std::map<TKey,TVal> & tab) {
	using namespace std;
	bool first=0; // first was done yet
	for (const auto & it : tab) {
		if (first) ostr << ", ";
		first=1;
		ostr << (it.first) << ": {" << (it.second) << "}";
	}
	return ostr;
}

