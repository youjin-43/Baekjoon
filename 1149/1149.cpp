//24.07.26 1149 RGB거리

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int list[1000][3];
int ret[1000][3]={0,};
int n;

void fill(int idx, int pre_color, int current_color){
    //base step
    if(idx==n){
        return;
    }

    //recursive step 
    if(ret[idx][current_color]==0){
        if(idx==0){
            ret[idx][current_color]=list[idx][current_color];
        }else{
            ret[idx][current_color]=list[idx][current_color]+ret[idx-1][pre_color];
        }
    }
    else{
        int tmp = ret[idx-1][pre_color]+list[idx][current_color];
        
        if(tmp<ret[idx][current_color]){
            ret[idx][current_color]=tmp;
        }else{
            return;
        }
    }

    for(int i=0;i<3;i++){
        if(i != current_color){
            fill(idx+1,current_color,i);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    // freopen("input.txt", "r", stdin);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>list[i][0]>>list[i][1]>>list[i][2];
    }

    for(int i=0;i<3;i++){
        fill(0,-1,i);
    }
    cout<<min({ret[n-1][0],ret[n-1][1],ret[n-1][2]});
    
}