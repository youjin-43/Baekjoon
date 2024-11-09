//24.10.28(월)) 16928 뱀과 사다리 게임


//100번 칸을 넘어간다면 이동할 수 없다.
//사다리면 사다리 타고 올라가고 뱀이면 뱀 타고 내려감 
//게임판의 상태가 주어졌을 때, 100번 칸에 도착하기 위해 주사위를 굴려야 하는 횟수의 최솟값

// 그리디로 하려고 헀는데 이러면 최적값이 안나올수도 있음 -> 그냥 무지성 탐색ㄱㄱ 
// 근데 시간 오래걸리니까 최솟값을 저장했다가 이 이상 으로 넘어가면 다른 루트를 탐색하는걸로. 새로운 최솟값이면 갱신.

// 아 근데 그냥 현재 번호까지 올 수있는 최솟값 저장해서 풀면 안되나,,?
// 사다리먼저 최솟값 구하고 그다음에 뱀을 이용한 경우 다시 갱신 해보자 

// 아 사다리나 뱀 밟으면 무조건 가네;;

// 코드 정리좀 했다 

#include<iostream>
#include<vector>
using namespace std;

int End=100;
vector<int> ladder(End+1,0);
vector<int> snake(End+1,0);
vector<int> minCnt(End+1,100);

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n,m; cin>>n>>m;// 사다리의 수 N(1 ≤ N ≤ 15), 뱀의 수 M(1 ≤ M ≤ 15) 
    int from,to;

    //ladder
    while(n--){
        cin>>from>>to;
        ladder[from]=to; 
    }
    //snake
    while(m--){
        cin>>from>>to;
        snake[from]=to;
    }

    minCnt[1]=0;

    int i=1;
    while(i<=100){
        //ladder가 있는 경우 -> 무조건 이동해야함 
        if(ladder[i]){
            minCnt[ladder[i]]=min(minCnt[ladder[i]],minCnt[i]);
        }
        //i에서 내려가야하는 snake가 있는 경우 -> 무조건 이동해야함 
        else if(snake[i]){
            minCnt[snake[i]]=minCnt[i];
            snake[i]=-1; //visit 표시
        }
        //ladder도 snake도 없는경우
        else{
            for(int j=1;j<=6;j++){
                if((i+j)<=100){
                    minCnt[i+j]=min(minCnt[i]+1,minCnt[i+j]);
                }
            }
        }
        i++;
    }

    // snake가 적용된 상태에서 최솟값 다시 확인
    i=1;
    while(i<=100){
        //ladder가 있는 경우 -> 무조건 이동해야함 
        if(ladder[i]){
            minCnt[ladder[i]]=min(minCnt[ladder[i]],minCnt[i]);
        }
        else if(snake[i]!=-1){ //snake가 있는 부분은 피해서 감
            for(int j=1;j<=6;j++){
                if((i+j)<=100){
                    minCnt[i+j]=min(minCnt[i]+1,minCnt[i+j]);
                }
            }
        }
        i++;
    }

    cout<<minCnt[100]<<endl;
}