#include<iostream>
#include<vector>
#include<climits>
#include<stack>
#include<algorithm>
using namespace std;

vector<int> nums;
vector<int> opers;// +,-,*,/ 

int ret_max=INT_MIN,ret_min = INT_MAX;

stack<pair<int,int>> st; // 숫자면 0, 연산자면 1

void Calc(){
    // 스택 초기화 
    while(st.size()) st.pop();

    int idx_n=0,idx_o=0;
    while(idx_n!=nums.size()){
        // 스택이 비었거나 top이 연산자인 경우 숫자 푸시 
        if(st.empty() || st.top().second){
            st.push({nums[idx_n],0});
            idx_n++;
        }

        if(idx_o==opers.size()) break;

        // 다음에 들어올 연산자에 따라 
        if(opers[idx_o]==2){ // 곱하기
            st.top().first*=nums[idx_n];
            idx_n++;
        }
        else if(opers[idx_o]==3){ // 나누기
            st.top().first/=nums[idx_n]; // 몫만 취한다. 
            idx_n++;
        }
        // 나머지는 그냥 푸시 
        else st.push({opers[idx_o],1});
        idx_o++;
    }

    // 남아있는 스택 계산
    int ret=0;
    while(st.size()>1){
        int tmp = st.top().first; st.pop();
        int op = st.top().first; st.pop();

        if(op==0) ret+=tmp;
        else if(op==1) ret-=tmp; 
    }
    ret+=st.top().first; st.pop();

    // 정답 갱신 
    ret_max=max(ret,ret_max);
    ret_min=min(ret,ret_min);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    // 입력받기
    int cnt; cin>>cnt;
    for(int i=0,tmp;i<cnt;i++){ cin>>tmp; nums.push_back(tmp);}
    for(int i=0,tmp;i<4;i++){ cin>>tmp; while(tmp--) opers.push_back(i);}
    
    // 모든 경우의 수 확인 
    do Calc();
    while(next_permutation(opers.begin(),opers.end()));

    cout<<ret_max<<'\n'<<ret_min<<'\n';
}