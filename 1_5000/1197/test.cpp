/*24.3.25 월 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(){


    int v=3,e=3;
    vector<vector<pair<int,int>>> gragh_(v+1);
    gragh_[1].push_back(make_pair(2,1));
    gragh_[2].push_back(make_pair(1,1));

    gragh_[2].push_back(make_pair(3,2));
    gragh_[3].push_back(make_pair(2,2));

    gragh_[1].push_back(make_pair(3,3));
    gragh_[3].push_back(make_pair(1,3));

    //그래프 출력
    cout<<"----그래프 출력-----"<<endl;
    for(int i=1;i<=v;i++){
        cout<<i<<" : ";
        for(int j=0;j<gragh_[i].size();j++){
            cout<<"("<<gragh_[i][j].first<<","<<gragh_[i][j].second<<") ";
        }
        cout<<endl;
    }
    cout<<"--------"<<endl;

    int distance[v+1];
    int check[v+1];

    for(int i=1;i<=v;i++){
        distance[i]=INT_MAX;
        check[i]=0;
    }

    int loop = v-1;
    int ret=0;
    int start_vertex = 1;
    check[start_vertex]=1;

    while(loop--){
        int vertex,weight;
        for(int i=0;i<gragh_[start_vertex].size();i++){

            vertex = gragh_[start_vertex][i].first;

            //이미 방문한 노드라면 안함
            if(check[vertex]){
                continue;
            }
            else{
                //distance랑 nearest update
                weight = gragh_[start_vertex][i].second;

                if(distance[vertex]>weight){
                    distance[vertex] = weight;
                }
            }
        }

        //distance가 제일 작은 노드로 감
        int tmp = INT_MAX;
        int next_node;

        for(int i=2;i<=v;i++){
            if(check[i]){
                continue;
            }else{
                if(distance[i]<tmp){
                    tmp = distance[i];
                    next_node=i;
                }
            }
        }
        ret+=distance[next_node];
        check[next_node]=1;
        start_vertex=next_node;
    }


cout<<ret<<endl;


}