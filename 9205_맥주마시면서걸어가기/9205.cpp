#include<iostream>
#include<stdlib.h>
#include<vector>
#include<queue>

#define X first
#define Y second

using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt","r",stdin);

    int t; cin>>t;
    while(t--){
        int check[105][105]={0,}; // i->j 로 이동하는데 한 박스 안에 갈 수 있는 거리인가 
        vector<pair<int,int> > pos; // idx 0은 출발지점, n-1은 도착지점 

        int n,x,y; cin>>n;
        n+=2;
        for(int i=0;i<n;i++){
            cin>>x>>y;
            pos.push_back(make_pair(x,y));
        }

        // 한 박스 안에 갈 수 있는 거리인지
        int dist;
        for(int s=0;s<n-1;s++){ // start
            for(int e=s+1;e<n;e++){ 
                if(s==e) continue;

                x = abs(pos[e].X-pos[s].X);
                y = abs(pos[e].Y-pos[s].Y);
                dist= x + y; 
                if(dist<=1000){
                    check[s][e]=1;
                    check[e][s]=1;
                }
            }
        }

        // 길찾기 
        vector<int> visit(n, 0);
        queue<int> q;
        q.push(0); // 출발지점에서 시작
        visit[0] = 1;

        while (!q.empty()) {
            int cur = q.front(); q.pop();
            if (cur == n - 1) break; // 도착했으면 끝!

            for (int next = 0; next < n; next++) {
                if (!visit[next] && check[cur][next]) {
                    visit[next] = 1;
                    q.push(next);
                }
            }
        }

        cout <<(visit[n-1] ? "happy":"sad")<<'\n';
    }    
}