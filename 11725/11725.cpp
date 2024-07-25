//24.7.1(월)11725 트리의 부모 찾기 -> 그래프 탐색

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define Size 100000

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int n;cin>>n;n++; 
    vector<vector<int> > graph(n);
    for(int i=0,a,b;i<n;i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    //1부터 탐색
    queue<int> q;
    int check[Size]={0,};
    int ret[Size]={0,};

    q.push(1);
    
    while(!q.empty()){
        int top = q.front(); 
        q.pop();

        check[top]=1;
        for(int i=0;i<graph[top].size();i++){
            if(!check[graph[top][i]]){
                q.push(graph[top][i]);
                ret[graph[top][i]]=top;
            }
        }
    }

    for(int i=2;i<n;i++){
        if(ret[i]) cout<<ret[i]<<'\n';
    }    
}