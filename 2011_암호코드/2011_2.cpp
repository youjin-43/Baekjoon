#include<iostream>
using namespace std;

int ret[5001];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    string str;cin >> str;
    vector<int> vec(str.size());
    int i;
    vec[0]= 1;
    for(i = 0; i < str.size(); i++){
        if(str[i]-'0') vec[i+1]=vec[i];
        if(i && str[i-1]-'0' && (str[i-1]-'0')*10+str[i]-'0'<27)
            vec[i+1]=(vec[i+1]+vec[i-1])%1000000;
        for(auto j : vec) cout << j << ' ';
        cout << '\n';
        }

    cout << vec[str.size()];
}