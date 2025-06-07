// 풀이 링크 : https://youjin43.tistory.com/80

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

vector<int> list;
vector<int> combi;

// n개중에서 r개를 뽑는 조합 
void genCombi(int start, int n, int r){
    if(combi.size()==r){
        for(int i=0;i<r;i++) cout<<combi[i]<<' '; cout<<'\n';
        return;
    }

    for(int i=start;i<n;i++){
        combi.push_back(list[i]);
        genCombi(i+1,n,r);
        combi.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; 
    while(cin>>n && n){
        // 초기화 
        list.clear();
        combi.clear();

        // 숫자 입력 받기 
        for(int i=0,tmp;i<n;i++){ cin>>tmp; list.push_back(tmp); }
        
        // 조합 출력 
        genCombi(0,n,6);
        cout<<'\n';
    }
}