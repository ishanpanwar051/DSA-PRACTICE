class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo = 0,high =nums.size()-1;
       
        while(lo<high){
            int mid = lo+(high-lo)/2;

            if(nums[mid]<nums[mid+1])lo =mid+1;
            else high =mid;

            

        }
        return lo;
        
    }
};