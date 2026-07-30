#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<int> Split(string s){
    vector<int> ret;
    
    string cur = "";
    int idx=0;
    while(idx<s.size()){
        while(s[idx]!=' '){
            cur+=s[idx];
            idx++;
        }
        // ret.push_back(stoi(cur));
        idx++;
        // cur 초기화
        cur = "";
    }
    
    return ret;
    
}


int main(){
    string input = "-1 -2 -3 -4";
    Split(input);
}