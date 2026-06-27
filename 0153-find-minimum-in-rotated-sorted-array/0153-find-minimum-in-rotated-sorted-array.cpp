class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int lo =0;
        int high = n-1;
int min_ele =INT_MAX;
        while(lo<=high){
int mid = lo+(high-lo)/2;

if(nums[lo]<=nums[mid]){
    min_ele = min(min_ele,nums[lo]);
    lo=mid+1;

}
else{
    min_ele = min(min_ele,nums[mid]);
    high = mid - 1;
}
    }
    return min_ele;
    }
};