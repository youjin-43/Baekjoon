/*2023.11.30(목)) 1753_최단경로.cpp
방향그래프 / 시작점에서 다른 모든 정점으로의 최단 경로를 구하시오
모든 간선의 가중치는 10 이하의 자연수
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int main(){
    // int distance[200001];
    // // int pre_v[200001];

    // int vertex,edge; //1≤V≤20,000, 1≤E≤300,000
    // int start; //시작 정점
    // int u,v,w; //u에서 v로 가는 가중치 w(≤10)인 간선

    // cin>>vertex>>edge>>start;

    // vector<pair<int,int>> edge_list[edge]; //인접리스트

    // //같은 엣지가 있다면 가중치가 제일 작은것만 저장
    // for(int i=0;i<edge;i++){
    //     cin>>u>>v>>w;

    //     int tmp = edge_list[u].size()-1;
    //     while(tmp>=0){
    //         if(edge_list[u][tmp].first==v){
    //             break;
    //         }
    //         tmp--;
    //     }

    //     if(tmp>=0){
    //         if(edge_list[u][tmp].second>w){
    //             edge_list[u].erase(edge_list[u].begin()+tmp);
    //             edge_list[u].push_back(make_pair(v,w));
    //         }

    //     }else{
    //         edge_list[u].push_back(make_pair(v,w));
    //     }
    // }


    /*디버깅 test_1*/
    // int distance[6];
    // int pre_v[6];

    // int vertex=5;
    // int edge=6; //1≤V≤20,000, 1≤E≤300,000
    // int start =1; //시작 정점
 
    // vector<pair<int,int>> edge_list[edge]; //인접리스트
    // edge_list[1].push_back(make_pair(2,2));
    // edge_list[1].push_back(make_pair(3,3));
    // edge_list[2].push_back(make_pair(3,4));
    // edge_list[2].push_back(make_pair(4,5));
    // edge_list[3].push_back(make_pair(4,6));
    // edge_list[5].push_back(make_pair(1,1));

    //출력
    // for(int i=0;i<edge;i++){
    //     cout<<i<<" : ";
    //     int tmp = edge_list[i].size();
    //     while(tmp--){
    //         cout<<edge_list[i][tmp].first<<edge_list[i][tmp].second<<" ";
    //     }
    //     cout<<endl;
    // }


    /*디버깅 test_1*/
    int distance[3];
    int pre_v[3];

    int vertex=2;
    int edge=1; //1≤V≤20,000, 1≤E≤300,000
    int start =1; //시작 정점
 
    vector<pair<int,int>> edge_list[edge+1]; //인접리스트
    edge_list[1].push_back(make_pair(2,3));

    //인접리스트 출력
    for(int i=0;i<edge;i++){
        cout<<i<<" : ";
        int tmp = edge_list[i].size();
        while(tmp--){
            cout<<edge_list[i][tmp].first<<edge_list[i][tmp].second<<" ";
        }
        cout<<endl;
    }

    /*find_shortestPath*/

    //initialize
    for(int i=1;i<=vertex;i++){
        distance[i]=INT_MAX;
    }
    // pre_v[start]=start;
    distance[start]=0;

    //start
    while(true){
        // distance[start]*=-1;

        int i = edge_list[start].size()-1;
        int min_distance=INT_MAX;
        int min_idx;
        bool loop_end=true;

        for(i; i>=0;i--){
            int node = edge_list[start][i].first;
            loop_end=false;

            if(distance[node]>0 && distance[node] > (edge_list[start][i].second + distance[start])){
                // pre_v[node]=start;
                distance[node]=edge_list[start][i].second + distance[start];

                if(min_distance>distance[node]){
                    min_distance=distance[node];
                    min_idx=node;
                }
            }else{
                loop_end=true;
            }
        }
        if(loop_end){
            break;
        }else{
            start = min_idx;
        }

    }

    for(int i=1;i<=vertex;i++){
        if(distance[i] == INT_MAX){
            cout<<"INF"<<endl;
        }
        else{
            cout<<distance[i]<<endl;
        }

    }


}