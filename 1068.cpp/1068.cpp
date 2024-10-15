//24.9.26(목) 트리
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int d; //삭제할 노드 
int cnt=0;
vector<vector<int> > graph(50);
vector<int> roots;

void solve(int node){
    // base step : 리프노드인경우
    if(graph[node].size()==0){
        cnt++;
        return;
    }
    // recursive step
    for(int i=0;i<graph[node].size();i++){
        int child = graph[node][i];
        //삭제한 노드인 경우 
        if(child==d){
            //삭제한 노드의 부모가 자식이 그놈밖에 없으면 
            if(graph[node].size()==1) cnt++;
            continue;
        }
        solve(child);
    }   
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt", "r", stdin);
    
    int n; cin>>n;
    int p; //parent
    
    for(int i=0;i<n;i++){
        cin>>p;
        if(p==-1){
            roots.push_back(i);
        }else{
            graph[p].push_back(i);
        }
    }
    cin>>d;

    for(auto i : roots){
        //루트를 지우면 볼 필요도 없음
        if(i==d) continue;
        solve(i);
    }
    cout<<cnt<<endl;   
    

}