class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int prefix = 0;
        int minprefix = 0;

        for(int num:nums){
            prefix+=num;
            minprefix = min(minprefix,prefix);
        }
        return 1 - minprefix;
    }
};