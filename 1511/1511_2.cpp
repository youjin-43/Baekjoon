//24.9.23(월)
#include<iostream>
#include<string>
#include<queue>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    freopen("input.txt", "r", stdin);

    priority_queue<pair<int,int>> pq;
    int total = 0;
    for(int i=0,tmp;i<10;i++){
        cin>>tmp;
        pq.push(make_pair(tmp,i));
        total+=tmp;
    }

    /*
    가장 많이 있는 카드(max_idx)가 나머지 카드의 총합(sub_total)보다 적거나 같은경우 
    -> 한 카드가 sub_total보다 많을떄까지 가장 많이 있는 카드 최대한 반복해서 배치
    */
    int sub_total = total - pq.top().first;
    if(pq.top().first <= sub_total){


        
    }

}