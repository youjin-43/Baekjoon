#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

struct Pos{ int y,x; };

char arr[5][6]; // \0포함 해서 6
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
bool isOK(int y,int x){return 0<=y && y<5 && 0<=x && x<5;}
Pos GetPos(int n){return {n/5,n%5};}

int ret=0; 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    // freopen("input.txt","r",stdin);

    for(int i=0;i<5;i++) cin>>arr[i];

    // 25C7구하기
    vector<int> vec(25,0);
    for(int i=0;i<7;i++) vec[24-i]=1;
    do{
        int cnt_S=0,cnt_Y=0;

        for(int i=0;i<25;i++){
            if(!vec[i]) continue;
            Pos p = GetPos(i);
            arr[p.y][p.x]=='Y'?cnt_Y++:cnt_S++;
        }

        if(cnt_S < cnt_Y) continue; // Y가 더 많으면 Pass

        // 모두 이어져있는지 확인 
        int v[5][5]={0,}; // visit
        stack<Pos> st;
        for(int i=0;i<25;i++){
            if(!vec[i]) continue;
            Pos p = GetPos(i);
            v[p.y][p.x]=1;
            
            if(!st.size()){
                st.push(p);
                v[p.y][p.x]++;
            }
        }

        int cnt=1; // 이어져 있는 갯수 
        while(st.size()){
            Pos curPos = st.top(); st.pop();
            for(int i=0;i<4;i++){
                int ny=curPos.y+dir[i][0],nx=curPos.x+dir[i][1];
                if(!isOK(ny,nx) || !v[ny][nx] || v[ny][nx]==2) continue; // 범위를 벗어났거나, 현재 고른  ,이미 넣은 경우

                v[ny][nx]++;
                st.push({ny,nx});
                cnt++;
            }
        }

        if(cnt==7) ret++; // 7개 모두 이어져 있으면 ret++
    }
    while(next_permutation(vec.begin(),vec.end()));

    cout<<ret<<'\n';
}