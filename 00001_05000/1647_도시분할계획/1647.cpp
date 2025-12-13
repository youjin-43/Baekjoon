#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define SIZE 20
struct  Info
{
    int c,a,b;
    bool operator<(const Info& other) const{
        return c>other.c;
    }
};

vector<vector<pair<int,int>>> graph(SIZE);
priority_queue<Info> pq;
int v[SIZE]={0,};
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    // freopen("input.txt","r",stdin);

    int n,m; cin>>n>>m;
    for(int i=0,a,b,c;i<m;i++){
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }



    //0번 노드에서 갈 수 있는 곳을 모두 pq에 넣음 
    for(int i=0;i<graph[1].size();i++) pq.push({graph[1][i].second,1,graph[1][i].first});
    v[1]=1;

    // 거리가 가장 가까운 곳을 이어나감 
    int ret=0;
    int m_cost=0; // 비용이 가장 많이 드는 길 -> 나중에 이거만 끊어냄 
    while (pq.size())
    {
        Info cur = pq.top(); pq.pop();
        if(v[cur.b]) continue; // 이미 방문했던 곳이라면 패쓰

        v[cur.b]=1; // 아직 방문하지 않았다면 방문 
        ret += cur.c;
        m_cost = max(m_cost, cur.c);

        // 갈 수 있는곳 모두 pq에 넣기
        int s = cur.b;
        int e,c;
        for(int i=0;i<graph[s].size();i++){
            e = graph[s][i].first;
            if(v[e]) continue; // 도착지가 이미 방문한 곳이면 pass
            c = graph[s][i].second;
            pq.push({c,s,e});
        }
    }
    cout<<ret-m_cost<<'\n';
}