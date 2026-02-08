#include<iostream>
#include<vector>
#define SIZE 101
using namespace std;

int n,m;
vector<vector<pair<int,int>>>graph(SIZE);
int ret[SIZE]={0,};
int need[SIZE][SIZE]={0,};
int v[SIZE]={0,};

// a에 b의 필요 부품들을 더해줌
void needAdd(int a,int b,int cnt){
    for(int i=1;i<n;i++) if(need[b][i]) need[a][i]+=(need[b][i]*cnt);
}

void DFS(int cur, int cnt){

    v[cur]=1; // 방문처리 

    //base - 기본 부품인 경우
    if(!graph[cur].size()) need[cur][cur]=1; // 기본 부품인 나 자신은 1개 처리

    //recursive 
    for(int i=0;i<graph[cur].size();i++){
        int next = graph[cur][i].first;
        int c = graph[cur][i].second;

        // 방문하지 않은 곳만 DFS 처리 
        if(!v[next])DFS(next,c*cnt);
        needAdd(cur,next, c);
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    // freopen("input.txt","r",stdin);

    cin>>n>>m;
    for(int i=0,a,b,c;i<m;i++){
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
    }

    DFS(n,1);

    for(int i=1;i<n;i++){
        if(graph[i].size()) continue;
        cout<<i<<' '<<need[n][i]<<'\n';
    }
}