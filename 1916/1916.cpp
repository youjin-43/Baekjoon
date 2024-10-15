//24.8.1(목) 1916 최소비용 구하기 - 그래프를 배열로 표현  
#include<iostream>
#include<vector>
#include<climits>
using namespace std;


int dp[1001]; //1부터 n까지 사용할거라
int check[1001];
int info[1001][1001];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    // freopen("input.txt", "r", stdin);

    int n,m; //도시의 개수 N(1 ≤ N ≤ 1,000)이 주어지고 둘째 줄에는 버스의 개수 M(1 ≤ M ≤ 100,000)
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                info[i][j]=0;
            }else{
                info[i][j]=INT_MAX;
            }
        }
    }

    int a,b,c;
    for(int i=0;i<m;i++){
        //출발지,도착치,비용
        cin>>a>>b>>c;
        info[a][b]=min(info[a][b],c);
    }
    
    //출발지 도착지
    int start,end; 
    cin>>start>>end;

    //우선 무한으로 채우기
    for(int i=1;i<=n;i++) dp[i]=INT_MAX;

    //출발지부터 다익스트라
    dp[start]=0; 
    int endCnt=0;
    
    while(endCnt<n){
        check[start]=1;

        //start에서 갈 수잇는 곳들 비용 갱신
        for(int tmp_end=1;tmp_end<=n;tmp_end++){
            int cost = info[start][tmp_end];
            if(tmp_end==start || check[tmp_end] || cost==INT_MAX) continue; //방문 안한 노드들만 확인

            dp[tmp_end]=min(dp[tmp_end],dp[start]+cost);
        }
        
        //안가본곳 중 cost가장 낮은곳을 start로 설정
        int minIdx=-1;
        int minValue=INT_MAX;
        for(int i=1;i<=n;i++){
            if(!check[i] && dp[i]<minValue){
                minValue=dp[i];
                minIdx=i;
            }
        }
        start=minIdx;
        endCnt++;
    }

    cout<<dp[end];
}