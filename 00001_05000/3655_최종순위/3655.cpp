#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define SIZE 501
using namespace std;

int n; // 노드의 갯수 
vector<vector<int>> graph(SIZE);
int list[SIZE]; // 작년 순위
int cnt[SIZE]; // 진입 차수 

queue<int> q;

bool Check_Reverse(int a, int b){
    auto it = lower_bound(graph[a].begin(),graph[a].end(),b);
    if(it!=graph[a].end() && *it==b){
        *it = -1; // 중간에 빼는건 힘드니까 그냥 -1로 해버림 

        // b->a로 바꾸기
        graph[b].push_back(a);

        // 진입차수 변경
        cnt[b]--;
        cnt[a]++;

        // 다시 소팅 
        sort(graph[a].begin(),graph[a].end());
        sort(graph[b].begin(),graph[b].end());

        return 1;
    }
    return 0;
}

vector<int> ret;
bool Check_Impossible(){
    return ret.size()<n && q.empty(); 
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    // freopen("input.txt","r",stdin);

    int t,m; cin>>t;
    while(t--){
        // 초기화
        graph = vector<vector<int>>(SIZE); // 그래프
        ret = vector<int>(); // 결과 

        cin>>n;
        for(int i=0;i<n;i++){
            cin>>list[i];
            cnt[i+1]=0; // cnt 같이 초기화
        }

        // 기본 그래프 연결
        for(int i=0;i<n-1;i++){
            int cur = list[i];
            for(int j=i+1;j<n;j++){
                graph[cur].push_back(list[j]);
                cnt[list[j]]++;
            }
        }

        // 소팅 
        for(int i=1;i<=n;i++) sort(graph[i].begin(),graph[i].end());

        // 뒤바뀐 순위
        cin>>m;
        for(int i=0,a,b;i<m;i++){
            cin>>a>>b;
            
            if(Check_Reverse(a,b)) continue; // a -> b가 있는지 확인
            else Check_Reverse(b,a); // b -> a가 있는지 확인 
        }

        // 위상정렬 시작 
        q = queue<int>();// 큐 초기화

        // 진입차수가 0인거 넣기
        for(int i=1;i<=n;i++) if(!cnt[i]) q.push(i);

        // 진입할 수 있는게 없으면 IMPOSSIBLE 출력 
        if(Check_Impossible()){
            cout<<"IMPOSSIBLE"<<'\n';
            continue;
        }

        while(q.size()){
            int cur = q.front(); q.pop();
            ret.push_back(cur);

            for(int i=0;i<graph[cur].size();i++){
                int node = graph[cur][i];
                if(node == -1) continue;

                cnt[node]--;
                if(!cnt[node]) q.push(node); // 진입 차수가 0이 되면 push
            }
        }

        if(Check_Impossible()) cout<<"IMPOSSIBLE"<<'\n';
        else{
            for(int i=0;i<n;i++) cout<<ret[i]<<' ';
            cout<<'\n';
        }
    }
}