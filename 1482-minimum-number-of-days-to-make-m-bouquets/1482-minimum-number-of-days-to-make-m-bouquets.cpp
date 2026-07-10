class Solution {
public:
bool possible(vector<int>&bloomDay,int day ,int m , int k ){
    int flowers =0;
    int bouquets = 0;

    for(int bloom : bloomDay){
        if(bloom  <= day){
            flowers++;
            if(flowers == k){
                bouquets++;
                flowers=0;
            }
        }
        else{
            flowers = 0;
        }
       
    }
     return bouquets >=m;
}

    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long ) m*k>bloomDay.size())return -1;

        int left = *min_element(bloomDay.begin(),bloomDay.end());
        int right = *max_element(bloomDay.begin(),bloomDay.end());

        int ans = -1;
        while(left<=right){
            int  mid = left + (right - left)/2;
            if(possible(bloomDay,mid,m,k)){
                ans = mid;
                right = mid -1;
            }
            else{
                left= mid+1;
            }
        }
        return ans;
    }
};