#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        vector<int> list;
        int n,m;
        cin>>n;
        for(int i=0,tmp;i<n;i++){
            cin>>tmp;
            list.push_back(tmp);
        }
        sort(list.begin(),list.end());  

        cin>>m;
        for(int i=0;i<m;i++){
            int a; cin>>a;
            if(a == *lower_bound(list.begin(),list.end(),a)){
                cout<<1<<'\n';
                }
            else{
                cout<<0<<'\n'; 
            }
        }
    }
}