//ㄹㅇ 디피!!
#include<iostream>
using namespace std;

struct Pos { int y,x; };

int dp[17][17][3]; //1부터 16까지 확인 
int map[17][17];

//Range

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("input.txt","r",stdin);

    int n; cin>>n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>map[i][j];

    //dp 채우기
    dp[1][2][0]=1;//초기값
    for(int i=1;i<=n;i++){
        for(int j=3;j<=n;j++){
            if(map[i][j]) continue; //벽이면 못놓음!

            //수평 0
            dp[i][j][0] = dp[i][j-1][0]+dp[i][j-1][2];

            //수직 1
            dp[i][j][1] = dp[i-1][j][1]+dp[i-1][j][2];

            //대각 2
            if(map[i-1][j] || map[i][j-1]) continue; //위에 옆에도 벽이면 못놓음 
            dp[i][j][2] = dp[i-1][j-1][0]+dp[i-1][j-1][1]+dp[i-1][j-1][2];
        }
    }
    int ret=dp[n][n][0]+dp[n][n][1]+dp[n][n][2];
    cout<<ret<<'\n';



    
}