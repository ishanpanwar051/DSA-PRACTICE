#include<iostream>
#include<vector>
#include<string>
using namespace std;

string removecharacter(string s){
    string res="";
    for(char a :s){
        if(a!='#')res.push_back(a);
else{
if(!res.empty())
res.pop_back();
    }
   


    }
     return res;
}

    bool backspaceCompare(string s, string t) {
   return removecharacter(s) ==removecharacter(t);
    }


    int main(){
string s ="ab#c";
string t = "ad#c";
if(backspaceCompare)==true;


    }