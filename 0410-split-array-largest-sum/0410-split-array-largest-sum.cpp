class Solution {
public:
bool possible(vector<int>&nums,int k,int mid){
    int count =1;
    int currentSum =0;

    for(int num:nums){
        if(currentSum +num<=mid){
            currentSum +=num;
        }
        else{
            count++;
            currentSum =num;
        }
    }
    return count<=k;
}
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(),nums.end());
        
        int right =accumulate(nums.begin(),nums.end(),0);
        int ans =right;
        
        while(left<=right){
            int mid =left+(right-left)/2;

            if(possible(nums,k,mid)){
                ans = mid;
                right =mid-1;
            }
            else{
                left = mid+1;
            }
        }  
        return ans;
          }
};