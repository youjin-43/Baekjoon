// 1660_캡틴이다솜 
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

#define MAX_SIZE 200
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int n; cin>>n; // n<=300,000
    
    vector<int> dp(n+1,INT_MAX);
    dp[0]=0;
    for(int i=1,tri=0,sum=0;;i++){
        tri += i;       // 삼각수
        sum += tri;     // 사면체 수
        if(sum>n) break;

        for(int j=sum;j<=n;j++)dp[j]=min(dp[j],dp[j-sum]+1);
    }
    cout<<dp[n]<<'\n';
  
}