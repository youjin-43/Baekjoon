//24.7.7(일) 1202 보석도둑
// pq이용? -> 공책 test3이 반례
// 아 pq 이용까진 맞았는데 이렇게 쓰는게 아니었누~

// 보석 무게 기준 오름차순 정렬 -> 넣을수 있는 보석의 가치 pq에 push
// value += pq.top
// 큐에서 팝 할땐 항상 큐가 비어있진 않은지 확인하자!!!!


#include<iostream>
#include<queue>
using namespace std;


int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int n,k;
    cin>>n>>k;

    vector<pair<int,int> > gems; //무게, 가치
    for(int i=0,m,v;i<n;i++){
        cin>>m>>v;
        gems.push_back(make_pair(m,v));
    }

    sort(gems.begin(),gems.end()); //보석 무게 기준 오름차순

    vector<int> bags;
    for(int i=0,tmp;i<k;i++){
        cin>>tmp;
        bags.push_back(tmp);
    }
    sort(bags.begin(),bags.end());//담을 수 있는 무게 기준 오름차순



    priority_queue<int> pq; 
    
    long sum_value=0;

    //각 가방에 대해 넣을수 있는 보석이 있다면 pq에 보석의 가치 push
    int gem=0;
    for(int bag=0;bag<k;bag++){ 
        for(;gem<n;gem++){ 
            if(bags[bag] < gems[gem].first) break;
            pq.push(gems[gem].second);
        }

        if(!pq.empty()){
            sum_value+=pq.top();
            pq.pop();
        }

    }


    cout<<sum_value<<'\n';
}
