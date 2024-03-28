
#include<iostream>
#include<stack>
#include<queue>
using namespace std;


int main(){

    int t;
    cin>>t;

    while(t--){
        vector<vector<int>> pre_graph(1001); //idx 노드를 짓기위해 먼저지어햐 하는 노드들을 가리킴
        int check[1001]{};

        int n,k;
        cin>>n>>k;

        
        int cost[1001]{};
        //node cost 입력 받기
        for(int i=1;i<=n;i++){
            cin>>cost[i];
        }

        int cnt[1001]{}; //idx전에 지어야야하는 노드의 갯수

        // direct 그래프 그리기
        while(k--){
            int a,b;
            cin>>a>>b;
            pre_graph[b].push_back(a);
            cnt[b]++;
        }

        int goal;
        cin>>goal;

        stack<int> stack_;
        stack_.push(goal);

        while(!stack_.empty()){
            int node = stack_.top();

            for(int i=0;i<pre_graph[node].size();i++){
                //이미 지었다면
                if(check[pre_graph[node][i]]){
                    cnt[node]--;
                }else{
                    stack_.push(pre_graph[node][i]);
                }
            }

            //진입 노드가 다 지어졌다면
            if(cnt[node]==0){
                if(pre_graph[node].size()){
                    int max=cost[pre_graph[node][0]];

                    for(int j=1;j<pre_graph[node].size();j++){
                        if(max<cost[pre_graph[node][j]]){
                            max = cost[pre_graph[node][j]];
                        }
                    }
                    cost[node]+=max;
                }
                check[node]=1;//지어줌
                stack_.pop();
            }
            

            // cout<<"ret------------"<<endl;
            // for(int i=1;i<=n;i++){
            //     cout<<i<<" : "<<cost[i]<<endl;
            // }
        }
        
        cout<<cost[goal]<<endl;
    }

}


