//24.8.1(목)  1753 최단경로 - pq이용 - 아니 이건 또 메모리 초과가 아니네??
#include<iostream>
#include<vector>
#include<climits>
#include<queue>
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
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq; //오름차순 정렬
    //first 기준 오름차순, 같으면 두번째 오름차순이라 first에 코스트를 넣고 second에 노드번호를 넣을거임
    
    dp[start]=0; 
    int start_cost = 0;
    pq.push(make_pair(start_cost,start)); 
    
    while(!pq.empty()){
        start = pq.top().second;
        start_cost = pq.top().first;
        pq.pop();

        check[start]=1; //방문했다고 표시

        //start에서 갈 수잇는 곳들 비용 갱신
        for(int i=0;i<graph[start].size();i++){
            int tmp_end = graph[start][i].first;

            if(check[tmp_end]) continue; //방문 안한 노드들만 확인
            // if(dp[tmp_end] < start_cost) continue; 

            int cost = graph[start][i].second;

            // dp[tmp_end]=min(dp[tmp_end],start_cost+cost);
            // pq.push(make_pair(dp[tmp_end],tmp_end));

            if(start_cost+cost<dp[tmp_end]){
                dp[tmp_end]=start_cost+cost;
                pq.push(make_pair(dp[tmp_end],tmp_end));
            }
        }
    }

    //출력
    for(int i=1;i<=n;i++){
        if(dp[i]==INT_MAX){
            cout<<"INF"<<'\n';
        }else{
            cout<<dp[i]<<'\n';
        }
    }
}