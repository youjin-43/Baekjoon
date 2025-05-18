// 노드가 30개인데 배열로 하면 깊이가 30이면 메모리가 ㅎㄷㄷ -> 그래프 이용 
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> list(26);

// 전위 (루트) (왼쪽 자식) (오른쪽 자식)
void PreOrder(int idx){
    cout<<(char)('A'+idx);

    //base
    if(!list[idx][0] && !list[idx][1]) return;
    
    //recursive
    if(list[idx][0]) PreOrder(list[idx][0]);
    if(list[idx][1]) PreOrder(list[idx][1]);
}

// 중위 (왼쪽 자식) (루트) (오른쪽 자식)
void InOrder(int idx){
    //base
    if(!list[idx][0] && !list[idx][1]){
        cout<<(char)('A'+idx); return;
    }
    
    //recursive
    if(list[idx][0]) InOrder(list[idx][0]);
    cout<<(char)('A'+idx);
    if(list[idx][1]) InOrder(list[idx][1]);
}

// 후위 (왼쪽 자식) (오른쪽 자식) (루트)
void PostOrder(int idx){
    //base
    if(!list[idx][0] && !list[idx][1]){
        cout<<(char)('A'+idx); return;
    }

    //recursive
    if(list[idx][0]) PostOrder(list[idx][0]);
    if(list[idx][1]) PostOrder(list[idx][1]);
    cout<<(char)('A'+idx);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("input.txt","r",stdin);

    // 입력 받기 
    int n; cin>>n;
    char parent,child_1,child_2;
    while(n--){
        cin>>parent>>child_1>>child_2;
        if(child_1 != '.') list[parent-'A'].push_back(child_1-'A');
        else list[parent-'A'].push_back(0);
        if(child_2 != '.') list[parent-'A'].push_back(child_2-'A');
        else list[parent-'A'].push_back(0);
    }

    // 출력 
    PreOrder(0); cout<<'\n';
    InOrder(0); cout<<'\n';
    PostOrder(0); cout<<'\n';
}