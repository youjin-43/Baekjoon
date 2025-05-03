
//15686_치킨배달
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int list[50][50];
vector<pair<int,int>> house; // 집들의 위치 정보 
vector<pair<int,int>> chicken; // 치킨집들의 위치 정보 
vector<int> selected; // 선택된 치킨집

int calc_dist(pair<int,int> a, pair<int,int> b){
    return abs(a.first-b.first)+abs(a.second-b.second);
}

int calc_chicken_dist(){
    int ret=0;
    for(int i=0;i<house.size();i++){
        int dist=INT_MAX; // 각 집에서 치킨집까지의 최소 거리 
        for(int j=0;j<chicken.size();j++){
            if(selected[j]==1) dist=min(dist,calc_dist(house[i],chicken[j]));
        }
        ret+=dist;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int n,m; cin>>n>>m;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        cin>>list[i][j];
        if(list[i][j]==1) house.push_back({i,j});
        else if(list[i][j]==2) chicken.push_back({i,j});
    }

    // 치킨집 정보를 모두 입력받은 후에 selected 벡터 초기화
    selected.resize(chicken.size(), 0);
    for(int i=0;i<m;i++) selected[chicken.size()-1-i]=1;  // 치킨집 중 m개를 선택하는 모든 경우의 수 
    
    int ret=INT_MAX;
    do{ 
       ret=min(ret,calc_chicken_dist());
    }while(next_permutation(selected.begin(),selected.end()));
    cout<<ret<<'\n';
}