/*11725 트리의 부모찾기 
2023.12.2(토)
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int tree[100001]={0,};
    bool check[100001]={0,};
    int n;
    cin>>n;

    vector<vector<int>> list(n+1);

    //입력받기
    int a,b;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        list[a].push_back(b);
        list[b].push_back(a);        
    }

    /*부모찾기*/
    //initailiaze
    tree[1]=1;
    check[1]=1;

    int idx = 1;
    int node = 1;
    n--; // 이미 1은 넣었으니까
    while(n){//n개 노드의 위치를 찾아줘야함
        for(int i=0; i<list[node].size();i++){
            int near_node = list[node][i];
            if(check[near_node]){//인접한 노드가 방문한적 있다면
                continue;
            }
            //방문한적이 없다면
            check[near_node]=1;//체크해주고
            if(tree[idx*2]){//왼쪽자식이 이미 있다면 오른쪽 자식에 넣음
                tree[idx*2+1]=near_node; 
                n--;
            }
            else{//왼쪽 자식이 없으면 왼쪽 자식으로
                tree[idx*2]=near_node; 
                n--;
            }
        }
        idx++;
        node = tree[idx];
        while(!node){
            idx++;
            node = tree[idx];
        }
        
    }


    /*부모 출력*/
    

}