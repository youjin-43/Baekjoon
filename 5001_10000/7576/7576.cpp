#include<iostream>
#include<queue>
using namespace std;

struct Tomato
{
    int a;//세로
    int b;//가로

    Tomato(int c, int d){
        a=c;
        b=d;
    }
};

int direc[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int box[1000][1000];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int m,n; cin>>m>>n;

    queue<Tomato> q;

    int total=0;
    int ripen=0;
    int unripen=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int tmp; cin>>tmp;
            box[i][j]=tmp;

            if(tmp!=-1) total++;
            if(tmp==1) ripen++;
            else if(tmp==0) unripen++;

            if(tmp==1){
                Tomato tomato(i,j);
                q.push(tomato);
            }
        }
    }

    if(total == q.size()){
        cout<<0;
        exit(0);
    }

    int needDate=0;
    int oneDaySize=q.size();

    while(!q.empty()){

        Tomato t = q.front();
        q.pop();
        
        for(int i=0;i<4;i++){
            int y=t.a+direc[i][0];
            int x=t.b+direc[i][1];

            // xy범위 체크
            if(0<=y && y<n && 0<=x&& x<m && box[y][x] == 0){
                box[y][x]=1;
                unripen--;
                ripen++;

                //박스 출력
                // for(int i=0;i<n;i++){
                //     for(int j=0;j<m;j++){
                //         cout<<box[i][j]<<' ';
                //     }
                //     cout<<endl;
                // }cout<<endl;

                Tomato t1(y,x);
                q.push(t1);
            }
        }

        oneDaySize--;
        if(oneDaySize==0){
            needDate++;
            oneDaySize=q.size();
        }
    }

    if(unripen==0){
        cout<<--needDate;
    }else{
        cout<<-1;
    }
}