//24.11.18(월)
#include<iostream>
using namespace std;
int mod = 1000000000;

int dp[10][101][1024]; //0~9까지 숫자를 | 1부터 n자리수에 | 어떤 수로 채워넣었느지 배열로 기억 
int n;

//bit의 n번째 자리를 1로 셋팅 
int Set_bit(int bit,int n){
    int tmp=1;
    while(n--){
        tmp<<=1;
    }
    bit |=tmp;
    return bit;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    //입력받기 
    cin>>n;

    //초깃값 셋팅 -> 첫번째 자리에 0이 오는건 제외해야하는것 같음 
    for(int i=1;i<=9;i++){
        dp[i][1][Set_bit(0,i)]=1;
    }

    //dp 실행
    for(int i=2;i<=n;i++){
        //i번째 자리에 0을 채워넣을떄 
        for(int k=0;k<1024;k++){
            if(dp[1][i-1][k]) {
                ((dp[0][i][Set_bit(k,0)]%=mod)+=dp[1][i-1][k])%=mod; //j+1에서 가져올떄 
            }
        }

        //i번째 자리에 1~8을 채워넣을떄 
        for(int j=1;j<=8;j++){
            for(int k=0;k<1024;k++){
                int tmp = Set_bit(k,j);
                if(dp[j-1][i-1][k]) (dp[j][i][tmp]+=dp[j-1][i-1][k])%=mod; //j-1에서 가져올떄 
                if(dp[j+1][i-1][k]) (dp[j][i][tmp]+=dp[j+1][i-1][k])%=mod; //j+1에서 가져올떄 
            }   
        }
        //i번째 자리에 9을 채워넣을떄 
        for(int k=0;k<1024;k++){
            if(dp[8][i-1][k]) (dp[9][i][Set_bit(k,9)]+=dp[8][i-1][k])%=mod; //j-1에서 가져올떄 
        }
    }

    int ret=0;
    for(int i=0;i<=9;i++){
        if(dp[i][n][1023]){ //0부터 9까지 모든 비트가 1이면 1023
            ret+=dp[i][n][1023];
            ret%=mod;   
        }
        
    }
    cout<<ret<<'\n';
}