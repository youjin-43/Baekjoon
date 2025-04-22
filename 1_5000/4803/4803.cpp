//24.09.29(일) 트리 -> 사이클 있는지만 확인하면 됨!
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int n,m;
vector<vector<int> > graph(501);
int tree_cnt=0;
int check[501]={0,}; // 1부터 n까지 사용


void AllCheck(int node){
    int check_tmp[501]={0,}; // 1부터 n까지 사용
    stack<int> st_tmp;

    st_tmp.push(node);

    while(!st_tmp.empty()){
        int top = st_tmp.top();
        st_tmp.pop();
        check_tmp[top]++;
        check[top]++;

        for(int child : graph[top]){
            if(!check_tmp[child]) st_tmp.push(child);
        }
    }

}
//cycle인지 반환 
int find(int root){
    check[root]++; //시작 노드 체크 

    stack<int> st;
    int isCycle = 0;
    for(int node : graph[root]){
        //이미 방문한 노드르 또 방문하면
        if(check[node]){
            check[node]++;
            if(check[node]%2==0){
                continue;
            }
            else{
                isCycle=1;
            }
        }
        st.push(node);
    }
    
    //cycle이라는게 밝혀지면 나머지 인접 노드들은 볼 필요도 없음 -> 죄다 check 해버림
    if(isCycle){
        AllCheck(root);
        return 1;
    }

    while(!st.empty()){
        int top = st.top();
        st.pop();
        
        bool isCycle = find(top);
        check[root]++;
        if(isCycle){
            return 1;
        }
    }

    return 0;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt", "r", stdin);

    cin>>n>>m; // n ≤ 500과 m ≤ n(n-1)/2
    int tc=1;
    while(!(n==0 && m==0)){
            //그래프 그리기(입력받기)
        for(int i=0,a,b;i<m;i++){
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        //모든 노드 순서대로 확인
        for(int i=1;i<=n;i++){
            //이미 방문한 노드이면 패스 
            if(check[i]) continue;

            if(find(i)==0) tree_cnt++;
        }

        if(tree_cnt==0){
            cout<<"Case "<<tc<<": No trees."<<endl;
        }
        else if(tree_cnt==1){
            cout<<"Case "<<tc<<": There is one tree."<<endl;
        }else{
            cout<<"Case "<<tc<<": A forest of "<<tree_cnt<<" trees."<<endl;
        }
        
        //초기화
        for(int i=1;i<=n;i++){
            graph[i].clear();
        }
        tree_cnt=0;
        for(int i=0;i<=n;i++) check[i]=0;
        

        //새로운 입력 받기
        tc++;
        cin>>n>>m;        
    }

}   