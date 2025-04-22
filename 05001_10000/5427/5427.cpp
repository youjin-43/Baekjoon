//24.11.8(금) 5427 - 불 

// 불 위치 스택이나 큐에 넣어놓고 상하좌우 옮겨붙게 하고 
// 상근이 움직일 수 있는곳 모두 탐색 

// 상근이가 있는 칸에 불이 옮겨옴과 동시에 다른 칸으로 이동할 수 있다.

#include<iostream>
#include<string>
#include<queue>
#define endl '\n'
using namespace std;

string Map[1000];
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};//상하좌우
int w,h;
pair<int,int> personPos;//상근이의 위치 

//범위 안에 있는지 확인 
bool isInside(int floor, int pos){
    return 0<=floor && floor<h && 0<=pos && pos<w;
}

//불난곳인지 확인
bool isFire(int floor, int pos){
    return Map[floor][pos]=='*';
}

//벽인지 확인
bool isWall(int floor, int pos){
    return Map[floor][pos]=='#';
}
//빈곳인지 확인
bool isEmpty(int floor, int pos){
    return Map[floor][pos]=='.';
}

//사람있는곳인지 확인 
bool isPerson(int floor, int pos){
    return personPos.first==floor && personPos.second==pos;
}

//상근이가 방문한곳인지 확인 
bool isVisit(int floor, int pos){
    return Map[floor][pos]=='x';
}


void PrintMap(){
    cout<<endl;
    for(int i=0;i<h;i++) cout<<Map[i]<<endl;
    cout<<endl<<endl;
}
queue<pair<int,int> > fire; // 불이 있는곳 저장 층,위치 
queue<pair<int,int> > toGo; //상근이가 갈 수 있는곳 

int ret = 0;
void Find(){
    //처음 위치 넣기 
    toGo.push(make_pair(personPos.first,personPos.second));

    while(!toGo.empty()) {
        ret++;

        //불이 번져부렀어 -> 상하좌우로 불이 번질 수 있는지 확인 
        int fireCnt = fire.size();
        while(fireCnt--){
            pair<int,int> currentFire = fire.front(); fire.pop();
            for(int i=0;i<4;i++){
                int a = currentFire.first+dir[i][0];
                int b = currentFire.second + dir[i][1];

                //경계에 벗어나지 않으면서 비어있는곳이거나 상근이가 있는곳에는 불이 번질 수 있음 
                if(isInside(a,b) && (isEmpty(a,b) || isPerson(a,b) || isVisit(a,b))){
                    Map[a][b]='*';
                    fire.push(make_pair(a,b));
                }
            }
        }

        // PrintMap();

        //상근이 지금 탈출 가능? -> 상하좌우 확인 
        int moveCnt = toGo.size();
        while(moveCnt--){
            personPos = toGo.front(); toGo.pop();

            for(int i=0;i<4;i++){
                int a = personPos.first+dir[i][0];
                int b = personPos.second + dir[i][1];
                // cout<<"a,b :"<<a<<", "<<b<<endl;

                //건물 밖으로 나갈 수 있다면 
                if(!isInside(a,b)){
                    cout<<ret<<endl;
                    // cout<<"설마 여기 들어가냐?"<<endl;
                    return;
                }
                //경계에 벗어나지 않으면서 아직 방문하지 않았고 비어있는곳에는 갈 수 있음
                else if(isInside(a,b) && isEmpty(a,b)){
                    toGo.push(make_pair(a,b));
                    Map[a][b]='x';//방문표시
                }
            }
        }
        // PrintMap();
    }

    cout<<"IMPOSSIBLE"<<endl;
    return;
}

void QueueClear(){
    while(!fire.empty()) fire.pop();
    while(!toGo.empty()) toGo.pop();
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    // freopen("input.txt","r",stdin);
    // int t; cin>>t;
    // while(t--){
        QueueClear(); // 큐 클리어
        ret = 0;

        //입력받기
        cin>>h>>w; //높이와 너비(1 ≤ w,h ≤ 1000)
        for(int i=0;i<h;i++) cin>>Map[i];
        
        //상근이의 위치와 불의 위치 파악 
        for(int floor=0;floor<h;floor++){
            for(int pos=0;pos<w;pos++){
                char tmp = Map[floor][pos];
                if(tmp=='F') fire.push(make_pair(floor,pos));
                else if(tmp=='J') {
                    personPos.first=floor; 
                    personPos.second=pos;
                }
            }
        }

        //빌딩을 탈출하는데 가장 빠른 시간을 출력
        Find();
    // }
}