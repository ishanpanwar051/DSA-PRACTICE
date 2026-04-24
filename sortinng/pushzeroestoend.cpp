#include<iostream>
#include<vector>
using namespace std;

int main(){
    int arr [] = {5,0,1,2,0,0,4,0,3};
    int n = sizeof(arr)/ sizeof(arr[0]);
    for(int i =0;i<n;i++){
        for(int j =i+1;j<n;j++){
            if(arr[i]==0 &&arr[j]!=0){
                swap(arr[i],arr[j]);
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
        }