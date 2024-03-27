/*24.03.27 비숍 - 완전 복사로 그냥 돌리기*/

#include <iostream>
using namespace std;

class Board{
    public :
    int **board;
    int size;

    Board(int n){
        cout<<"보드 생성!"<<endl;
        size=n;
        board = new int*[size];
        for(int i=0;i<n;i++){
            board[i] = new int[size];
        }
    }

    ~Board(){
        cout<<"보드 소멸!"<<endl;
        for(int i=0;i<size;i++){
            delete[] board[i];
        }
        delete[] board;
    }
};

int n=5;

bool check_bound(int a, int b){
    if( 0<=a&& a<n && 0<=b && b<n){
        return true;
    }
    else{
        return false;
    }
}

int loop(Board board,int start_i,int start_j){
    int ret=0;
    
    //비숍을 배치할 수 있으면 우선 배치
    for(int i=start_i;i<n;i++){
        for(int j=start_j;j<n;j++){

            //비숍을 배치할 수 없다면
            if(board.board[i][j] != 1){
                continue;
            }
            //배치할 수 있다면 일단 배치
            else{
                ret++; 
                board.board[i][j]=2; // 비숍 배치

                // cout<<i<<","<<j<<"에 비숍 배치"<<endl;

                //4방으로 진행하며 배치된 비숍때문에 배치할 수 없는 곳 표시
                int tmp=1;

                while(tmp<n ){
                    //체스판 안에 있고 배숍을 배치할 수 있는 자리라면 실행
                    if(check_bound(i+tmp,j+tmp) && board.board[i+tmp][j+tmp]==1){ //오른쪽 아래방향
                        board.board[i+tmp][j+tmp]=3;
                        // cout<<i+tmp<<","<<j+tmp<<" = 3"<<endl;
                    }
                    
                    if(check_bound(i+tmp,j-tmp) && board.board[i+tmp][j-tmp]==1){//왼쪽 아래 방향
                        board.board[i+tmp][j-tmp]=3;
                        // cout<<i+tmp<<","<<j-tmp<<" = 3"<<endl;
                    }

                    if(check_bound(i-tmp,j+tmp) && board.board[i-tmp][j+tmp]==1){//오른쪽 위 방향
                        board.board[i-tmp][j+tmp]=3;
                        // cout<<i+tmp<<","<<j-tmp<<" = 3"<<endl;
                    }

                    if(check_bound(i-tmp,j-tmp) && board.board[i-tmp][j-tmp]==1){//왼쪽 위 방향
                        board.board[i-tmp][j-tmp]=3;
                        // cout<<i+tmp<<","<<j-tmp<<" = 3"<<endl;
                    }

                    tmp++;

                    // cout<<"---------------"<<endl;
                    // for(int s=0;s<n;s++){
                    //     for(int t=0;t<n;t++){
                    //         cout<<board[s][t]<<" ";
                    //     }   
                    //     cout<<endl;
                    // }
                    // cout<<"---------------"<<endl;
                }
            }
        }
    }

    return ret;
}

int main(){

    Board original_board(n);

    // int board[n][n]; //비숍을 배치할 수 없다면 0, 배치할 수 있으면 1, 비숎이 배치됐다면 2, 배치된 비숍때문에 배치할 수 없다면 3
    //보드 입력 받기

    int list[5][5]={{1,1,0,1,1},{0,1,0,0,0},{1,0,1,0,1},{1,0,0,0,0},{1,0,1,1,1}};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            original_board.board[i][j]=list[i][j];
        }
    }

    cout<<"-------입력받은 보드--------"<<endl;
        for(int s=0;s<n;s++){
            for(int t=0;t<n;t++){
                cout<<original_board.board[s][t]<<" ";
            }   
            cout<<endl;
        }
    cout<<"---------------"<<endl;


    for(int x=0;x<n;x++){
        for(int y=0; y<n;y++){
            if(original_board.board[x][y]!=1){
                cout<<"hit"<<endl;
                continue;
            }
            else{
                Board sub_board(original_board);
                int ret = loop(sub_board,x,y);
                sub_board.~Board();
                original_board.board[x][y] =  ret;
            }
        }
    }



    cout<<"-------ret_board-----------"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<original_board.board[i][j]<<" ";
        }
        cout<<endl;
    }
}

