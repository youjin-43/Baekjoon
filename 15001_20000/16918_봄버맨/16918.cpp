#include<iostream>
#include<string>
#include<queue>
using namespace std;
string b[200];
int r,c,n; 
void print(){
    for(int i=0;i<r;i++){
        for(auto &s:b[i]) if(s=='0' || s=='1' ||  s=='2') s='O';
        cout<<b[i]<<'\n';
    }
    exit(0);
    // cout<<endl;
}

bool isOk(int i,int j){
    return 0<=i && i<r && 0<=j && j<c;
}

void boom(int i,int j){
    if(isOk(i+1, j) && b[i+1][j]!='2')b[i+1][j]='.';
    if(isOk(i-1, j) && b[i-1][j]!='2')b[i-1][j]='.';
    if(isOk(i, j+1) && b[i][j+1]!='2')b[i][j+1]='.';
    if(isOk(i, j-1) && b[i][j-1]!='2') b[i][j-1]='.';
    b[i][j]='.';
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    // 크기가 R×C인 직사각형 격자판

    // 폭탄은 3초뒤 폭발
    // 폭탄이 있던칸은 빈칸
    // 인접 4칸도 같이 폭발, 폭탄은 파괴

    // 처음 : 일부에 폭탄 설치
    // 1초 : 아무것도 안함
    // 2초 : 폭탄 설치 안되어있는곳에 모두 설치 --> 모든 칸에 폭탄 설치됨
    // 3초 : 처음 설치했던 폭탄이 모두 폭발
    // 2초,3초 반복

    // n초가 흐른 후 격자판의 상태

    cin>>r>>c>>n; // 빈칸 :. 폭탄 : O

    // 0초(놓기), 1초(기다림)
    for(int i=0;i<r;i++) cin>>b[i];
    if(n==0 || n==1) 
    print();
    
    // 1초 - 기다림
    
    //2초 == 0초에 +2, 빈곳에 폭탄놓기
    for(int i=0;i<r;i++){
        for(auto &s:b[i]){
            if(s=='O') s='2';
            else if(s=='.')s='0';
        }
    }

    // --> 빈곳이 없어짐 
    if((n%2)==0) 
    print();

    // 3초 : 펑~
    for(int i=0;i<r;i++)for(int j=0;j<c;j++){
        if(b[i][j]=='.')continue;
        if(b[i][j]=='2')boom(i,j);
        else b[i][j]++;
    }
    if(((n-3)%4)==0) 
    print();

    // 4초 : 빈곳에 놓기 
    for(int i=0;i<r;i++)for(int j=0;j<c;j++){
        if(b[i][j]=='.') b[i][j]='O';
        else if(b[i][j]=='1') b[i][j]='2';
    }
    // print();
    
    // 5초
    for(int i=0;i<r;i++)for(int j=0;j<c;j++){
        if(b[i][j]=='2')boom(i,j);
    }
    print();
}