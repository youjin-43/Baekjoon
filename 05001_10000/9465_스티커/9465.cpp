#include<iostream>
using namespace std;
int list[100000][2];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t; cin>>t;    
    while(t--){
        int n; cin>>n;
        for(int i=0;i<n;i++)cin>>list[i][0];
        for(int i=0;i<n;i++)cin>>list[i][1];
        
        for(int i=1;i<n;i++){
            if(i==1){
                list[i][0]+=list[i-1][1];
                list[i][1]+=list[i-1][0];
                continue;
            }
            int tmp = max(list[i-2][0],list[i-2][1]);
            list[i][0]+=max(list[i-1][1],tmp);
            list[i][1]+=max(list[i-1][0],tmp);
        }
        cout<<max(list[n-1][0],list[n-1][1])<<'\n';
    }
}