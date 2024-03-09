/*2023.12.2(토) 1753_최단경로.cpp
방향그래프 / 시작점에서 다른 모든 정점으로의 최단 경로를 구하시오
모든 간선의 가중치는 10 이하의 자연수
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int main(){
    int distance[200001];

    int vertex,edge; //1≤V≤20,000, 1≤E≤300,000
    int start; //시작 정점
    int u,v,w; //u에서 v로 가는 가중치 w(≤10)인 간선

    cin>>vertex>>edge>>start;

    vector<pair<int,int>> edge_list[vertex+1]; //인접리스트

    //같은 엣지가 있다면 가중치가 제일 작은것만 저장
    for(int i=0;i<edge;i++){
        cin>>u>>v>>w;

        int tmp = edge_list[u].size()-1;
        while(tmp>=0){
            if(edge_list[u][tmp].first==v){
                break;
            }
            tmp--;
        }

        if(tmp>=0){
            if(edge_list[u][tmp].second>w){
                edge_list[u].erase(edge_list[u].begin()+tmp);
                edge_list[u].push_back(make_pair(v,w));
            }

        }else{
            edge_list[u].push_back(make_pair(v,w));
        }
    }


    /*디버깅*/
    // int distance[6];

    // int vertex=5;
    // int edge=8; //1≤V≤20,000, 1≤E≤300,000
    // int start =1; //시작 정점
 
    // vector<pair<int,int>> edge_list[vertex+1]; //인접리스트
    // edge_list[1].push_back(make_pair(2,1));
    // edge_list[1].push_back(make_pair(3,3));
    // edge_list[1].push_back(make_pair(5,3));
    // edge_list[2].push_back(make_pair(3,4));
    // edge_list[2].push_back(make_pair(4,5));
    // edge_list[2].push_back(make_pair(5,1));
    // edge_list[3].push_back(make_pair(4,6));
    // edge_list[5].push_back(make_pair(1,1));

    // // 출력
    // for(int i=1;i<=vertex;i++){
    //     cout<<i<<" : ";
    //     int tmp = edge_list[i].size();
    //     while(tmp--){
    //         cout<<edge_list[i][tmp].first<<edge_list[i][tmp].second<<" ";
    //     }
    //     cout<<endl;
    // }

    /*find_shortestPath*/

    //initialize
    for(int i=1;i<=vertex;i++){
        distance[i]=INT_MAX;
    }
    distance[start]=0;
    for(int i=0;i<edge_list[start].size();i++){
        int end = edge_list[start][i].first;
        int weight = edge_list[start][i].second;

        distance[end] = weight;
    }




    
    int v_near;
    //start
    bool loop_end = true;
    while(loop_end){//모든 노드에서 진행
        loop_end = false;
        int min= INT_MAX;
        for(int i=1;i<=vertex;i++){
            if(0<distance[i] && distance[i]<min){//아직 방문하지 않았고 인접한경우
                min=distance[i];
                v_near=i;
                loop_end = true;
            }
            
        }
        for(int i=0; i<edge_list[v_near].size();i++){
            int  end = edge_list[v_near][i].first;
            int weight = edge_list[v_near][i].second;

            if(distance[v_near]+weight<distance[end]){
                distance[end]=distance[v_near]+weight;
            }
        }
        if(loop_end){
            distance[v_near]*=-1;
        }

    }

    //출력
    for(int i=1;i<=vertex;i++){
        if(distance[i] == INT_MAX){
            cout<<"INT"<<endl;
        }
        else{
            cout<<-distance[i]<<endl;
        }

    }


}