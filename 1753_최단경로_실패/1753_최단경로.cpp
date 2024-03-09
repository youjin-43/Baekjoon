/*2023.11.30(목)) 1753_최단경로.cpp
방향그래프 / 시작점에서 다른 모든 정점으로의 최단 경로를 구하시오
모든 간선의 가중치는 10 이하의 자연수

- base case : u = 1 일때 >> 거리 : 그냥 w

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> v1,vector<int> v2){
    if(v1[0]==v2[0]){
        if(v1[1]==v2[1]) return v1[2]<v2[2];
        else return v1[1]<v2[1];
    }
    else{
        return v1[0]<v2[0];
    }

}

int main(){
    // int distance[200000];
    // int pre_v[200000];
    // int vertex,edge; //1≤V≤20,000, 1≤E≤300,000
    // int k; //시작 정점
    // int u,v,w; //u에서 v로 가는 가중치 w(≤10)인 간선

    // cin>>vertex>>edge>>k;

    // vector<vector<int>> edge_list(edge,vector<int>(3));
    // for(int i=0;i<edge;i++){
    //     cin>>edge_list[i][0]>>edge_list[i][1]>>edge_list[i][2];
    // }
    
    /*test case*/
    int edge = 7;
    vector<vector<int>> edge_list(edge,vector<int>(3));
    edge_list = {{5,1,1},{5,1,2},{1,3,3},{2,3,4},{2,4,5},{3,4,6},{3,4,2}};
    sort(edge_list.begin(),edge_list.end(),cmp);

    //가중치가 제일 작은거만 남기고 다 지워줌
    int i=edge-1;
    while(i){
        if(edge_list[i][0]==edge_list[i-1][0] && edge_list[i][1]==edge_list[i-1][1]){
            edge_list.erase(edge_list.begin()+i);
            edge--;
        }
        i--;
    }

    edge_list[3][2]=9;

    //print
    cout<<"print"<<endl;
    for(int i=0;i<edge;i++){
        for(int j=0;j<3;j++){
            cout<<edge_list[i][j]<<" ";
        }
        cout<<endl;
    }
  
}