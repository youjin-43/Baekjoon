#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int m,n; 

// 순위로 치환 -> map을 이용해서 O(N log N)으로 최적화
vector<int> Calc_Rank(vector<int>& space){
    vector<int> tmp = space;
    sort(tmp.begin(), tmp.end());

    map<int,int> m;
    int rank = 0;
    for(int i=0;i<n;i++) if(m.find(tmp[i]) == m.end()) m[tmp[i]]=rank++;

    vector<int> ret;
    for(int i=0;i<n;i++) ret.push_back(m[space[i]]);
    
    return ret;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    
    cin>>m>>n;
    vector<vector<int> > spaces(m);
    
    // 무게 입력받기 
    int w;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>w; 
            spaces[i].push_back(w);
        }
    }

    // 같은 패턴이 있는지 확인 
    map<vector<int>,int> pattern;
    for(int i=0;i<m;i++) pattern[Calc_Rank(spaces[i])]++;

    // 조합으로 쌍 계산
    int ret=0;
    for(auto it : pattern) if(it.second>=2) ret+=it.second*(it.second-1)/2; //nC2 계산
    cout<<ret<<'\n';
}