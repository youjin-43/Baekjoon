#include<iostream>
using namespace std;

int list[50000];
int dp[3][50000]={0,};
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("input.txt","r",stdin);

    int n,s; cin>>n;
    for(int i=0;i<n;i++) cin>>list[i];
    cin>>s;//size

    //1대
    for(int i=s-1;i<n;i++) for(int j=0;j<s;j++) dp[0][i]+=list[i-j];
    
    //2대
    int tmp=0;
    for(int i=2*s-1;i<n;i++) {
        tmp=max(tmp,dp[0][i-s]);
        dp[1][i]=max(dp[1][i],dp[0][i]+tmp);
    }

    for(int i=3*s-1;i<n;i++) dp[2][i]=max(dp[2][i-1],dp[0][i]+dp[1][i-s]); //3대 
    cout<<ret<<'\n';
}