class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        multimap<int,int> temp;
        vector<int> output;
        int index = 0;
        while(index!=nums.size()){temp.insert(pair<int,int>(nums[index], index)); index++;}
        auto i = temp.begin();
        auto j = --temp.end();
        while(i!=j){
            if((i->first+j->first)>target){
                j--;
            }
            else if((i->first+j->first)<target){
                i++;
            }
            else{
                if(i->second<j->second){
                    output.push_back(i->second+1);
                    output.push_back(j->second+1);
                    return output;
                }else{
                    output.push_back(j->second+1);
                    output.push_back(i->second+1);
                    return output;
                }
            }
        }
    }
};