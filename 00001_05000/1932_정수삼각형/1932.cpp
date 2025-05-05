//1932_정수삼각형

#include <cstdio>
#include <iostream>
#include <iostream>
#include <algorithm>
using namespace std;


#define bsz 1 << 14
char RBUF[bsz];
int l = 0, r = 0;

inline char read() {
    if(l == r) {
        r = (int)fread(RBUF, 1, bsz, stdin);
        l = 0;

        if (r == 0) {
            // fprintf(stderr, "[EOF] fread returned 0 - no more input\n");
            return -1; // Signal end of input
        }
    }
    // printf("read(): l=%d, char='%c' (%d)\n", l, RBUF[l], RBUF[l]);
    return RBUF[l++];
}

// inline char read() {
//     if(l == r) { r = (int)fread(RBUF, 1, bsz, stdin); l = 0; }
//     return RBUF[l++];
// }

inline int readInt() {
    int ret = 0, tmp = read();
    while (tmp >= 48) { ret = ret * 10 + tmp - 48; tmp = read(); }
    return ret;
}

// inline int readInt() {
//     int ret = 0;
//     char tmp = read();

//     // 공백, 줄바꿈, 탭 등 스킵
//     while (tmp != -1 && (tmp < '0' || tmp > '9')) tmp = read();

//     // 숫자 읽기
//     while (tmp != -1 && tmp >= '0' && tmp <= '9') {
//         ret = ret * 10 + (tmp - '0');
//         tmp = read();
//     }
//     // cout<<ret<<endl;

//     return ret;
// }

int dp[130000];
int main(){
    // ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL); 
    // freopen("input.txt","r",stdin);

    int n = readInt(); // n<=500
    // printf("%d\n",n);

    int idx=1,ans=0;;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++){
            int num = readInt();
            dp[idx++] = num;
            // printf("%d ", num);
        }

    // for(int i=1;i<idx;i++) printf("%d ",dp[i]);
    // printf("\n");

    
    // n==1인 경우는 그냥 출력
    if(n==1) {cout<<dp[1]<<'\n'; return 0;}

    idx=1;
    for(int i=2;i<=n;i++){
        idx+=i-1;
        for(int j=0;j<i;j++){
            if(j==0) dp[idx+j]+=dp[idx-i+1];// 가장 왼쪽인 경우는 그냥 오른쪽꺼 가져옴 
            else if(j==i-1) dp[idx+j]+=dp[idx-1]; // 가장 오른쪽인 경우는 그냥 왼쪽꺼 가져옴 
            else dp[idx+j] += max(dp[idx+j-i],dp[idx+j-i+1]);

            if(i==n) ans=max(ans,dp[idx+j]);
        }
    }
    // cout<<ans<<'\n';
    printf("%d\n", ans);
}