/*시간 초과남*/

#include<iostream>
#include<stack>
#include<queue>
using namespace std;


int main(){

    int t;
    cin>>t;

    while(t--){
        vector<vector<int>> post_graph(1001); //idx 노드다음에 지을 수 있는 노드를 가리킴

        int n,k;
        cin>>n>>k;
        
        int cost[1001];
        int ret[1001];
        //node cost 입력 받기
        for(int i=1;i<=n;i++){
            cin>>cost[i];
            ret[i]=cost[i];
        }

        int cnt[1001]{}; //idx전에 지어야야하는 노드의 갯수

        // direct 그래프 그리기
        while(k--){
            int a,b;
            cin>>a>>b;
            post_graph[a].push_back(b);
            cnt[b]++;
        }

        int goal;
        cin>>goal;

        queue<int> visit_list;

        for(int i=1;i<=n;i++){
            if(cnt[i]==0){
                visit_list.push(i);
            }
        }

        while(!visit_list.empty()){
            int node = visit_list.front();
            visit_list.pop();
            for(int i=0;i<post_graph[node].size();i++){
                int next_node = post_graph[node][i];
                if(ret[next_node]<ret[node]+cost[next_node]){
                    ret[next_node]=ret[node]+cost[next_node];
                }
                cnt[next_node]--;
                if(!cnt[next_node]){
                    visit_list.push(next_node);
                }
            }
            
        }
        cout<<ret[goal]<<endl;

    }
}


