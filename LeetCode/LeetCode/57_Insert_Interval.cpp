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
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> output;
		if (intervals.size() == 0) return vector < Interval > {newInterval};
		multimap<int, Interval> ordered_intervals;
		for (int pointer = 0; pointer < intervals.size(); pointer++){
			ordered_intervals.insert(make_pair(intervals[pointer].start, intervals[pointer]));
		}
		multimap<int, Interval>::iterator i = ordered_intervals.begin();
		while (1){
			if (i == ordered_intervals.end()){ output.push_back(newInterval); return output; }
			if (i->second.end < newInterval.start){ output.push_back(i->second); i++; }
			else{
				if (i->second.start > newInterval.end){ output.push_back(newInterval); break; }
				multimap<int, Interval>::iterator j = i;
				j++;
				int end_now = max(i->second.end, newInterval.end);
				int start_now = min(i->second.start, newInterval.start);
				while (j != ordered_intervals.end() && j->first <= end_now){ end_now = max(j->second.end, end_now); j++; }
				output.push_back(Interval(start_now, end_now));
				i = j;
				break;
			}
		}
		while (i != ordered_intervals.end()){ output.push_back(i->second); i++; }
		return output;
	}
};