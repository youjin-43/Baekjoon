#include<iostream>
#include<climits>
#include<vector>
using namespace std;
int list[20][20];
int n, ret = INT_MAX; // 4 ≤ N ≤ 20, N은 짝수

int abs(int a,int b){
    return a>b?a-b:b-a;
}

vector<int> v_0;
vector<int> v_1;
int calc(int team){
    // 초기화
    v_0.clear();
    v_1.clear();

    for(int i=0;i<n;i++){
        if(i) team>>=1;
        if(team&1) v_1.push_back(i);
        else v_0.push_back(i);
    }

    // 0팀 힘 계산
    int sum_0=0;
    for(int i=0;i<v_0.size()-1;i++)for(int j=i+1;j<v_0.size();j++) sum_0+=(list[v_0[i]][v_0[j]]+list[v_0[j]][v_0[i]]);

    // 1팀 힘 계산
    int sum_1=0;
    for(int i=0;i<v_1.size()-1;i++)for(int j=i+1;j<v_1.size();j++) sum_1+=(list[v_1[i]][v_1[j]]+list[v_1[j]][v_1[i]]);

    // ret 갱신
    ret = min(ret,abs(sum_0-sum_1));
    if(ret==0){
        cout<<0<<'\n';
        exit(0);
    }
}

void Solution(int d,int cnt, int b){
    // base
    if(cnt==n/2){
        calc(b);
        return;
    }

    if(d==n) return;

    //recursive
    Solution(d+1,cnt+1,b|(1<<d)); // d번째를 넣던가
    Solution(d+1,cnt,b);// 안넣던가
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    // freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++) cin>>list[i][j];
    Solution(0,0,0);
    cout<<ret<<'\n';
}