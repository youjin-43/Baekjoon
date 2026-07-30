#include<iostream>
#include<string>
using namespace std;

string str = "aaaaaaaaaaaaa";
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t; cin>>t;
    if(t==1){
        long long a,b,s; cin>>a>>b;
        s=a+b;

        int idx=12;
        while(s){
            str[idx--]='a'+s%26;
            s/=26;
        }

        cout<<str<<'\n';

    }else{
        cin>>str;
        long long ret=str[12]-'a';
        long long cur =26;
        for(int i=11;i>=0;i--){
            ret+=cur*(str[i]-'a');
            cur*=26;
        }

        cout<<ret<<'\n';
    }
}