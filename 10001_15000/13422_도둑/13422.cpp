#include<iostream>
using namespace std;

int house[100000];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n,m,k; // n: 집의 갯수, m: 훔칠 집
        long long cnt=0;
        cin>>n>>m>>k;
        for(int i=0;i<n;i++){
            cin>>house[i];
            if(i<m) cnt+=house[i];
        }

        if(n==m){
            if(cnt<k)cout<<1<<'\n';
            else cout<<0<<'\n';
            continue;;
        }

        int ret=0;
        // s: start
        for(int s=0;s<n;s++){
            cnt-=house[s];
            cnt+=house[(s+m)%n];
            if(cnt<k) ret++;
        }
        cout<<ret<<'\n';
    }
}