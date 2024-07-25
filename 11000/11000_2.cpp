// 24.7.6(토) 11000 강의실 배정 prioty queue를 써보겠다.
// 강의실이 새로 필요하면 pq에 삽입하는 식 
// -> pq를 이용하는 이유는 top에 계속 제일 빠르게 끝나는 시간을 유지시키기 위함 인것 같음 
// -> 최종적으로  pq의 size가 필요한 강의실 수임. 

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first) return a.second<b.second;
    return a.first<b.first;
}

using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int n; cin>>n; //1 ≤ N ≤ 200,000
    // int n=3;
    
    vector<pair<int,int> >list;
    for(int i=0,a,b;i<n;i++){
        cin>>a>>b;
        list.push_back(make_pair(a,b));
    }

    // list.push_back(make_pair(1,3));
    // list.push_back(make_pair(2,4));
    // list.push_back(make_pair(3,5));


    sort(list.begin(),list.end(),cmp);


    priority_queue<int, vector<int>, greater<int> > pq;
    pq.push(list[0].second);

    for(int i=1;i<n;i++){
        if(list[i].first >= pq.top()){
            pq.pop();
        }
        pq.push(list[i].second);
    }
    cout<<pq.size()<<'\n';

}