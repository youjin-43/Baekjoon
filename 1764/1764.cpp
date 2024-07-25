#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    map<string,int> list;
    int n,m;cin>>n>>m;
    string tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        list.insert({tmp,0});
    }

    int ret=0;
    for(int i=0;i<m;i++){
        cin>>tmp;
        map<string,int>::iterator it = list.find(tmp);
        if(it != list.end()){
            it->second++;
            ret++;
        }
    }

    cout<<ret<<'\n';
    for(auto it:list){
        if(it.second) cout<<it.first<<'\n';
    }


}