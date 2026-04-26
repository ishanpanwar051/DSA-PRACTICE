#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int>& a,vector<int>& b,vector<int>& res){
    int i=0;
    int j=0;
    int k=0;
    while(i<a.size() && j<b.size()){
        if(a[i]<b[j]){
          res[k] =a[i];
            i++;
            k++;
        }
        else{
            res[k] = b[j];
            k++;
            j++;

        }

    }
    if(i==a.size()){
        while(j<b.size()){
            res[k] =b[j];
            k++;
            j++;

        }
    }
    if(j==b.size()){
        while(i<a.size()){
            res[k] =a[i];
            k++;
            i++;
            
        }
    }

}
void mergesort(vector<int>&v){
      if (v.size() <= 1) return;
    int n=v.size();
    int n1=n/2;
    int n2 = n-n/2;
    vector<int>a(n1),b(n2);
    for(int i=0;i<n1;i++){
        a[i] =v[i];

    }
    for(int i=0;i<n2;i++){
        b[i] =v[i+n1];
    }
    mergesort(a);
    mergesort(b);


    merge(a,b,v);
}


int main(){

    int arr[] ={1,4,5,8};
    int n1 = sizeof(arr)/sizeof(arr[0]);
    vector<int>a(arr,arr+n1);



    int brr[] ={2,3,6,7,10,12};

    int n2 = sizeof(brr)/sizeof(brr[0]);
         vector<int>b(brr,brr+n2);
  vector<int>res(n1+n2);

merge(a,b,res);
for(int i=0;i<res.size();i++){
    cout<<res[i]<<" ";
}
}