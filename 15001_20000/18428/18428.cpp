#include<iostream>
#include<vector>
using namespace std;

int n; 
char b[6][6];
int v[6][6]={0,};
int empty_total =0,cnt=0;
int dir[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
vector<pair<int,int>> teachers;
vector<pair<int,int>> walls;

bool isOK(int y,int x){ return 0<=y && y<n && 0<=x && x<n;}

bool find(){
    // 초기화
    for(auto w: walls)b[w.first][w.second]='X';
    walls.clear();

    for(int i=0;i<teachers.size();i++){
        

        for(auto d:dir){
            bool toPlace = false;

            int y= teachers[i].first, x= teachers[i].second;

            while(1){
                y+=d[0]; x+=d[1];
                if(!isOK(y,x) || b[y][x]=='O' || b[y][x]=='T') break;
                if(b[y][x]=='X') continue;
                
                toPlace = true;
                break;
            }

            // 장애물을 놓아야한다면
            if(toPlace && walls.size()<3){
                y= teachers[i].first; x= teachers[i].second;

               // 전에 놓은적 없는곳에 배치
                while(toPlace){
                    y+=d[0]; x+=d[1];
                    if(b[y][x]=='S')break;
                    if(v[y][x]) continue; // 전에 이미 배치했던 자리거나 학생이 있으면 pass
                    b[y][x]='O';
                    v[y][x]=1;
                    cnt++;
                    walls.push_back({y,x});
                    toPlace=0; 
                }
            }
                            
            // 장애물을 배치 못했으면
            if(toPlace) return false;
        }
    }

    return true;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    // freopen("input.txt","r",stdin);
    
    cin>>n;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        cin>>b[i][j];
        if(b[i][j]=='T') teachers.push_back({i,j});
        if(b[i][j]=='X') empty_total++;
    }

    int count=teachers.size()*4;
    while(count--){
        if(find()){
            cout<<"YES"<<endl;
            exit(0);
        }
    }
    cout<<"NO"<<endl;
}