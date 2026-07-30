#include<iostream>
using namespace std;
#define SIZE 101

struct Pos{int y,x;};

int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}}; // 반시계방향 

int n,ret=0; // 보드의 크기, 지난 시간
int board[SIZE][SIZE]={1,}; // 1~4는 뱀(방향을 나타냄 -1 해서 사용) / 5은 사과


bool IsOK(int y,int x){
    return 0<=y && y<n && 0<=x && x<n;
}

void PrintBoard(){
    return;
    cout<<"ret : "<<ret<<" ----------------"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)cout<<board[i][j]<<' ';
        cout<<endl;
    }
    cout<<endl<<endl;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt","r",stdin);

    int k,l; cin>>n>>k;

    // 사과 위치
    for(int i=0,a,b;i<k;i++){
        cin>>a>>b;
        board[a-1][b-1]=5;
    }

    PrintBoard();

    cin>>l;
    int cd,x;
    char d;

    // 뱀 정보
    Pos s{0,0},e{0,0};
    l++;
    while(1){
        if(l>1){cin>>x>>d;l--;}
        int duration = x-ret;
        while(1){
            if(l) duration--;
            ret++; //시간 증가

            cd=board[s.y][s.x]-1;
            int ny = s.y+dir[cd][0]; 
            int nx = s.x+dir[cd][1];

            //벽이나 자기 자신에 충돌했는지(사과가 아닌 양수인지) 확인 
            if(!IsOK(ny,nx) || (board[ny][nx]!=5 && board[ny][nx])){
                cout<<ret<<'\n';
                return 0;
            }
            
            // 머리 전진
            bool is = board[ny][nx]!=5;
            board[ny][nx]=board[s.y][s.x]; // 방향 표시
           
            s.y = ny, s.x = nx;// 머리 위치 갱신 

            // 사과가 없으면 꼬리는 없어짐(꼬리 갱신)
            if(is){
                int cur_d = board[e.y][e.x]-1;
                ny = e.y + dir[cur_d][0];
                nx = e.x + dir[cur_d][1];

                board[e.y][e.x]=0; // 기존 꼬리는 없어지고
                // 꼬리 갱신 
                e.y =ny,e.x =nx;
            }
            PrintBoard();
            if(!duration)break;   
        }
        

        if(!l) continue;

        // 방향 틀기 
        if(d=='L'){ 
            // 왼쪽으로 틀기
            board[s.y][s.x]--;
            if( board[s.y][s.x]==0) board[s.y][s.x]=4;
        }
        else{
            // 오른쪽
            board[s.y][s.x]++;
            if( board[s.y][s.x]==5) board[s.y][s.x]=1;
        }
        PrintBoard();
    }
    cout<<ret<<'\n';

}