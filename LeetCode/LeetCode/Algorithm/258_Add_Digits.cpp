class Solution {
public:
    int addDigits(int num) {
        if(num<10) return num;
        else{
            int output = 0;
            while(num){
                output += (num%10);
                num /= 10;
            }
            return addDigits(output);
        }
    }
};
