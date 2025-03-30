//24.9.25(수) 트리게임 

//한 번 방문했던 정점으로는 이동할 수 없음
// 더는 말을 움직일 수 없게 되면 게임 종료
// 이때 게임 진행 과정에서 한 번이라도 말이 목표 정점을 방문했다면 선공의 승리, 아니면 후공의 승리

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<vector<int> > graph(100001);
int check[100001]={0,};

int n; //정점의 개수 N(≤100,000)
int s; //말의 시작 정점 
int g; //목표 정점 

bool Find(int node, bool isFirst){
    stack<pair<int,int>> st; //node, isFirst pair 
    st.push(make_pair(node,1)); check[node]=1;
    
    while(!st.empty()){
        node = st.top().first; 
        isFirst = st.top().second;
        st.pop();

        for(int i=0;i<graph[node].size();i++){
            if(!check[graph[node][i]]){
                st.push(make_pair(graph[node][i],!isFirst));
                check[graph[node][i]]=1;
            }
        }

    }

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
    
    if(s==g){
        cout<<"First"<<endl;
        exit(0);
    }

    if(Find(s,1)){
        cout<<"First"<<endl;
    }else{
        cout<<"Second"<<endl;
    }
}