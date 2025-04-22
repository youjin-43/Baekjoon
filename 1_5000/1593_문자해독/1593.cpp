// 1593_문자해독
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m;
    char str[3001],list[3000001];

    // freopen("input.txt","r",stdin);
    cin>>n>>m>>str>>list;

    int ret=0;
    // 문자 구성 확인 
    vector<int> cnt(128,0), window_cnt(128, 0);;
    for(int i=0;i<n;i++) cnt[str[i]]++;  // 암호문 str의 알파벳 빈도 기록

    // 초기 윈도우 확인 
    for (int i = 0; i < n; i++) window_cnt[list[i]]++; 
    if (window_cnt == cnt) ret++; 

    // 슬라이딩 윈도우
    for (int i = 0; i < m-n; i++) {
        window_cnt[list[i]]--;     // 빠져나간 문자
        window_cnt[list[i+n]]++;   // 새로 들어온 문자
        if (window_cnt == cnt) ret++;
    }
    cout<<ret<<'\n';
}