/*24.03.27 비숍*/

#include <iostream>
using namespace std;

int n;

bool check_bound(int a, int b){
    if( 0<=a&& a<n && 0<=b && b<n){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    cin>>n;

    int board[n][n]; //비숍을 배치할 수 없다면 0, 있으면 1, 비숎이 배치됐다면 2, 배치된 비숍때문에 배치할 수 없다면 3
    //보드 입력 받기
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
        }
    }

    int ret=0;
    
    //비숍을 배치할 수 있으면 우선 배치
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            //비숍을 배치할 수 없다면
            if(board[i][j] != 1){
                continue;
            }
            //배치할 수 있다면 일단 배치
            else{
                ret++; 
                board[i][j]=2; // 비숍 배치

                // cout<<i<<","<<j<<"에 비숍 배치"<<endl;

                //배치된 비숍때문에 배치할 수 없는 곳 표시(오른쪽 아래 -> 왼쪽아래)
                int tmp=1;

                while(i+tmp<n ){
                    //체스판 안에 있고 배숍을 배치할 수 있는 자리라면 실행
                    if(check_bound(i+tmp,j+tmp) && board[i+tmp][j+tmp]==1){ //오른쪽 아래방향
                        board[i+tmp][j+tmp]=3;
                        // cout<<i+tmp<<","<<j+tmp<<" = 3"<<endl;
                    }
                    
                    if(check_bound(i+tmp,j-tmp) && board[i+tmp][j-tmp]==1){//왼쪽 아래 방향
                        board[i+tmp][j-tmp]=3;
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

    cout<<ret<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

}

