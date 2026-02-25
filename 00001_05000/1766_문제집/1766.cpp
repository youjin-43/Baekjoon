#include<iostream>
#include<vector>
#include<queue>
#define SIZE 32'001
using namespace std;

vector<vector<int>> graph(SIZE);
int list[SIZE];
priority_queue<int,vector<int>,greater<int>> pq; // min_heap
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m; cin>>n>>m;
    for(int i=0,a,b;i<m;i++){
        cin>>a>>b;
        graph[a].push_back(b);
        list[b]++;
    }

    // 진입차수가 0인거 푸시 
    for(int i=1;i<=n;i++) if(!list[i]) pq.push(i);

    while(pq.size()){
        int node = pq.top(); pq.pop();
        cout<<node<<' ';

        for(int i=0;i<graph[node].size();i++){
            list[graph[node][i]]--;

            // 진입차수가 0이 되면 푸시
            if(!list[graph[node][i]]) pq.push(graph[node][i]);
        }
    }
}