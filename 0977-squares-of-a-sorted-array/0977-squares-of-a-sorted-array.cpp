class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
     int n = nums.size();
        int left=0;
        int right=nums.size()-1;
int index = nums.size()-1;
vector<int>ans(n);

        while(left<=right){
            if(abs(nums[left])>abs(nums[right])){
                ans[index] = nums[left]*nums[left];
                left++;
            }
            else{
                ans[index] = nums[right]*nums[right];
                right--;

            }
            index--;

        }
        return ans;
    }
};