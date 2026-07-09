class Solution {
public:

bool possible(vector<int>&pos,int m,int dist){
    int balls =1;
    int last = pos[0];
    for(int i=1;i<pos.size();i++){
        if(pos[i]-last>=dist){
            balls++;
            last = pos[i];
            if(balls==m) return true;
        }
    }
    return false;
}
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());

        int left =1;
        int right =position.back()-position.front();

        int ans =0;
        while(left<=right){
            int mid = left+(right-left)/2;

    if(possible(position,m,mid)){
        ans = mid;
        left =mid+1;
    }
    else{
        right= mid-1;
    }
        }
        return ans;
    }
    };