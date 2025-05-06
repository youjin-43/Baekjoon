// 백준 4888 연산자 끼워넣기
// 풀이 : https://youjin43.tistory.com/78
#include<iostream>
#include<algorithm>
using namespace std;

vector<int> nums;
vector<int> op(4); // +, -, *, /
int max_res = -1e9, min_res = 1e9;

int calc(int a, int b, int op){
    if(op==0) return a+b;
    if(op==1) return a-b;
    if(op==2) return a*b;
    if(op==3) return a/b;
}

int dfs(int totol, int idx){
    // base step
    if(idx==nums.size()){
        max_res = max(max_res, totol);
        min_res = min(min_res, totol);
        return totol;
    }

    // recursive step
    for(int i=0;i<4;i++){
        if(op[i]==0) continue;

        op[i]--;
        int res = calc(totol, nums[idx], i);
        dfs(res, idx+1);
        op[i]++;
    }
    return totol;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    // 입력받기 
    int n; cin>>n;
    for(int i=0,a;i<n;i++){ cin>>a; nums.push_back(a); } // 숫자 리스트
    for(int i=0;i<4;i++) cin>>op[i]; // 연산자 갯수 
    
    dfs(nums[0],1);
    cout<<max_res<<'\n'<<min_res;
}