#include<iostream>
using namespace std;
const double EPS = 1e-8; // 충분히 작은 값
#define MAX_ 1000000000
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    // 입력받기 
    int n; double t;
    cin>>n>>t;

    int x_list[50000], y_list[50000];
    for(int i=0;i<n;i++) cin>>x_list[i];
    for(int i=0;i<n;i++) cin>>y_list[i];

    // 모든 학생이 만날 수 있는 위치의 범위 계산 
    double l=-1e18,r=1e18;
    // cout<<l<<endl<<r<<endl<<endl;
    for(int i=0;i<n;i++){
        double d = y_list[i]*t;// 이동 가능 거리 
        r = min(r,x_list[i]+d); // 최대 범위 -> 각자의 최댓값 중 가장 작은 값
        l = max(l,x_list[i]-d); // 최소 범위 -> 각자의 최솟값 중 가장 큰 값
    }
    // cout<<l<<endl<<r<<endl<<endl;

    if(l<=r+EPS) cout<<1<<'\n'; // 이 두 개가 겹치면 만날 수 있음!!!
    else cout<<0<<'\n'; 
}