#include<iostream>
#include<vector>
#define SIZE 10
using namespace std;

int UF[SIZE]; //F
int Root(int node){
    if (UF[node] == node) return node;
    return UF[node] = Root(UF[node]); // 경로 압축 
}

void Union(int a, int b){
    UF[Root(a)]=Root(b);
}
vector<vector<int>> graph(SIZE); //E

void DFS(int from, int node, int d){
    //base
    if(d==2){
        if(from != node) 
            Union(from,node);
        return;
    }

    // recursive
    for(int i=0;i<graph[node].size();i++){
        DFS(from,graph[node][i],d+1);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    // freopen("input.txt","r",stdin);

    int n,m;
    cin>>n>>m;

    // Init UF
    for(int i=0;i<=n;i++)UF[i]=i;

    char c;
    for(int i=0,a,b;i<m;i++){
        cin>>c>>a>>b;
        if(c=='E'){ 
            graph[a].push_back(b); 
            graph[b].push_back(a); 
        }
        else Union(a,b);
    }

    for(int i=1;i<=n;i++){
        if(!graph[i].size()) continue;
        DFS(i,i,0);
    }

    int ret=0;
    for(int i=1;i<=n;i++) if(UF[i]==i) ret++;
    
    cout<<ret<<'\n';

}