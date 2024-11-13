#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>
using namespace std;


//모든 강의의 시작하는 시간과 끝나는 시간을 알고 있다. 이때, 우리는 최대한 적은 수의 강의실을 사용하여 모든 강의가 이루어지게 하고 싶다.
//종료시간과 시작시간이 겹쳐도됨 
//필요한 최소 강의실의 수를 출력


//ret를 갱신할때마다 ret 벡터가 오름차순으로 보장되지않음!! 
//그냥 start 기준으로 정렬하고, 가장 빠르게 끝나는 시간을 pq로 가지고 있어야겠다.. 

vector<pair<int,int> > list; // 시작시간, 끝나는 시간 
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("input.txt","r",stdin);

    int n; cin>>n; //N(1 ≤ N ≤ 100,000)
    //강의 번호, 강의 시작 시간, 강의 종료 시간(종료 시간은 0 이상 10억 이하)
    for(int i=0,tmp,start,end;i<n;i++){
        cin>>tmp>>start>>end;
        list.push_back(make_pair(start,end));
    }
    sort(list.begin(),list.end()); //시작 시간 기준 소팅

    priority_queue<int,vector<int>,greater<int> > pq; //가장 빨리 끝나는 시간을 top에  
    pq.push(list[0].second);
    for(int i=1;i<n;i++){
        if(pq.top()<=list[i].first){
            pq.pop();
            
        }
        pq.push(list[i].second);

    }
    cout<<pq.size()<<'\n';
}