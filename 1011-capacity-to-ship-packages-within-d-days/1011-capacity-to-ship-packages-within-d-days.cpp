class Solution {
public:

int daysNeeded(vector<int>& weights,int cap){
    int days=1;
    int load =0;
    

for(int w:weights){
    if(load+w>cap){
        days++;
        load = w;

    }
    else {
        load+=w;
    }
}

return days;


}
    int shipWithinDays(vector<int>& weights, int days) {
        int low =*max_element(weights.begin(),weights.end());

        int high = accumulate(weights.begin(),weights.end(),0);

        while(low<high){
            int mid = low+(high-low)/2;

            if(daysNeeded(weights,mid)>days)
             low = mid+1;

             else
             high =mid;
        }
        return low;

    }
};