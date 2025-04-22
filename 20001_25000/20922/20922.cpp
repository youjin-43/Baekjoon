#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    queue<int> q; //최장 연속 부분 수열의 길이
    int cnt[100001]={0,};//나온 갯수
    int n,k; cin>>n>>k; 

    int num, ret=0; 
    for(int i=0;i<n;i++){
        cin>>num;
        while(cnt[num]>=k) cnt[q.front()]--,q.pop();
        q.push(num); cnt[num]++;
        ret=max(ret,(int)q.size());
    }
    cout<<ret<<'\n';
}