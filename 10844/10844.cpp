#include<iostream>
using namespace std;

int dp[10][100]; // 숫자, 자릿수 
// dp[i][j] == i가 10^j승 자이레 왔을 때  

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int div = 1000000000;
    int n; cin>>n; //n은 1~100

    //1의자리수인경우
    for(int i=0;i<=9;i++) dp[i][0]=1;
    
    //10의 자리부터 각 자리수에 0부터 9까지 올 경우를 dp에 채움  
    for(int pos = 1; pos<n;pos++){
        //0일경우
        dp[0][pos]=dp[1][pos-1];
        
        //1부터 8이 가장 큰 자릿수에 올 경우
        for(int i=1;i<=8;i++) dp[i][pos]=(dp[i-1][pos-1]+dp[i+1][pos-1])%div;
        
        //9가 가장 큰 자릿수에 올 경우
        dp[9][pos]=dp[8][pos-1];
    }    

    int sum=0;
    for(int i=1;i<=9;i++) {
        sum+=dp[i][n-1];
        sum%=div;
    }
    cout<<sum<<endl;
}
