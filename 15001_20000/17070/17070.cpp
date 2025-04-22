#include<iostream>
#include<queue>
using namespace std;

struct Pos { int y,x; };

int dp[16][16][3];
int map[16][16];

//Range
int n; 
bool isAble(Pos pos, int state){

    if(0<=pos.y && pos.y<n && 0<=pos.x && pos.x<n && map[pos.y][pos.x]!=1){
        if(state==2){ //대각선이면 조건이 더 붙음 
            return map[pos.y][pos.x-1]!=1 && map[pos.y-1][pos.x]!=1;
        }else{
            return 1;
        }
    }
    return 0;
}
//State
int horizon[2][2]={{0,1},{1,1}}; //0
int vertical[2][2]={{1,0},{1,1}}; //1
int diag[3][2]={{0,1},{1,0},{1,1}};//2

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("input.txt","r",stdin);

    cin>>n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>map[i][j];

    //초기값 설정
    // for(int i=1;i<n;i++) dp[0][i][0]=1;
    dp[0][1][0]=1;

    Pos pos = {0,1};
    int State = 0;
    queue<pair<Pos,int> > q; //Pos, state 페어
    q.push(make_pair(pos,State));


    int currentCnt;
    while(!q.empty()){
        pos = q.front().first;
        State = q.front().second;
        currentCnt=dp[pos.y][pos.x][State];
        q.pop();

        Pos nextPos;
        int nextState;
        switch (State)
        {
            case 0: //horizon
                for(int i=0;i<2;i++){
                    nextPos.y = pos.y+horizon[i][0];
                    nextPos.x = pos.x+horizon[i][1];
                    nextState = (i==0?0:2);
                    if(!isAble(nextPos,nextState)) continue; //범위 확인 

                    dp[nextPos.y][nextPos.x][nextState]+=1;
                    q.push(make_pair(nextPos,nextState));
                }
                break;
            case 1: //vertical
                for(int i=0;i<2;i++){
                    nextPos.y = pos.y+vertical[i][0];
                    nextPos.x = pos.x+vertical[i][1];
                    nextState = i+1;
                    if(!isAble(nextPos,nextState)) continue; //범위 확인 

                    dp[nextPos.y][nextPos.x][nextState]+=1;
                    q.push(make_pair(nextPos,nextState));
                }
                break;
            case 2: //diag
                for(int i=0;i<3;i++){
                    nextPos.y = pos.y+diag[i][0];
                    nextPos.x = pos.x+diag[i][1];
                    nextState = i;
                    if(!isAble(nextPos,nextState)) continue; //범위 확인 
                    
                    dp[nextPos.y][nextPos.x][nextState]+=1;
                    q.push(make_pair(nextPos,nextState));
                }
                break;
        }

        // dp 출력
        // cout<<"CurretPos : "<< pos.y <<','<< pos.x <<" State: "<<State<< endl;
        // for(int k=0;k<3;k++){
        //     for(int i=0;i<n;i++){ 
        //         for(int j=0;j<n;j++) {        
        //             cout<<dp[i][j][k]<<' ';
        //         }
        //         cout<<endl;
        //     }
        //     cout<<endl;
        // }
    }

    int ret=0;
    for(int i=0;i<3;i++){
        ret+=dp[n-1][n-1][i];
    }
    cout<<ret<<'\n';

    
}