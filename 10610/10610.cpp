//24.9.9(월) 30
#include<iostream>
#include<string>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    string str; cin>>str;
    
    int sum=0;
    int isZero=0;
    for(char s:str){
        sum+=(s-'0');
        if(s == '0') isZero=1;
    }

    if(!isZero || sum%3){
        cout<<-1<<endl;
    }else{
        sort(str.begin(),str.end(),greater<int>());
        for(char s:str){
            cout<<s;
        }
    }
}