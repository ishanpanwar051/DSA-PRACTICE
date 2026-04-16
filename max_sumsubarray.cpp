#include<iostream>
#include<climits>
using namespace std;

int main(){
    int arr[] ={7,1,2,5,8,4,9,3,6};
    int n =sizeof(arr)/sizeof(arr[0]);

    int k =3;
    int maxsum =INT_MIN;
    int prevsum =0;
int maxidx =0;
    //1.)Brute Force 0(n*k)

    // int max_sum=INT_MIN;
    // for(int  i=0;i<=n-k;i++){
    //     int sum=0;
    //     for(int j=i;j<i+k;j++){
    //      sum+=arr[j];
    //     }
    //     max_sum =max(max_sum,sum);

    // }
    // cout<<max_sum;

//2.)Sliding Window 0(n)

for(int i=0;i<k;i++){
    prevsum+=arr[i];
}

int i=1;
int j=k;
while(j<n){
    int currsum = prevsum+arr[j]-arr[i-1];
    if(maxsum<currsum){
        maxsum =currsum;
maxidx =i;


    }
    prevsum = currsum;
    i++;
    j++;

}

cout<<maxsum<<endl;
cout<<maxidx;

}