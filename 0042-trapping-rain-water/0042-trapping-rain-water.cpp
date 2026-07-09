class Solution {
public:
    int trap(vector<int>& arr) {
        int left =0;
        int right =arr.size()-1;
        int water=0;
        int leftmax=0;
        int rightmax=0;

        while(left<right){
            if(arr[left]<=arr[right]){
            if(leftmax<arr[left])leftmax=arr[left];
            else water+=leftmax-arr[left];
                
                left++;
            }
            else if(arr[left]>arr[right]){
            if(rightmax<arr[right]) rightmax=arr[right];
            else water+=rightmax-arr[right];
                right--;
            }

            
            
        }
        return water;
    }
};