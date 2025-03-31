//25.3.30(일) 12891 DNA 비밀번호

#include<iostream>
#include<string>

using namespace std;

int cnt[4]{0,};
int allow_cnt[4]; // 포함될 최소 개수

int CharToIdx(char c){
    int DNA_idx;
    switch (c)
    {
        case 'A': DNA_idx=0; break;
        case 'C': DNA_idx=1; break;
        case 'G': DNA_idx=2; break;
        case 'T': DNA_idx=3; break;
        default: break;
    }
    return DNA_idx;
}

bool Check(int idx){
    // 하나라도 만족 못하면 false;
    for(int i=0;i<4;i++) if(allow_cnt[i]>cnt[i]) return 0;
    return 1; 
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int ret=0; // 만들 수 있는 비밀번호의 종류의 수

    int s,p; cin>>s>>p; // 1 ≤ |P| ≤ |S| ≤ 1,000,000
    string str; cin>>str;
    for(int i=0;i<4;i++) cin>>allow_cnt[i]; // 포함될 최소 개수

    for(int i=0;i<s;i++){
        // i-p에 있던 문자는 뻄 
        if(p<=i) cnt[CharToIdx(str[i-p])]--; 

        // 현재 문자의 cnt는 하나 증가 
        cnt[CharToIdx(str[i])]++; 

        // 요구조건을 만족하는지 확인 
        if(p-1<=i && Check(i)) ret++;
    }
    cout<<ret<<'\n';
}