#include<iostream>
#include<queue>
#include<algorithm>
#define SIZE 1001
using namespace std;

struct info{ int s,d;};

priority_queue<int, vector<int>, greater<int>> pq; // 내가 수행한 과제 점수들 -> minheap 
info arr[SIZE];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int n; cin>>n;
    for(int i=0,d,s;i<n;i++){
        cin>>d>>s;
        arr[i]={s,d};
    }

    // 정렬 (데드라인 임박한 순)
    sort(arr,arr+n,[](const info& a,const info& b){return a.d<b.d;}); // 데드라인 기준 오름차순 

    for(int i=0;i<n;i++){
        // 현재 해야하는 과제 
        info cur = arr[i];
        pq.push(cur.s); 
        
        // 현재 마감일까지 할 수 있는 개수 초과하면 가장 작은 점수 제거
        if(pq.size()>cur.d) pq.pop(); 
    }

    int ret=0;
    while(pq.size()){ ret+=pq.top(); pq.pop(); }
    cout<<ret<<'\n';
}