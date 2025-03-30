#include<iostream>
using namespace std;
int list[1025][1025];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n,t; cin>>n>>t; 
    for(int i=0;i<=n;i++){
        list[0][i]=0;
        list[i][0]=0;
    }

    //가로 누적합 먼저 구하고 세로 누적합 구하고 하는 방식으로 해보자 
    int tmp;

    //가로 누적합 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>tmp;
            // list[i][j]=list[i-1][j]+list[i][j-1]-list[i-1][j-1]+tmp;
            list[i][j]=list[i][j-1]+tmp; 
        }
    }

    //세로 누적합
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            list[j][i]+=list[j-1][i];
        }
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<list[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;

    while(t--){
        int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
        cout<<list[x2][y2]-list[x2][y1-1]-list[x1-1][y2]+list[x1-1][y1-1]<<'\n';
    }
}