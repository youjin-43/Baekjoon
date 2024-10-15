#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int h,w,n;
        cin>>h>>w>>n;
        if(n%h==0){
            cout<<h*100+n/h<<'\n';
        }else{
            cout<<n%h*100+n/h+1<<'\n';
        }
        
    }
}