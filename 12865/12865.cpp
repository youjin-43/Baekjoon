
//24.6.30(일) 12865 평범한 배낭 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int list[100001][101];
vector<pair<int,int> > things(101);

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int n,k; cin>>n>>k;

    for(int i=1;i<=n;i++){  
        cin>>things[i].first>>things[i].second;
    }

    //test1
    // int n=4,k=7;
    // things[0].first=4; things[0].second=8;
    // things[1].first=3; things[1].second=6;
    // things[2].first=5; things[2].second=12;
    

    //무게가 0일때 가치는 모두 0
    for(int i=0;i<=n;i++){
        list[0][i]=0;
    }
    //아무것도 안들어있을때 
    for(int i=0;i<=k;i++){
        list[i][0]=0;
    }

    //무게가 1부터 k까지 
    for(int i=1;i<=k;i++){

        //각 물품에 대하여 dp 진행
        for(int j=1;j<=n;j++){
            
            int weight = things[j].first;
            int value = things[j].second;

            if(weight<=i){
                list[i][j] = max(list[i-weight][j-1]+value,list[i][j-1]);
            }else{
                list[i][j]=list[i][j-1];
            }
        }
    }

    cout<<list[k][n];

}