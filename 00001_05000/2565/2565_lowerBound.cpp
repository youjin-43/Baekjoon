//lowerbound이용해서 LIS구하기
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int,int> > list; //전깃줄
vector<int> LIS;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin>>n;
    for(int i=0,a,b;i<n;i++){
        cin>>a>>b;
        list.push_back(make_pair(a,b));
    }
    sort(list.begin(),list.end()); //first 기준으로 정렬 

    LIS.push_back(list[0].second);
    for(int i=1;i<n;i++){
        if(LIS.back()<list[i].second){
            LIS.push_back(list[i].second);
        }else{
            *lower_bound(LIS.begin(),LIS.end(),list[i].second)=list[i].second;
        }
    }
    cout<<n-LIS.size()<<endl;
}