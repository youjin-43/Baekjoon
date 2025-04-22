//24.7.5(금) 11000 강의실 배정 -> 시간 초과 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second) return a.first<b.first;
    return a.second<b.second;
}

using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int n; cin>>n; //1 ≤ N ≤ 200,000
    
    vector<pair<int,int> >list;
    
    for(int i=0,a,b;i<n;i++){
        cin>>a>>b;
        list.push_back(make_pair(a,b));
    }

    sort(list.begin(),list.end(),cmp);

    int check[200000]={0,};
    int ret=0;
    
    for(int i=0;i<n;i++){
        if(!check[i]){
            ret++;
            check[i]++;

            int strart=list[i].first;
            int end=list[i].second;

            for(int j=i+1;j<n;j++){
                if(!check[j]){
                    int next_start = list[j].first;
                    int next_end = list[j].second;

                    if(end<=next_start){
                        check[j]=1;
                        strart = next_start;
                        end=next_end;
                    }
                }
            }
        }
    }
    cout<<ret<<'\n';

}