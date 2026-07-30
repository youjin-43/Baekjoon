#include<iostream>
#include<algorithm>
#include<cmath>
#define SIZE 100'000
using namespace std;

int gun[SIZE];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int m,n,l; cin>>m>>n>>l;
    for(int i=0;i<m;i++)cin>>gun[i];
    sort(gun,gun+m);

    int ret=0;
    for(int i=0,x,y;i<n;i++){
        cin>>x>>y;

        if(y>l) continue; // y가 사정거리르 넘어가면 pass

        auto it = lower_bound(gun,gun+m,x);
        if(it != gun+m){
            int dist = abs(*it-x)+y;
            if(dist<=l){ ret++; continue; }
        }
        
        if(it!=gun){
            it--;
            int dist = abs(*it-x)+y;
            if(dist<=l) ret++;
        }
    }
    cout<<ret<<'\n';
}