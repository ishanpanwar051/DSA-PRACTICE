class Solution {
public:
bool possible(vector<int>&candies,long long k,int x){
    long long children =0;
    for(int pile:candies){
        children +=pile/x;
    }
    return children >=k;
}

    int maximumCandies(vector<int>& candies, long long k) {
        

        int left =1;
        int right = *max_element(candies.begin(),candies.end());

        int ans=0;

        while(left<=right){
            int mid =left+(right-left)/2;

            if(possible(candies,k,mid)){
                ans = mid;
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }
        }
        return ans;
    }

    
};