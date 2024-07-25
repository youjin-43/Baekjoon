//24.7.8(월) 2239 스토쿠
#include<iostream>

int section[9][4] = {
                        {0,3,0,3},{0,3,4,6},{0,3,7,9},
                        {4,6,0,3},{4,6,4,6},{4,6,7,9},
                        {7,9,0,3},{7,9,4,6},{0,3,7,9}
                    };


int check_bit(int list, int num){

}

void fill(int i,int j){

    //행 확인
    for(int i=0;i<9;i++){
        
    }

    //열 확인

    //구역확인
}

using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    char board[9][10] ;
    for(int i=0;i<9;i++){
        cin>>board[i];
    }

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]=='0') fill(i,j);
        }
    }
}