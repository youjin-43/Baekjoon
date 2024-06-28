#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b);

int main(){
    int n; //1 ≤ N ≤ 100,000
    cin>>n;

    vector <pair<int,int>> time; // 시작시간, 종료시간
    int a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        time.push_back(make_pair(b,a));
    }
    sort(time.begin(),time.end(),cmp);


    int start = time[0].first;
    int end = time[0].second;
    int max =1;

    for(int i=1;i<n;i++){
        
    }



    
}

// 오름차순 정렬
bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first; 
}