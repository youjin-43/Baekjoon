// Depth를 이용한 방식(Depth가 홀수면 1번 그룹, 짝수면 0번 그룹)
// 풀이 : https://youjin43.tistory.com/82
#include<iostream>
#include<vector>
#include<queue>
# define MAX 20'001
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t; cin>>t;
    while(t--){
        int vertex,e,isAble=1; cin>>vertex>>e; //그래프의 정점의 개수 V, 간선의 개수 E
        vector<vector<int>> graph(vertex+1);

        // 간선 입력 받기 
        for(int i=0,a,b;i<e;i++){
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        //BFS
        queue<int> q; 
        int v[MAX]={0,};
        
        for(int i=1;i<=vertex;i++){
            if(v[i]) continue;

            q.push(i); v[i]=1;
            while(q.size()){
                int node = q.front(); q.pop();
                for(int adj : graph[node]){
                    // 같은 그룹에 있으면 NO
                    if(v[adj] && (v[adj]&1) == (v[node]&1)){ isAble=0; break;} 
                    // 아직 방문 안했으면 큐에 추가 
                    if(!v[adj]){ q.push(adj); v[adj]=v[node]+1; }
                }
                if(!isAble) break;
            }
        }

        if(isAble) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
}