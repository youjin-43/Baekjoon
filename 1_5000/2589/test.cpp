//24.10.29(화ㅏ)
#include<iostream>
#include<queue>
using namespace std;

struct Pos { int y; int x; };
int m[50][50];
int h,w; 

bool isWithinRange(Pos p){
    return (0<=p.y && p.y<h && 0<=p.x && p.x<w);
}

// int mainVisit[50][50]={0,};
int move_[4][2]={{1,0},{-1,0},{0,-1},{0,1}};

int ret=0;
vector<Pos> reEstate;
void BFS(Pos p){
    int visit_[50][50]={0,};
    queue<Pos > q; //위치와 거리 쌍 
    q.push(p); 
    visit_[p.y][p.x]=1;


    Pos tmp;
    while(!q.empty()){
        Pos current = q.front(); 
        q.pop();

        int currentCnt=m[current.y][current.x];
        for(int i=0;i<4;i++){
            Pos next;
            next.y=current.y+move_[i][0];
            next.x=current.x+move_[i][1];
            if(isWithinRange(next) && !visit_[next.y][next.x] && m[next.y][next.x]==1){
                q.push(next); 
                m[next.y][next.x]=currentCnt+1;
                if(m[next.y][next.x]>ret){
                    tmp.y=next.y;
                    tmp.x=next.x;
                    ret=m[next.y][next.x];
                }
            }
        }
    }
    reEstate.push_back(tmp);
}


void BFS_second(Pos p){
    int visit_[50][50]={0,};
    queue<pair<Pos,int> > q; //위치와 거리 쌍 
    q.push(make_pair(p,0)); visit_[p.y][p.x]=1;

    while(!q.empty()){
        Pos current = q.front().first; 
        int cnt = q.front().second; ret=max(cnt,ret);
        q.pop();

        // cout<<current.y<<' '<<current.x<<' '<<cnt<<endl;

        for(int i=0;i<4;i++){
            Pos next;
            next.y=current.y+move_[i][0];
            next.x=current.x+move_[i][1];
            if(isWithinRange(next) && m[next.y][next.x] && !visit_[next.y][next.x]){
                q.push(make_pair(next,cnt+1)); visit_[next.y][next.x]=1;
                // cout<<next.y<<' '<<next.x<<endl;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);  

    // freopen("input.txt","r",stdin);
    cin>>h>>w;

    char tmp;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>tmp;
            if(tmp=='L'){
                m[i][j]=1;
            }
            
        }
    }

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(m[i][j]==1){
                Pos p; p.y=i; p.x=j;
                BFS(p);
            }
        }
    }
    ret--;


    for(int i=0;i<reEstate.size();i++){
        BFS_second(reEstate[i]);
    }

    cout<<ret<<'\n';
}