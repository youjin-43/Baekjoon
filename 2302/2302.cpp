#include<iostream>
#include<cmath>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("input.txt","r",stdin);

    int n,vipCnt; cin>>n>>vipCnt;
    
    int dp[41]={0,}; dp[0]=1; dp[1]=1;
    for(int i=2;i<=n;i++) dp[i]=dp[i-1]+dp[i-2];


    int ret=1,start=1,end,size; 
    while(vipCnt--){
        cin>>end;
        size=end-start;
        ret*=dp[size];
        start=end+1;
    }
    size=n-start+1;
    if(size>1) ret*=dp[size];
    cout<<ret<<'\n';
}