#include<iostream>
#include<stack>
#include <cstring>
using namespace std;

typedef struct Pos{int y,x;} pos;
pos dir[4]= {{1,0},{-1,0},{0,-1},{0,1}}; // 상,하,좌,우 

int n,m;
int nums[100][100],visit_[100][100];

bool IsIn(int y, int x){
    if(0<=y && y<m && 0<=x && x<n) return 1;
    return 0;
}

bool Check(int k, int a, int b, int c){
    if(k==a || k==b || k==c) return 1;
    return 0;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt","r",stdin);

    // 입력 받기 
    cin>>n>>m;
    for(int i=0;i<m;i++)for(int j=0;j<n;j++)cin>>nums[i][j];

    for(int a=0;a<10;a++)for(int b=a;b<10;b++)for(int c=b;c<10;c++){
        // 각 시작지점에서 DFS
        for(int i=0;i<n;i++){
            if(!Check(nums[0][i],a,b,c)) continue;

            stack<pos> st;
            memset(visit_, 0, sizeof(visit_));
            st.push({0,i}); visit_[0][i]=1;
            while(st.size()){
                pos c_pos = st.top(); st.pop();

                for(pos d : dir){
                    pos tmp = {c_pos.y+d.y, c_pos.x+d.x};

                    // 범위를 벗어났거나 가고자하는 번호가 아니거나 이미 방문했다면  pass
                    if(!IsIn(tmp.y,tmp.x) || !Check(nums[tmp.y][tmp.x],a,b,c) || visit_[tmp.y][tmp.x]) continue; 

                    // a,b,c 조합으로 끝에 도달했다면 출력하고 종료 
                    if(tmp.y == m-1){
                        if(a==b && b==c) cout<<"0 0 0"<<'\n';
                        else if (a==b || b==c) cout<<"0 "<<a<<' '<<c<<'\n';
                        else cout<<a<<' '<<b<<' '<<c<<'\n';
                        exit(0);   
                    }
                    st.push(tmp);
                    visit_[tmp.y][tmp.x]=1;   
                }
            }
        }
    }   
    cout<<"-1 -1 -1"<<'\n';
}