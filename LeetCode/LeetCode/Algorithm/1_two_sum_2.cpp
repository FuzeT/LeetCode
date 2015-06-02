#include <vector>
#include <map>
using namespace std; 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> temp;
        vector<int> output;
        for(int i=0;i<nums.size();i++){
            if(temp.find(nums[i])==temp.end()){
                temp[target-nums[i]] = i;
            }
            else{
                output.push_back(temp[nums[i]]+1);
                output.push_back(i+1);
                return output;
            }
        }
        return output;
    }
};