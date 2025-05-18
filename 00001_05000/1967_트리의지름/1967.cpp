// 트리의 지름 : 트리에 존재하는 모든 경로들 중에서 가장 긴 것의 길이

#include<iostream>
#include<vector>
using namespace std;

vector<vector<pair<int,int>>> list; // 노드, 가중치 

pair<int,int> DFS(int node, int parent, int dist){
    pair<int,int> ret = {dist, node};
    for(auto& [next, weight] : list[node]){
        if(next == parent) continue;
        ret = max(ret, DFS(next, node, dist + weight));
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    // 입력받기 
    // 루트 노드의 번호는 항상 1, 간선의 가중치는 100보다 크지 않은 양의 정수
    int n; cin>>n; // 노드의 개수 n(1 ≤ n ≤ 10,000)
    if(n==1){ cout<<0<<'\n'; return 0; }
    list.resize(n+1);
    
    int a,b,c; // 부모노드, 자식노드, 가중치 
    while(cin>>a>>b>>c){
        list[a].push_back({b,c});
        list[b].push_back({a,c});
    }

    // DFS 2번만 실행: ① 아무 노드에서 가장 먼 노드 k 탐색 ② k에서 다시 가장 먼 거리 탐색하여 지름 계산
    auto k = DFS(1, -1, 0);        // 1번 노드에서 가장 먼 노드 찾기
    auto ret = DFS(k.second, -1, 0);  // 그 노드에서 또 가장 먼 거리 구하기
    cout<<ret.first<<'\n';
}