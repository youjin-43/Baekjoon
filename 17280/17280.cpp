//24.6.28(금) 17280 카풀 매칭


//실패한코드 
#include<iostream>
#include<vector>
#include <set>
#include<algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second){
        return  a.first < b.first;
    }else{
        return a.second < b.second;
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;

        //입력받고 소팅
        multiset<int> visiter; //insert 하면 알아서 소팅됨 
        for (int i=0, x; i<n; i++) {
			cin >> x;
			visiter.insert(x);
		}

        vector<pair<int,int> > list(m);
        for(int i=0;i<m;i++){
            cin >> list[i].first >> list[i].second;
        }

        sort(list.begin(),list.end(),cmp);

        // cout<<"sorted"<<endl;
        // for(int i=0;i<m;i++){
        //     cout<<list[i].first<<' '<<list[i].second<<endl;
        // }

        //멀리가는 손님부터 그리디로 배치
        int ret=0;

        for(int i=m-1;i>=0;i--){
            auto it = visiter.lower_bound(list[i].first);
            if(it != visiter.end() && *it<list[i].second){
                ret++;
                passenger.erase(it);
            }
        }
        cout<<ret<<endl;

    }
}