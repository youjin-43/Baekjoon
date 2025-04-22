#include<iostream>
#include<algorithm>
using namespace std;

int m[1500001]={0,}; // money
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int n,w,p; // workDay, Pay
    cin>>n;
    for(int s=1;s<=n;s++) { // start 
        cin >> w >> p;
        m[s] = max(m[s] ,m[s-1]);
        if(s + w-1<=n) m[s + w-1] = max(m[s-1]+p,m[s + w-1]);
    }
    cout<<m[n]<<'\n';
}