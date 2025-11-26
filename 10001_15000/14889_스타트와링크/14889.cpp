#include<iostream>
#include<climits>
#include<vector>
using namespace std;
int list[20][20];
int n, ret = INT_MAX;

vector<int> v[2];
int make_team(int v){
    v
}

int find(int cnt, int v){
    // base 
    if(cnt == n/2){
        // 팀의 능력치의 차이의 최솟값
        int t0=0,t1=0;
        for(int i=0;i<n;i++){
            if(v&(1<<i)){
                t1+=list[]
            }
            else{

            }
        }

    }

    //recursive
    for(int i=0;i<n;i++){
        if(v&(1<<i)) continue;
        return find(cnt+1,v|(1<<i));
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++) cin>>list[i][j];


}