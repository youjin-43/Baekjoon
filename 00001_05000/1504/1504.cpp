//24.10.24(목) 1504 다익스트라 여러번 사용하면 되지 않을까?
#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<algorithm>
using namespace std;

int n,e;
vector<vector<pair<int,int> > > graph(801); ////1~n까지 사용 

int dijkstra(int s, int d){
    priority_queue<pair<int,int>, vector<pair<int,int> >,greater<pair<int,int> > > pq;
    vector<int> length(n+1,INT_MAX);
    
    length[s]=0; 
    pq.push(make_pair(0,s));
    
    while(!pq.empty()){
        int node = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        if(length[node]<dist) continue;

        for(int i=0;i<graph[node].size();i++){
            int toNode=graph[node][i].first;
            int weight = graph[node][i].second;
            
            if(length[node]+weight<length[toNode]){
                length[toNode]=length[node]+weight;
                pq.push(make_pair(length[toNode],toNode));
            }
        }
    }
    if(length[d]==INT_MAX){
        return -1;
    }
    return length[d];
}


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    // freopen("input.txt","r",stdin);

    cin>>n>>e;// 정점의 개수 N과 간선의 개수 E가
    int s,d,w;
    for(int i=1;i<=e;i++){
        cin>>s>>d>>w;
        graph[s].push_back(make_pair(d,w));
        graph[d].push_back(make_pair(s,w));
    }

    int a,b; cin>>a>>b;

    int StoA = dijkstra(1,a);
    int BtoN = dijkstra(b,n);

    int StoB = dijkstra(1,b);
    int AtoN = dijkstra(a,n);
    
    int AtoB = dijkstra(a,b);
    
    int first=INT_MAX;
    if(StoA!=-1 && AtoB!=-1 && BtoN!=-1){
        first = StoA + AtoB + BtoN;
    }

    int second=INT_MAX;
    if(StoB!=-1 && AtoB!=-1 && AtoN!=-1){
        second = StoB + AtoB + AtoN;
    }
    
    int ret= min(first,second);
    if(ret==INT_MAX){
        cout<<-1<<endl;
    }else{
        cout<<ret<<endl;
    }
    
}