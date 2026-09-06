class Solution {
public:
    bool search(vector<int>& arr, int k) {
        int lo = 0;
        int hi  =arr.size()-1;
        while(lo<=hi)
        {
            int mid = lo+(hi-lo)/2;

            if(arr[mid] == k){
                return true;

            }
            if(arr[lo] == arr[mid] && arr[mid] == arr[hi]){
                lo++;
                hi--;

            }
            else if(arr[lo]<=arr[mid]){
                if(arr[lo] <=k &&  k<arr[mid]){
                    hi = mid-1;
                }
                else{
                    lo = mid+1;
                }
            }
            else {
                if(arr[mid]<k && k<= arr[hi]){
                    lo = mid+1;
                }
                else{
                    hi = mid-1;
                }
            }
        }
        return false;
    }
};