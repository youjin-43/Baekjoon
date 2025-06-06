#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt","r",stdin);

    int n,ret=0; cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    
    // list[i]가 Sk라고 가정하고 왼쪽 오른쪽 탐색 
    vector<int> L,R;
    for(int i=0;i<n;i++){
        int Sk = arr[i];

        // Left
        for(int idx=0;idx<=i;idx++){

            int num = arr[idx];
            auto it = lower_bound(L.begin(),L.end(),num);
            if(it == L.end()) L.push_back(num);
            else *it = num;
        }

        //Right
        for(int idx=i+1;idx<=n;idx++){
            int num = arr[idx];
            auto it = lower_bound(R.begin(),R.end(),num,greater<int>());
            if(it == R.end()) R.push_back(num);
            else *it = num;
        }

        ret=max(ret,int(L.size()+R.size()-1));
        L.clear(); R.clear();
    }
    cout<<ret<<'\n';
}