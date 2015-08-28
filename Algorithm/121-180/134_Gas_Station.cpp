#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <set>
#include <math.h>
#include <unordered_set>

using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		if (gas.size() == 0) return -1;
		if (gas.size() == 1) return gas[0] >= cost[0] ? 0 : -1;
		int index = 0;
		int phase = gas.size();
		while (index < gas.size() && gas[index] < cost[index]) index++;
		if (index == gas.size()) return -1;
		long long contain = gas[index] - cost[index];
		int start = getNext(index, phase);
		while (start != index){
			if (contain + gas[start] - cost[start] < 0){
				if (index >= getNext(start, phase)) return -1;
				else {
					index = getNext(start, phase);
					while (index<phase && gas[index] < cost[index]) index++;
					if (index == phase) return -1;
					start = getNext(index, phase);
					contain = gas[index] - cost[index];
				}
			}
			else{
				contain = contain + gas[start] - cost[start];
				start = getNext(start, phase);
			}
		}
		return index;
	}

	int getNext(int start, int phase){
		if (start + 1 == phase) return 0;
		else return start + 1;
	}
	int getPre(int start, int phase){
		if (start == 0) return phase - 1;
		else return start - 1;
	}
};