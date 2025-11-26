

/*
1. 행성 배열 -> 어디 행성 안에 존재하는지 체크
2. 1인것만 다 더해서 출력 
*/

#include<iostream>
#include<vector>
using namespace std;

struct Pos{int x,y;};
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t; cin>>t;
    while(t--){
        Pos s,e; cin>>s.x>>s.y>>e.x>>e.y;
        int n; cin>>n;

        vector<int> cnt(n); 
        for(int i=0;i<n;i++){
            // i번 행성 정보 (위치, 반지름)
            Pos p; int r; cin>>p.x>>p.y>>r;

            // i번 행성 안에 출발점 or 도착점 있는지 확인 
            int s_dist = (p.x-s.x)*(p.x-s.x) + (p.y-s.y)*(p.y-s.y);
            int e_dist = (p.x-e.x)*(p.x-e.x) + (p.y-e.y)*(p.y-e.y);
            if(s_dist < r*r) cnt[i]++;
            if(e_dist < r*r) cnt[i]++;
        }

        int ret=0;
        for(int i=0;i<n;i++) if(cnt[i]==1) ret++;
        cout<<ret<<'\n';
    }
}