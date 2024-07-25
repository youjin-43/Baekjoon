#include<iostream>
#include<queue>
using namespace std;

struct Tomato
{
    int c;//높이   
    int a;//세로
    int b;//가로
    

    Tomato(int i,int j, int k){ 
        c=i;
        a=j;
        b=k;
        
    }
};

int direc[6][3]={{0,1,0},{0,-1,0},{0,0,1},{0,0,-1},{1,0,0},{-1,0,0}};
int box[100][100][100]; // 높이 세로 가로

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int m,n,h; cin>>m>>n>>h;

    queue<Tomato> q;

    int total=0;
    int ripen=0;
    int unripen=0;
    for(int k=0;k<h;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int tmp; cin>>tmp;
                box[k][i][j]=tmp;

                if(tmp!=-1) total++;
                if(tmp==0) unripen++;
                if(tmp==1){
                    ripen++;
                    Tomato tomato(k,i,j);
                    q.push(tomato);
                }
            }
        }
    }


    if(total == ripen){
        cout<<0;
        exit(0);
    }

    int needDate=0;
    int oneDaySize=q.size();

    while(!q.empty()){

        Tomato t = q.front();
        q.pop();
        
        for(int i=0;i<6;i++){
            int z=t.c+direc[i][0]; //높이
            int y=t.a+direc[i][1]; //세로
            int x=t.b+direc[i][2]; //가로


            // xy범위 체크
            if(0<=z && z<h && 0<=y && y<n && 0<=x&& x<m && box[z][y][x] == 0){
                box[z][y][x]=1;
                unripen--;
                ripen++;

                //박스출력
                // for(int k=0;k<h;k++){
                //     for(int i=0;i<n;i++){
                //         for(int j=0;j<m;j++){
                //             cout<<box[k][i][j];
                //         }cout<<endl;
                //     }cout<<endl;
                // }cout<<endl<<endl;



                Tomato t1(z,y,x);
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