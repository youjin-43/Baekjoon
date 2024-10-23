#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0); 
    int n; cin>>n;
    
    int blank = n-1;
    while(blank--) cout<<' ';
    cout<<'*'<<'\n';

    for(int i=1;i<n;i++){
        blank=n-i-1;
        while(blank--) cout<<' ';
        cout<<'*';

        for(int j=0;j<i*2-1;j++) cout<<' ';
        cout<<'*'<<'\n';
    }
    
}