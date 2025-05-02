// 1251번 단어나누기

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    string s; cin>>s;
    vector<string> candidates;  // 모든 가능한 단어 조합을 저장하는 벡터
    
    // 모든 가능한 분할 지점에 대해 시도
    for(int i=1; i<s.size()-1; i++){
        for(int j=i+1; j<s.size(); j++){
            string tmp = s;
            
            // 세 부분으로 나눈 후 각 부분을 뒤집음
            reverse(tmp.begin(), tmp.begin()+i);      // 첫 번째 부분 뒤집기
            reverse(tmp.begin()+i, tmp.begin()+j);    // 두 번째 부분 뒤집기
            reverse(tmp.begin()+j, tmp.end());        // 세 번째 부분 뒤집기
            
            candidates.push_back(tmp);  // 만들어진 단어를 후보 목록에 추가
        }
    }
    
    // 모든 후보 단어들을 사전순으로 정렬
    sort(candidates.begin(), candidates.end());
    // 사전순으로 가장 앞서는 단어 출력
    cout<<candidates[0]<<'\n';
}