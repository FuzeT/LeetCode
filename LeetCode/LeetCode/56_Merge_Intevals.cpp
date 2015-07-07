#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <math.h>
using namespace std;



struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		if (intervals.size() <= 1) return intervals;
		multimap<int, Interval> ordered_intervals;
		for (int pointer = 0; pointer < intervals.size(); pointer++){
			ordered_intervals.insert(make_pair(intervals[pointer].start, intervals[pointer]));
		}
		vector<Interval> output;
		multimap<int, Interval>::iterator i = ordered_intervals.begin();
		while (i != ordered_intervals.end()){
			multimap<int, Interval>::iterator j = i;
			j++;
			int end_now = i->second.end;
			while (j != ordered_intervals.end() && j->first <= end_now){ end_now = max(j->second.end, end_now); j++; }
			output.push_back(Interval(i->first, end_now));
			i = j;
		}
		return output;
	}
};