#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;  
    cin>>n;
    vector<int> list(n,0);
    for(int i=0;i<n;i++) list[i]=i+1;
    do{
        for(auto it = list.begin(); it != list.end(); it++) cout << *it << ' ';
        cout << '\n';
    }while(next_permutation(list.begin(),list.end()));
}