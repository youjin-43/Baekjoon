#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.first<b.first;
}

bool cmp2(pair<int,int> a, pair<int,int> b){
    return a.second<b.second;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    vector<pair<int,int> > list; // 점수, 문제번호

    for(int i=0,tmp;i<8;i++){
        cin>>tmp;
        list.push_back(make_pair(tmp,i+1));
    }
    sort(list.begin(),list.end(),cmp);

    // for(int i=0;i<8;i++){
    //     cout<<"num : "<<list[i].second<<" score : "<<list[i].first<<endl;
    // }cout<<endl;
    
    sort(list.begin()+3,list.end(),cmp2);

    // for(int i=0;i<8;i++){
    //     cout<<"num : "<<list[i].second<<" score : "<<list[i].first<<endl;
    // }

    int sum=0;
    for(int i=3;i<8;i++){
        sum+=list[i].first;
    }
    cout<<sum<<endl;

    for(int i=3,sum=0;i<8;i++){
        cout<<list[i].second<<' ';
    }
    
}