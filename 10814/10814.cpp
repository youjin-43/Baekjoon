#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(tuple<int,string,int> a,tuple<int,string,int> b){
    if(get<0>(a)==get<0>(b)) return get<2>(a)<get<2>(b);
    return get<0>(a)<get<0>(b);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    vector<tuple<int,string,int> > list;
    
    int n; cin>>n;

    int age; string name; int num=0;
    for(int i=0;i<n;i++){
        cin>>age>>name;
        list.push_back(make_tuple(age,name,num));
        num++;
    }

    sort(list.begin(),list.end(),cmp);

    for(int i=0;i<n;i++){
        cout<<get<0>(list[i])<<' '<<get<1>(list[i])<<'\n';
    }
}