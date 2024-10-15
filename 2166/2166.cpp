//24.08.16(금)
#include<iostream>
using namespace std;
#define ld long double
struct Point{ ld x,y; };

// 삼각형 넓이 = 외적의 크기(평행사변형)/2
ld  Area (const Point &a, const Point &b, const Point &c){
    pair<ld,ld> v1=make_pair(c.x-a.x,c.y-a.y);
    pair<ld,ld> v2=make_pair(b.x-a.x,b.y-a.y);
    return (v1.first*v2.second - v1.second*v2.first)/2;
}


int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    Point list[10000];

    int n; cin>>n;
    for(int i=0;i<n;i++){
        cin>>list[i].x>>list[i].y;
    }

    double sum=0;
    for(int i=1;i<n-1;i++){
        sum+=Area(list[0],list[i],list[i+1]);
    }
    cout.precision(1);
    cout<<fixed;
    cout<<abs(sum)<<'\n';
}