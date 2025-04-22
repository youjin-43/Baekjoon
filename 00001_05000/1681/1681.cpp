#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    int n,m; cin>>n>>m;
    vector<vector<int> > graph(n+1); //1부터 n까지 사용 

    for(int i=0,a,b;i<m;i++){
        cin>>a>>b;
        graph[b].push_back(a);
    }
    vector<bool> check(n+1);
    int ret[10001];

    queue<int> st;
    int maxCnt=0;
    for(int i=1;i<=n;i++){
        
        fill(check.begin(), check.end(), false);
        
        int cnt=1;
        st.push(i);
        check[i]=1;
        
        while(!st.empty()){
            int top = st.front();
            st.pop();

            for(int j=0;j<graph[top].size();j++){
                int node = graph[top][j];
                if(!check[node]){  
                    check[j]=1;
                    st.push(node);
                    cnt++;
                }
            }
        }

        ret[i] = cnt;
        maxCnt = max(maxCnt,cnt);
    }

    for(int i=1;i<=n;i++){
        if(ret[i]==maxCnt){
            cout<<i<<' ';
        }
    }
    cout<<endl;



}