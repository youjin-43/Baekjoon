#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int,int> > list;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n,a,b; cin>>n;
    while(n--){
        cin>>a>>b;
        if(a>b){
            list.push_back(make_pair(b,a));
        }else{
            list.push_back(make_pair(a,b));
        }
    }    
    sort(list.begin(),list.end());

    //출력확인 
    // for(int i=0;i<list.size();i++) cout<<list[i].first<<" "<<list[i].second<<endl;

    int s=list[0].first,e=list[0].second;
    int ret = e-s;
    for(int i=1;i<list.size();i++){

        if(e<list[i].first){
            s=list[i].first,e=list[i].second;
            ret += e-s;
        }
        else if(e<list[i].second){
            ret += list[i].second-e;
            e=list[i].second;
        }
    }
     cout<<ret<<'\n';

}