//앜 각 인덱스까지 봤을떄 LIS는 구해놓고 거기서 최댓값을 뺴야한는데 마지막에서 빼버림^^7
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int,int> > list; //전깃줄
int ret[100];
int LIS =0;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int n; cin>>n;
    for(int i=0,a,b;i<n;i++){
        cin>>a>>b;
        list.push_back(make_pair(a,b));
    }
    sort(list.begin(),list.end()); //first 기준으로 정렬 

    for(int i=0;i<n;i++){
        ret[i]=1;
        for(int j=i-1;j>=0;j--){
            if(list[j].second<list[i].second) {
                ret[i]=max(ret[i],ret[j]+1);
            }
        }
        LIS=max(LIS,ret[i]);
    }
    cout<<n-LIS<<'\n';
}