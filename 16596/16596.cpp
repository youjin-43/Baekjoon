//24.8.28(수) 황금칵테일
#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("input.txt", "r", stdin);
    
    int n; cin>>n;

    map<string,int> map;
    for(int i=0;i<n;i++){
        string str; 
        int tmp; 
        cin>>str>>tmp;

        if(map.find(str) != map.end()){
            map[str]+=tmp;
        }else{
            map[str]=tmp;
        }
    }

    //debug
    for(pair<string,int> it : map){
        cout<<it.first<<' '<<it.second<<endl;
    }

    auto tmp = map.end();
    tmp--;
    for(auto it = map.begin(); it!=tmp; it++){
        auto it2 = map.begin();
        it2++;
        for(; it2!=map.end(); it2++){
            if((it->second)*1.168 == it2->second || (it2->second)*1.168 == it->second){
                cout<<"Delicious!"<<'\n';
                exit(0);
            }
        }
    }
    cout<<"Not Delicious..."<<'\n';
}