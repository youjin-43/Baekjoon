#include<iostream>
#include<vector>
#include<climits>
#include<tuple>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t; cin>>t;
    while(t--){
        int list[1000]={0,}; // 들어온 순서 
        int cnt[201]={0,}; // 팀별 참가한 인원
        
        // 입력 받기 
        int n; cin>>n; // 6 ≤ N ≤ 1,000
        for(int i=0;i<n;i++){
            cin>>list[i];
            cnt[list[i]]++;
        }

        // 점수 계산 
        vector<tuple<int,int,int>> v(201); // 팀별 점수, 계산된 인원, 5번째
        int score=1;
        for(int i=0;i<n;i++){
            int team = list[i];
            if(cnt[team]>=6){ // 각 팀의 참가 선수가 여섯보다 작으면 그 팀은 점수 계산에서 제외
                get<1>(v[team])++;
                if(get<1>(v[team])<=4) get<0>(v[team])+=score; // 상위 4명만 점수 합산
                if(get<1>(v[team])==5) get<2>(v[team])=score; // 5번째 선수 점수 저장
                score++;
            }
        }

        // 최저 점수 구하기 
        int min_score = INT_MAX;
        for(int i=1;i<=200;i++){
            if(get<1>(v[i])<6) continue;
            min_score = min(min_score, get<0>(v[i])); // 가장 낮은 점수 계산
        }

        // 공동 1등 확인 
        vector<int> t;
        for(int i=1;i<=200;i++){
            if(get<0>(v[i]) == min_score) t.push_back(i);
        }

        int ret = t[0];
        for(int i=0;i<t.size();i++){
            if(get<2>(v[ret]) > get<2>(v[t[i]])) ret = t[i];
        }
        cout<<ret<<endl;
    }
}