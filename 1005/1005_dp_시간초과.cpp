/*시간 초과남*/

#include<iostream>
#include<stack>
#include<queue>
using namespace std;


int main(){

    int t;
    cin>>t;

    while(t--){
        vector<vector<int>> pre_graph(1001); //idx 노드를 짓기위해 먼저지어햐 하는 노드들을 가리킴
        vector<vector<int>> post_graph(1001); //idx 노드다음에 지을 수 있는 노드를 가리킴

        int n,k;
        cin>>n>>k;
        
        int cost[1001];
        //node cost 입력 받기
        for(int i=1;i<=n;i++){
            cin>>cost[i];
        }

        int cnt[1001]{}; //idx전에 지어야야하는 노드의 갯수

        // direct 그래프 그리기
        while(k--){
            int a,b;
            cin>>a>>b;
            post_graph[a].push_back(b);
            pre_graph[b].push_back(a);
            cnt[b]++;
        }

        int goal;
        cin>>goal;


        //탐색순서 정하기
        stack<int> stack_;
        queue<int> visit_list;

        stack_.push(goal);

        while(!stack_.empty()){
            int node = stack_.top();
            //탑 노드 전에 와야하는 노드가 없다면
            if(cnt[node]==0){
                stack_.pop();
                visit_list.push(node);

                //연결된 cnt 감소
                for(int i=0;i<post_graph[node].size();i++){
                    cnt[post_graph[node][i]]--;
                }
            }else{
                //전에 와야하는 노드가 있으면 push
                for(int i=0;i<pre_graph[node].size();i++){
                    stack_.push(pre_graph[node][i]);
                }
            }
        }

        // while(!visit_list.empty()){
        //     cout<<visit_list.front()<<" ";
        //     visit_list.pop();
        // }
        // cout<<endl;



        //표 채우기
        while(!visit_list.empty()){
            int node = visit_list.front();
            
            //전에 지어져야 하는 노드가 없다면
            if(pre_graph[node].size()==0){
                // ret[node]=cost[node];
            }
            //전에 지어져야 하는 노드가있으면 그 중 가장 큰 값 + 자기 자신 짓는데 걸리는 cost
            else{
                int max=cost[pre_graph[node][0]];

                for(int j=1;j<pre_graph[node].size();j++){
                    if(max<cost[pre_graph[node][j]]){
                        max = cost[pre_graph[node][j]];
                    }
                }
                cost[node]+=max;
            }
            visit_list.pop();

            // cout<<"ret------------"<<endl;
            // for(int i=1;i<=n;i++){
            //     cout<<i<<" : "<<cost[i]<<endl;
            // }
        }


        cout<<cost[goal]<<endl;
    }

}


