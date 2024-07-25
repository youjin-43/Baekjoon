
//24.6.29(토) 11650 좌표 정렬하기
//좌표를 x좌표가 증가하는 순으로, x좌표가 같으면 y좌표가 증가하는 순서로 정렬한 다음 출력

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    vector<pair<int,int> > list;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        list.push_back(make_pair(a,b));
    }
    sort(list.begin(),list.end(),cmp);

    for(int i=0;i<n;i++){
        cout<<list[i].first<<' '<<list[i].second<<'\n';
    }
}