class Solution {
public:

bool possible(vector<int>&nums,int divisior,int threshold){
    int sum =0;
    for(int x:nums){
        sum+=(x+divisior-1)/divisior;

    }
    return sum<=threshold;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left =1;
        int right=*max_element(nums.begin(),nums.end());
        int ans=right;

        while(left<=right){
        int mid = left+(right-left)/2;

        if(possible(nums,mid,threshold)){
            ans =mid;
            right = mid-1;
        }
        else{
            left  = mid+1;
        }
        }
        return ans;
    }
};