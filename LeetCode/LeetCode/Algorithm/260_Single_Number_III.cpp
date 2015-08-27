class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> output;
        if(nums.size()<2) return output;
        int aORXb = 0;
        for(auto temp:nums) aORXb ^= temp;
        int last_diff = (aORXb & (aORXb - 1)) ^ aORXb;
        int A = 0, B = 0;
        for(auto temp:nums){
            if(temp & last_diff) A ^= temp;
            else B ^= temp;
        }
        output = {A, B};
        return output;
    }
};
