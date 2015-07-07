#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <unordered_map>
#include <set>
#include <math.h>

using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		if (path.size() <= 1) return "/";
		stack<string> path_trace;
		path_trace.push("/");
		string temp;
		for (int i = 1; i < path.size();){
			int end = i;
			while (end<path.size() && path[end] != '/') end++;
			temp = path.substr(i, end - i);
			i = end + 1;
			if (temp == "." || temp == "") continue;
			else if (temp == ".."){
				if (path_trace.top() == "/") continue;
				else path_trace.pop();
			}
			else path_trace.push(temp);
		}
		string output = path_trace.top();
		path_trace.pop();
		while (path_trace.empty() == false){
			temp = path_trace.top();
			path_trace.pop();
			if (temp == "/"){
				output = temp + output;
				return output;
			}
			else{
				output = temp + "/" + output;
			}
		}
		return output;
	}
};
