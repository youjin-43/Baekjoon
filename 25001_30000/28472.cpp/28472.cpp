//24.11.16(토) Minimax Tree
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

vector<vector<int> >graph(100001); // 1부터 10^5까지 사용 
int score[100001];
bool visit_[100001];

int Solve(int node, bool isMax){
    visit_[node]=1;
    stack<int>st; //node의 자식들을 넣어놓음 
    for(int i=0;i<graph[node].size();i++){
        int child = graph[node][i];
        if(!visit_[child]) {
            st.push(child);
            visit_[child]=1;
        }
    }

    //base step - 자식 노드인경우 -> 자식이 0인 경우
    if(st.size()==0) return score[node];
    
    //recursive step 
    score[node]=Solve(st.top(),!isMax); st.pop();//일단 첫번째 자식을 자기 값으로
    
    while(!st.empty()){
        score[node]= isMax? max(Solve(st.top(),!isMax),score[node]) : min(Solve(st.top(),!isMax),score[node]);
        st.pop();
    }
    return score[node];
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("input.txt","r",stdin);

    int n; cin>>n; //2 <=N<=10^5
    int rootNode; //1 <= R <=N -> 와 루트가 1아닐수도 있는거 악마아니냐? 
    cin>>rootNode; 

    //트리 그리기 -> 양방향 그래프로 그림 
    for(int i=0,a,b;i<n-1;i++){ //n개의 노드 -> N-1개의 간선 
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    //리프노드
    int L; cin>>L; //리프 노드의 갯수 1<=L<=N
    for(int i=0,k,t;i<L;i++){
        cin>>k>>t;
        score[k]=t;
    }

    //miniMax 구하기!
    int tmp = Solve(rootNode,1);

    int testCace; cin>>testCace; //구해야하는 노드의 갯수 
    int num; 
    while(testCace--){
        cin>>num;
        cout<<score[num]<<'\n';
    }
    return 0;
}