//24.8.9(금) 13549 숨바꼭질3
#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<algorithm>
using namespace std;

int start,end_; // (0 ≤ N,K ≤ 100,000)
vector<int> graph(100001, INT_MAX); // 인덱스 1부터 100000 까지 사용, 초기값 INT_MAX로 설정. 
int check[100001]={0,};
priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > > pq; //cost,node

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    cin>>start>>end_;

    //start부터 다익스트라 ㄱㄱ
    graph[start]=0;
    pq.push(make_pair(0, start));

    while(!pq.empty()){
        start = pq.top().second;
        check[start]=1;
        pq.pop();

        //x-1 : 비용 1
        if(!check[start+1] && graph[start+1]>graph[start]+1){
            graph[start+1]=graph[start]+1;
            pq.push(make_pair(graph[start+1],start+1));
        }

        //x+1 : 비용 1
        if(!check[start-1] && graph[start-1]>graph[start]+1){
            graph[start-1]=graph[start]+1;
            pq.push(make_pair(graph[start-1],start-1));
        }

        //2x : 비용 0
        if(start*2<=100000 && !check[start*2] && graph[start]<graph[start*2]){
            graph[start*2]=graph[start];
            pq.push(make_pair(graph[start*2],start*2));
        }
    }
    cout<<graph[end_];
}