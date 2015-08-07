#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        map<char, int> temp;
        for(int i = 0;i<s.size();i++){
            if(temp.find(s[i])==temp.end()) temp[s[i]] = 1;
            else temp[s[i]]++;
        }
        for(int i = 0;i<t.size();i++){
            if(temp.find(t[i])==temp.end()) return false;
            else {
                if(temp[t[i]]==1) temp.erase(t[i]);
                else temp[t[i]]--;
            }
        }
        return temp.empty();
    }
};
