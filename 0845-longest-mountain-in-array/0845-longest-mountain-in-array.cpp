class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n =arr.size();
        int ans =0;
        int i =1;

        while(i<n){
            int up =0,down =0;

            while(i<n && arr[i]>arr[i-1]){
                up++;
                i++;
            }
            while(i<n && up>0 && arr[i]<arr[i-1]){
                down++;
                i++;
            }
            if(up>0 && down>0) ans = max(ans ,up+down+1);
if(up == 0 && down == 0)
    i++;
            while(i<n && arr[i] == arr[i-1])i++;
        }
        return ans;
    }
};