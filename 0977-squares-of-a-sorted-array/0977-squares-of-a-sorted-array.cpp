class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    
    int left =0;
    int right = nums.size()-1;
    int idx =nums.size()-1;
vector<int>ans(n);
    while(left<=right){
       if(abs(nums[left])>abs(nums[right])){
        ans[idx] = nums[left]*nums[left];
        left++;
       }
       else{
        ans[idx] = nums[right]*nums[right];
        right--;
       }
       idx--;
    }
   
    return ans;
    
        }
};