//24.11.19
// 아 pq 기본은 max아닌가? 
#include<iostream>
#include<climits>
#include<queue>
using namespace std;

int n;//지역의 개수 n (1 ≤ n ≤ 100)
int m; //예은이의 수색범위 m (1 ≤ m ≤ 15)
int r; //길의 개수 r (1 ≤ r ≤ 100)

//1부터 100까지 사용
int ItemCnt[101]; 
vector<vector<pair<int,int> > > graph(101);
int dist[101];

void Dikjstra(int node){
    int visit[101]={0,};

    //dist 우선 INTMAX로 채우기
    for(int i=1;i<=n;i++) dist[i]=INT_MAX;
    dist[node]=0; //시작노드까지의 거리는 0

    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq; // 거리, 노드 페어
    pq.push(make_pair(0,node)); 

    while(!pq.empty()){
        visit[node]=1;
        int distance = pq.top().first;
        pq.pop();

        //방문할 수 있는 노드마다 dist를 갱신해 나감 
        for(int i=0;i<graph[node].size();i++){
            int next = graph[node][i].first;
            int cost = graph[node][i].second;

            // 아직 방문하지 않았고 현재 노드를 거쳐서 가는게 더 빠르다면 dist 갱신
            if(!visit[next] && dist[next]>distance+cost){
                dist[next]=distance+cost;
                pq.push(make_pair(distance+cost,next));
            }
        }
        
        //가장 거리가 가까운 곳(top) 방문
        node = pq.top().second;
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>r;
    for(int i=1;i<=n;i++) cin>>ItemCnt[i];

    int a,b,l;
    for(int i=0;i<r+2;i++){
        cin>>a>>b>>l;
        graph[a].push_back(make_pair(b,l));
        graph[b].push_back(make_pair(a,l));
    }


    int ret=0;
    //각노드에서 시작했을때 아이템을 몇개 먹는지 확인 
    for(int i=1;i<=n;i++){
        //i에서 시작했을 떄 각 노드까지의 최소거리를 구힘
        Dikjstra(i);

        int cnt=0;
        //그중에서 수색 범위에 있는 아이템 습득
        for(int j=1;j<=n;j++){
            if(dist[j]<=m) cnt+=ItemCnt[j];
        }
        ret=max(cnt,ret);
    }
    cout<<ret<<'\n';
}