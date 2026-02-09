#include<iostream>
#include<climits>
#include<algorithm>
#define SIZE 11
using namespace std;

int pw[SIZE][SIZE];
int fr[SIZE];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt","r",stdin);

    int t; cin>>t;
    while(t--){
        int n,m; // 방의 갯수, 비밀 통로 갯수
        cin>>n>>m;

        // pw 초기화
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
            if(i==j) pw[i][j]=0;
            else pw[i][j]=INT_MAX;
        }
        for(int i=0,a,b,c;i<m;i++){
            cin>>a>>b>>c;
            pw[a][b]=c;
            pw[b][a]=c;
        }

        // pw진행
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)for(int k=1;k<=n;k++){
                if(pw[j][i]==INT_MAX || pw[i][k]==INT_MAX) continue;
                pw[j][k]=min(pw[j][k], pw[j][i]+pw[i][k]);
            }
        }

        // 친구 
        int k; cin>>k;
        for(int i=0;i<k;i++)cin>>fr[i];

        // 각 방에서 모였을때 최솟값 찾기
        int min_sum=INT_MAX,ret=0;
        for(int i=1;i<=n;i++){
            int sum=0;

            // 각 친구가 i로 오는 비용 구하기
            for(int j=0;j<k;j++) sum+=pw[fr[j]][i];
            
            if(min_sum>sum){
                min_sum=sum;
                ret=i;
            }
        }

        cout<<ret<<'\n';
    }
}