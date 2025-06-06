// 풀이 링크 : https://youjin43.tistory.com/79

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;

vector<int> list;
int main(){
    int n; cin>>n; // N(1 ≤ N ≤ 500,000)
    map<int,int> m;
    double sum=0;
    for(int i=0,tmp;i<n;i++){
        cin>>tmp; 
        m[tmp]++;
        list.push_back(tmp);
        sum+=tmp;
    }
    
    // 산술평균
    cout <<(int)round(sum / n) << '\n';

    // 중앙값
    sort(list.begin(),list.end());
    cout<<list[n/2]<<'\n';
    
    // 최빈값 
    int max_cnt=0,max_num=0;
    int prev_cnt=0,prev_num=0;
    for(auto it=m.rbegin();it!=m.rend();it++){
        if(it->second > max_cnt){
            max_cnt=it->second;
            max_num=it->first;
            continue;
        }

        if(it->second == max_cnt){
            prev_num=max_num;
            prev_cnt=max_cnt;
            max_num=it->first;
        }
    }

    if(max_cnt==prev_cnt) cout<<prev_num<<'\n';
    else cout<<max_num<<'\n';

    // 범위
    cout<<m.rbegin()->first-m.begin()->first<<'\n';
}