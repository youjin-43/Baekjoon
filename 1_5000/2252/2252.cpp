/*24.3.22 2252 줄세우기*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> gragh(n+1);
    int edge_cnt[n+1];
    bool check[n+1];
    vector<int> ret;

    for(int i=0;i<=n;i++){
        edge_cnt[i]=0;
        check[i]=0;
    }

    int a,b;
    while(m--){
        cin>>a>>b;  
        gragh[a].push_back(b);
        edge_cnt[b]++;
    }

    //그래프 출력
    // cout<<"----그래프----"<<endl;
    // for(int i=1;i<gragh.size();i++){
    //     cout<<i<<"(size:"<<gragh[i].size()<<") : ";
    //     for(int j=0;j<gragh[i].size();j++){         
    //         cout<<gragh[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    // cout<<"------------"<<endl;


    queue<int> queue_;

    //간선이 0인것들(앞에 먼저 와야하는게 없는것들) 큐에 넣기
    for(int i=1;i<=n;i++){
        // cout<<"edge_cnt["<<i<<"] :"<<edge_cnt[i]<<endl;
        if(!edge_cnt[i]){
            queue_.push(i);
            check[i]=1;
            // cout<<i<<" is pushed"<<endl;
        }
    }

    //큐가 빌 때까지 실행
    while(queue_.size()){
        int node = queue_.front(); // 프론트 노드가져와서
        ret.push_back(node);//ret에 추가해주고
        queue_.pop();//큐에서 삭제

        // cout<<"node : "<<node<<" gragh[node].size() :"<<gragh[node].size()<<endl;

        //노드와 연결된 노드들 엣지 하나씩 줄이기
        for(int i=0; i< gragh[node].size();i++){
            int tmp = gragh[node][i];
            edge_cnt[tmp]--;

            //간선의 갯수가 0이 되면 큐에 넣기
            if(!edge_cnt[tmp] && !check[tmp]){
                queue_.push(tmp);
                check[tmp]=1;
                // cout<<tmp<<" is pushed"<<endl;
            }
        }

    }

        //ret출력
        // cout<<"ret : ";
        for(int i=0;i<ret.size();i++){
                cout<<ret[i]<<' ';
            }
        cout<<endl; 

}



