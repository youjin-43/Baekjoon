//24.8.1(목)  1753 최단경로 - 시간초과
#include<iostream>
#include<vector>
#include<climits>
using namespace std;


int dp[20001]; //1부터 n까지 사용할거라
int check[20001];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    // freopen("input.txt", "r", stdin);

    int n,m; //정점의 개수 V와 간선의 개수 E가 주어진다. (1 ≤ V ≤ 20,000, 1 ≤ E ≤ 300,000) 
    cin>>n>>m;

    //출발지
    int start;
    cin>>start;

    vector<vector<pair<int,int> > > graph(n+1);
    int a,b,c;
    for(int i=0;i<m;i++){
        //출발지,도착치,비용(10이하의 자연수)
        cin>>a>>b>>c;
        graph[a].push_back(make_pair(b,c));
        // graph[b].push_back(make_pair(a,c)); //- 방향 그래프니까
    }
    


    //우선 무한으로 채우기
    for(int i=1;i<=n;i++) dp[i]=INT_MAX;

    //출발지부터 다익스트라
    dp[start]=0; 
    int endCnt=0;
    
    while(endCnt<n){
        check[start]=1;



        //start에서 갈 수잇는 곳들 비용 갱신
        for(int i=0;i<graph[start].size();i++){
            int tmp_end = graph[start][i].first;

            if(check[tmp_end]) continue; //방문 안한 노드들만 확인
            int cost = graph[start][i].second;

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

    for(int i=1;i<=n;i++){
        if(dp[i]==INT_MAX){
            cout<<"INF"<<'\n';
        }else{
            cout<<dp[i]<<'\n';
        }
        
    }
}