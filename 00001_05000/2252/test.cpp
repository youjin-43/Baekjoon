/*24.3.22 2252 줄세우기*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int main(){
    int n=4,m=2;

    int check[32000] ={0,};
    vector<pair<int,int>> edge; // first -> second
    vector<vector<int>> gragh(n);
    vector<int> ret;


    edge.push_back(make_pair(4,2));
    edge.push_back(make_pair(3,1));
    

    //그래프 그리기
    for(int i=0;i<edge.size();i++){
        gragh[edge[i].first-1].push_back(edge[i].second-1);
    }

    //그래프 출력
    cout<<"----그래프----"<<endl;
    for(int i=0;i<gragh.size();i++){
        cout<<i<<"(size:"<<gragh[i].size()<<") : ";
        
        for(int j=0;j<gragh[i].size();j++){
            
            cout<<gragh[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<"------------"<<endl;


    queue<int> queue_;

    //모든 노드에 대하여 수행
    for(int i=0;i<n;i++){

        cout<<"i : "<<i<<endl;

        //방문했다면 패스
        if(check[i]){
            continue;
        }else{
            queue_.push(i); //i 노드부터 탐색 시작
            check[i]++;//노드 체크    

            //큐의 사이즈가 빌 때까지 실행
            while(queue_.size()){
                int node = queue_.front(); // 프론트 노드가져와서
                ret.push_back(node);//ret에 추가해주고
                queue_.pop();//큐에서 삭제

                cout<<"node : "<<node<<endl;

                // //ret출력
                // cout<<"ret : ";
                // for(int i=0;i<ret.size();i++){
                //         cout<<ret[i]<<' ';
                //     }
                // cout<<endl; 

                //이미 나왔었는지 체크해가면서 연결된 노드들 큐에 추가
                for(int k=0;k<gragh[node].size();k++){
                    //방문하지 않은 노드라면 -> 큐에 추가
                    cout<<check[gragh[node][k]]<<endl;
                    if(!check[gragh[node][k]]){
                        queue_.push(gragh[node][k]);
                        check[gragh[node][k]]++;
                        cout<<"큐에 추가된 노드 : "<< gragh[node][k]<<endl;
                    }
                }
            }
        }

    }



    //ret출력
    for(int i=0;i<ret.size();i++){
        cout<<ret[i]<<' ';
    }
    cout<<endl;

}


