// 15681_트리와쿼리
// 풀이 링크 : https://youjin43.tistory.com/76

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define MAX 100001
vector<vector<int>> tree(MAX);
int sub_tree_size[MAX]={0,};

// 서브트리의 크기를 리턴
int visited[MAX]={0,};
int dfs(int root, int parent){
    visited[root]=1; // 방문 처리

    // 리프노드인 경우
    if(tree[root].size()==1 && parent!=0){
        sub_tree_size[root]=1;
        return 1;
    }

    // 자식노드 방문
    int cnt=1;
    for(int i=0;i<tree[root].size();i++){
        if(!visited[tree[root][i]]) cnt+=dfs(tree[root][i], root);
    }
    sub_tree_size[root]=cnt;
    return cnt;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("input.txt","r",stdin);

    //트리의 정점의 수 N과 루트의 번호 R, 쿼리의 수 Q
    int n,r,q; cin>>n>>r>>q;
    for(int u,v,i=0;i<n-1;i++){ cin>>u>>v; tree[u].push_back(v); tree[v].push_back(u);}

    // 서브트리의 크기 구하기
    sub_tree_size[r]=dfs(r,0);
    // for(int i=0;i<=n;i++) cout<<sub_tree_size[i]<<' ';cout<<endl;

    //쿼리 처리
    int new_root; 
    while(q--){
        cin>>new_root;
        cout<<sub_tree_size[new_root]<<'\n';
    }
}