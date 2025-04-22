//24.7.7(일) 1202 보석도둑
// 3퍼에서 시간초과!!! 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second==b.second){
        return a.first>b.first;
    }
    return a.second>b.second;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int n,k;
    cin>>n>>k;

    vector<pair<int,int> > gems; //무게, 가치
    for(int i=0,m,v;i<n;i++){
        cin>>m>>v;
        gems.push_back(make_pair(m,v));
    }

    sort(gems.begin(),gems.end(),cmp); //가치 기준 내림차순 정렬. 가치가 같다면 무게도 내림차순.

    vector<int> bags;
    for(int i=0,tmp;i<k;i++){
        cin>>tmp;
        bags.push_back(tmp);
    }
    sort(bags.begin(),bags.end());//담을 수 있는 무게 기준 오름차순 정렬

    int sum_value=0;
    int check[300000]={0,}; //가방에 넣은 보석인지 체크

    
    for(int bag=0;bag<k;bag++){ //각 가방에 대해 
        for(int gem=0;gem<n;gem++){ // 담을 수 있는 보석 중 가치가 가장 큰걸 담음 
            //이미 가방에 넣은 보석이거나 무거워서 담지 못한다면 Pass
            if(check[gem] || bags[bag] < gems[gem].first) continue;

            check[gem]=1;
            sum_value+=gems[gem].second;
            break;
        }
    }


    cout<<sum_value<<'\n';
}
