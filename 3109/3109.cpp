//24.07.21(일) 3109 빵집 -> 그리디
#include<iostream>
#include<string>
using namespace std;

int R,C; //(1 ≤ R ≤ 10,000, 5 ≤ C ≤ 500)
string road[10000]; //아 여기 처음에 1000으로 해놨더라ㅋㅋㅋㅋ 
int check[10000][500]={0,};
int dir[3]={-1,0,1};

int  march(int y, int x){

    check[y][x]=1;

    //base step
    if(x==C-1) return 1;

    //recursive step
    for(int i=0;i<3;i++){
        int next_y = y+dir[i];
        int next_x = x+1;

        //next_y와 next_x가 경계를 벗어나지 않는지 먼저 확인한 후, 다른 조건들을 확인하도록 순서를 변경
        if(0<=next_y && next_y<R && road[next_y][next_x]!='x' && check[next_y][next_x]==0){ 
            
            //도달하는데 성공한경우
            if(march(next_y,next_x)){
                return 1;
            }

        }
    }
    //못찾은 경우
    // check[y][x]=0; 굳이 안되는곳을 다시 탐색 할 필요x
    return 0;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    //입력받기
    cin>>R>>C;
    for(int i=0;i<R;i++){
        cin>>road[i];
    }

    int ret=0;
    for(int floor=0;floor<R;floor++){
        ret+=march(floor,0);
    }
    cout<<ret<<'\n';

}