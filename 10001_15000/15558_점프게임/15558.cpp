// 15558 점프게임
// 메모리제이션 + 큐

#include<iostream>
#include<queue>
#include<climits>
#include<algorithm>
#include<string>
#define MAX 100'001
using namespace std;

int B[2][MAX];
int n;

void isClear(int pos){
    if(pos>n){
        cout<<1<<'\n';
        exit(0);
    };
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int k; cin>>n>>k; //  1 ≤ N, k ≤ 100,000
    for(int i=0,tmp;i<2;i++){
        string str; cin>>str;
        for(int j=0;j<str.size();j++){
            if(str[j]=='1')B[i][j+1]=INT_MAX; // 갈 수 있는 곳이라면 최대값으로 초기화 -> 이후 최솟값으로 갱신해 나갈것 
            else B[i][j+1]=0;
        }
    }
    B[0][1]=1; // 왼쪽 줄의 1번 칸은 항상 안전한 칸

    queue<pair<int,int>> q; // 현재 위치, 현재 줄
    q.push({1,0}); // 0번째줄 1번에서 시작 

    while(!q.empty()){
        int pos=q.front().first;
        int line=q.front().second; 
        q.pop();

        // 앞으로 한칸
        isClear(pos+1); 
        if(B[line][pos+1]){ // 0이 아닐떄(위험한 칸이 아닐 때) 수행
            if(B[line][pos+1]>B[line][pos]+1){
                B[line][pos+1] =B[line][pos]+1;
                q.push({pos+1,line});
            }
        }

        // 뒤로 한칸
        if(pos-1>=1 && B[line][pos-1]){
            if(B[line][pos-1]>B[line][pos]+1 && B[line][pos]+1<=pos-1){
                B[line][pos-1] = B[line][pos]+1;
                q.push({pos-1,line}); 
            }
        }

        // 건너편으로
        isClear(pos+k);
        if(B[(line+1)%2][pos+k]){
            if(B[(line+1)%2][pos+k]>B[line][pos]+1){
                B[(line+1)%2][pos+k]=B[line][pos]+1;
                q.push({pos+k,(line+1)%2});
            }
        }
    }
    cout<<0<<'\n';
}