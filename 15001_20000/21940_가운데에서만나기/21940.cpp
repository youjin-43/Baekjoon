// 21940 가운데에서 만나기
// 풀이 : https://youjin43.tistory.com/81
#include<iostream>
#include<vector>
#include<queue>
#include<climits>

#define MAX 201
using namespace std;

vector<vector<pair<int,int>>> graph(MAX+1);
vector<vector<int>> min_dist(MAX+1,vector<int>(MAX+1,INT_MAX));

priority_queue<pair<int,int>> pq; // dist,node
void dijkstra(int start){
   
    pq.push({0,start});
    min_dist[start][start]=0;

    while(!pq.empty()){
        int cur_dist=pq.top().first;
        int cur_node=pq.top().second;
        pq.pop();

        for(int i=0;i<graph[cur_node].size();i++){
            int next_node=graph[cur_node][i].first;
            int cost=graph[cur_node][i].second;
            
            if(min_dist[start][next_node]>cur_dist+cost){
                min_dist[start][next_node]=cur_dist+cost;
                pq.push({cur_dist+cost,next_node});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    // 입력 받기 
    int n,m; cin>>n>>m;
    for(int i=0,a,b,c;i<m;i++){
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
    }

    // 다익스트라로 각 노드에서 노드까지 최단거리 구하기 
    for(int i=1;i<=n;i++)dijkstra(i);
    
    // 최단 왕복거리 구하기
    vector<vector<int>> dist(MAX+2,vector<int>(MAX+1));
    int k; cin>>k;
    for(int i=0,start;i<k;i++){
        cin>>start;
        for(int j=1;j<=n;j++)dist[start][j]=min_dist[start][j]+min_dist[j][start];
    }

    // 최단 왕복거리 중 최댓값 구하기
    for(int i=1;i<=n;i++){
        dist[n+1][i]=dist[1][i];
        for(int j=1;j<n;j++) if(dist[j][i]) dist[n+1][i]=max(dist[n+1][i],dist[j][i]);
    }

    // 최단 왕복거리 중 최솟값이 가장 작은 노드 구하기
    int min_value=INT_MAX;
    for(int i=1;i<=n;i++) min_value=min(min_value,dist[n+1][i]);

    // 답 출력 
    for(int i=1;i<=n;i++) if(dist[n+1][i]==min_value) cout<<i<<' ';
}