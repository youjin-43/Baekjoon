#include<iostream>
#include<queue>
#define SIZE 1000
using namespace std;

struct Info{ int num,d;}; // 트럭 번호, 남아있는 거리

int list[SIZE];
deque<Info> dq; // 현재 다리에 있는 트럭들
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    
    // n 트럭의 수, w 다리의 길이, L 다리의 최대하중
    int n,w,l; cin>>n>>w>>l;
    for(int i=0;i<n;i++) cin>>list[i]; // 트럭의 무게 임력 받기 


    int ret=0, cur_l=0,idx=0; // idx는 현재 진입해야하는 트럭
    while(idx<n || dq.size()){
        // 트럭들 앞으로 한칸
        int cnt=dq.size();
        while(cnt--){
            Info cur = dq.front(); dq.pop_front();
            cur.d--;
            if(cur.d) dq.push_back(cur); // 거리가 남아있는 경우 다시 push
            else cur_l-=list[cur.num]; // 0이면 하중 빼기
        }

        // 진입 가능한 경우 
        if(idx<n && cur_l<l && cur_l+list[idx]<=l){
            dq.push_back({idx,w});
            cur_l+=list[idx++];
        }

        // 시간 증가
        ret++;
    }

    cout<<ret<<'\n';
}