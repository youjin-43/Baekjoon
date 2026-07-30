#include<iostream>
#include<algorithm>
#include<queue>
#define SIZE 10'001
using namespace std;

int arr[SIZE];
priority_queue<int> pq;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    
    // freopen("input.txt","r",stdin);

    int n,k; cin>>n>>k; // N개의 센서, K개의 집중국
    if(k >= n){ cout<<0<<'\n'; return 0; } // 예외 경우
    for(int i=0;i<n;i++) cin>>arr[i];

    sort(arr,arr+n);
    for(int i=1;i<n;i++) if(arr[i]-arr[i-1]) pq.push(arr[i]-arr[i-1]);
    for(int i=0;i<k-1;i++) pq.pop();

    int ret=0;
    while(pq.size()){ret+=pq.top(); pq.pop();}
    cout<<ret<<'\n';
}