#include<iostream>
#include<string>
using namespace std;

string a,b,ret="";
int idx=0; // 넣어야 하는 곳 
bool Check(){
    if(idx<b.size()) return 0;
    for(int i=0;i<b.size();i++) if(ret[idx-1-i] != b[b.size()-1-i]) return 0;
    return 1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);  
    cin>>a>>b;
    for(int i=0;i<a.size();i++){
        if(ret.size()>idx) ret[idx]=a[i]; 
        else ret+=a[i];
        idx++;

        if(Check()) idx-=b.size();
    }
    ret= ret.substr(0,idx);
    if(ret.size())cout<<ret<<'\n';
    else cout<<"FRULA"<<'\n';
}