#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    int ret=0;
    int cnt=1;
    while(n){
        if(n>=cnt){
            ret++;
            n-=cnt;
            cnt++;
        }else{
            cnt=1;
        }
    }   
    cout<<ret<<'\n';
}