#include<iostream>
using namespace std;
int a[300][300];
int b[300][300];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int h,w,x,y; cin>>h>>w>>y>>x;

    for(int i=0;i<h+y;i++) for(int j=0;j<w+x;j++) cin>>b[i][j];

    // for(int i=0;i<h+y;i++) {for(int j=0;j<w+x;j++) cout<<b[i][j]<<' '; cout<<endl;}cout<<endl;

    // 왼쪽 위에
    for(int i=0;i<h;i++)for(int j=0;j<w;j++) a[i][j]=b[i][j];
    // for(int i=0;i<h;i++) {for(int j=0;j<w;j++) cout<<a[i][j]<<' '; cout<<endl;}cout<<endl;


    // 겹치는 중앙
    for(int i=y;i<h;i++)for(int j=x;j<w;j++) a[i][j]-=a[i-y][j-x];
    // for(int i=0;i<h;i++) {for(int j=0;j<w;j++) cout<<a[i][j]<<' '; cout<<endl;}cout<<endl;

    // 오른쪽 아래 
    for(int i=h-y;i<h;i++)for(int j=x;j<w;j++) a[i][j]=b[i+y][j+x];
    // for(int i=0;i<h;i++) {for(int j=0;j<w;j++) cout<<a[i][j]<<' '; cout<<endl;}cout<<endl;


    // 출력
    for(int i=0;i<h;i++) {for(int j=0;j<w;j++) cout<<a[i][j]<<' '; cout<<endl;}

    

    
    

}