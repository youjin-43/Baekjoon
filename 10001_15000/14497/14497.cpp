//24.7.19 금 14497 주난의 난

#include<iostream>
#include<queue>
#include<stack>
#include<string>
using namespace std;

struct pos
{
    int y,x;

    pos(int a,int b){
        y=a; x=b;
    }
};

int n,m;//(1 ≤ N, M ≤ 300)

string room[300];
int check[300][300]={0,};
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}}; //상하좌우

queue<pos> q;
stack<pos> s;

int isFind=0;

void go(int start_y, int start_x){

    for(int i=0;i<4;i++){
        int y = start_y+dir[i][0];
        int x = start_x+dir[i][1];

        if(0<=y && y<n && 0<=x && x<m && check[y][x]==0){

            check[y][x]=1;

            //1인경우 -> 큐에 넣음
            if(room[y][x]=='1'){
                pos tmp(y,x);
                q.push(tmp);
            }
            //0인경우
            else if(room[y][x]=='0'){
                pos tmp(y,x);
                s.push(tmp);
            }
            //# 인경우 == 초콜릿을 찾은 경우
            else{
                isFind=1;
                return;
            }
            
        }
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    // freopen("input.txt", "r", stdin);

    cin>>n>>m;
    int start_y,start_x;
    cin>>start_y>>start_x;
    start_y--; start_x--;

    int end_y,end_x;
    cin>>end_y>>end_x;

    for(int i=0;i<n;i++){
        cin>>room[i];
    }

    //room 출력
    // for(int i=0;i<n;i++){
    //     cout<<room[i]<<endl;
    // }cout<<endl;


    pos tmp(start_y,start_x);
    q.push(tmp);
    int day=1;
    int day_size=1;

    while(!q.empty()){
        start_y = q.front().y;
        start_x = q.front().x;        

        check[start_y][start_x]=1;
        go(start_y,start_x);

        while(!s.empty()){
            start_y = s.top().y;
            start_x = s.top().x;
            s.pop();
            go(start_y,start_x);
        }

        if(isFind) break;

        q.pop();
        day_size--;

        if(day_size==0){
            day_size = q.size();
            day++;
        }    
    }

    cout<<day<<'\n';


}