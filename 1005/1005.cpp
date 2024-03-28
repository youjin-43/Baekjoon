#include<iostream>
#include <vector>
#include <queue>
#include<deque>
#include <algorithm>
using namespace std;

bool cost_decrease(pair<int,int> &a,pair<int,int> &b){
    return a.second>b.second;
}

int main(){
    vector<vector<int>> graph_(1001); //idx 노드를 짓기위해 먼저지어햐 하는 노드들이 들어있음
    int check[1001]{};//idx노드가 지어졌는지
    int cnt[1001]{};//idx 노드가 가리키는 노드의 갯수(==이 다음에 지을 수 있는 노드의 갯수)

    int t;
    cin>>t;
    // int t=1;

    while(t--){
        int n,k;
        cin>>n>>k;

        // int n=4,k=4;
        
        int cost[1001];
        //node cost 입력 받기
        for(int i=0;i<n;i++){
            cin>>cost[i];
        }

        // int cost[5]={0,10, 1, 100, 10};

        // direct 그래프 그리기 -> idx 노드를 짓기위해 먼저지어햐 하는 노드들을 가리킴
        while(k--){
            int a,b;
            cin>>a>>b;
            graph_[b].push_back(a);
            cnt[a]++;
        }

        // graph_[2].push_back(1);
        // cnt[1]++;
        // graph_[3].push_back(1);
        // cnt[1]++;
        // graph_[4].push_back(2);
        // cnt[2]++;
        // graph_[4].push_back(3);
        // cnt[3]++;


        int ret=0;
        int goal;
        cin>>goal;
        // int goal=4;

        queue<int> buildList;
        deque<pair<int,int>> delayedNodes; //node, delay
        vector<pair<int,int>> prior_node;

        buildList.push(goal);

        while(true){

            //빌드할큐가 비어있다면 딜레이된게 있는지 확인
            if(!buildList.size()){ 

                //딜레이된것도 없다면 끝
                if(!delayedNodes.size()){
                    break;
                }
                //딜레이된게 있다면 큐에 추가
                else{
                    pair<int,int> node = delayedNodes.front();
                    cost[node.first]=node.second;
                    buildList.push(node.first);
                    delayedNodes.pop_front();
                }
          
            }

            int visitNode = buildList.front();
            buildList.pop();
            check[visitNode]=1;
            ret+=cost[visitNode];

            //딜레이되고있는 노드가 있다면 visit노드가 지어진 만큼 딜레이 감소
            if(delayedNodes.size()){
                for(int i=0;i<delayedNodes.size();i++){
                    delayedNodes[i].second -=cost[visitNode];
                    if(delayedNodes[i].second<=0){
                        //건설완료
                        cost[delayedNodes[i].first]=delayedNodes[i].second;
                        buildList.push(delayedNodes[i].first);
                        delayedNodes.pop_front();
                    }
                }
            }

            //visitNode와 연결된 노드들 cnt 감소
            for(int i=0;i<graph_[visitNode].size();i++){
                int node = graph_[visitNode][i];
                cnt[node]--;

                if(!cnt[node]){//node의 cnt가 0이라면 실행 
                    prior_node.push_back(make_pair(node,cost[node]));
                }
            }
            
            //전에 지어져야하는 노드가 여려개라면 그중 가장 큰 코스트가 드는걸 딜레이에 추가
            if(prior_node.size()>1){
                sort(prior_node.begin(),prior_node.end(),cost_decrease);//코스트기준으로 내림차순으로 결정

                delayedNodes.push_back(prior_node[0]);//코스트가 가장 높은 노드는 딜레이 노드에 넣어주고
                //나머지는 build리스트에 넣어줌 
                for(int i=1; i<prior_node.size();i++){
                    buildList.push(prior_node[i].first);
                }
            }
            //1개면 그냥 buildList에 추가
            else if(prior_node.size()==1){
                buildList.push(prior_node[0].first);
            }
            //없다면 그냥 끝
            else{
                
            }

            //다음 노드에서 수행하기 위해 prior노드 벡터 초기화
            prior_node.clear();
        }


        cout<<ret<<endl;

    }
}

