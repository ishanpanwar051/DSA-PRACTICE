class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int total = 0;

        for(int x:nums){
            total+=x;
            }
            int left =0;
            vector<int>ans;

            for(int i=0;i<nums.size();i++){
                int right= total-left-nums[i];

                ans.push_back(abs(left-right));

                left+=nums[i];
            }
            return ans;
    }
};