//24.9.25(수) 트리게임 
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<vector<int> > graph(100001);
int check[100001]={0,};

int n; //정점의 개수 N(≤100,000)
int s; //말의 시작 정점 
int g; //목표 정점 

int Find_depth(int node,int depth){
    check[node]++;

    //baseStep
    if(node == g){
        return depth;
    }
    //recursiveStep
    

}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt", "r", stdin);
    
    cin>>n>>s>>g;
    for(int i=0,a,b;i<n;i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    //시작노드에서 목표노드까지의 깊이 탐색 
    int tmp= Find_depth(s,0);
    
    if(tmp%2){
        cout<<"First"<<endl;
    }else{
        cout<<"Second"<<endl;
    }

}