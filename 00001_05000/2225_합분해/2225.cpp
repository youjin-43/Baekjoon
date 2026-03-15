#include<iostream>
#define SIZE 201
using namespace std;

int dp[SIZE][SIZE]={0,};
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,k; cin>>n>>k; // 200 이하 

    // 0부터 N까지의 정수 K개를 더해서 그 합이 N이 되는 경우의 수

    // 초기화
    for(int i=0;i<=SIZE;i++){dp[0][i]=1; dp[i][0]=1;}

    // dp
    for(int i=1;i<=k;i++) for(int j=1;j<=n;j++){
        for(int k=0;k<=j;k++){
            dp[i][j]+=dp[i-1][k];
            dp[i][j]%=1'000'000'000;
        }
    }
    cout<<dp[k-1][n]<<'\n';
}