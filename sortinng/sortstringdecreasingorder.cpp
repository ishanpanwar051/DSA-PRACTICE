#include<iostream>
#include<string>

using namespace std;

int main(){
    string s ="AZYBJFJNKv";
    int n= s.length();
    string str="";
    for(int i=0;i<s.length();i++){
        if(s[i]>='X'){
            str.push_back(s[i]);
        }
    }
    
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;i++){
            if(str[j]>str[j+1]){
                swap(str[j],str[j+1]);

            }
        }
    }
    cout<<str;
}