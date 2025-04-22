//LIS 벡터는 최장 증가 부분수열 자체를 의미하지 않음 -> 바로 출력하는 게 아니라 실제 해를 복원하는 로직이 더 있어야 함!!
//전에는 하나를 미리 추가하고 back으로 접근했는데, 그냥  end 쓰면 됨!!! 
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int list[1000000]; //입력저장 
int idx[1000000]; //LIS에서의 위치 
vector<int> LIS;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("input.txt","r",stdin);

    int n; cin>>n;
    for(int i=0,tmp;i<n;i++){
        cin>>tmp; list[i]=tmp;
        auto it = lower_bound(LIS.begin(),LIS.end(),tmp);
        if(it ==LIS.end()){
            LIS.push_back(tmp);
            idx[i]=LIS.size()-1;
        }else{
            *it=tmp;
            idx[i]=distance(LIS.begin(), it);
        }
    }
    cout<<LIS.size()<<'\n';

    // cout<<"복원 전 LIS : "; 
    // for(int i=0;i<LIS.size();i++) cout<<LIS[i]<<' ';
    // cout<<'\n';

    //실제 해 복원 
    vector<int> ans;
    int LIS_idx=LIS.size()-1;
    for(int i=n-1;i>=0;i--){
        if(idx[i]==LIS_idx){
            ans.push_back(list[i]);
            LIS_idx--;
        }
    }

    //복원된 해 출력
    // cout<<"복원 후 LIS : "; 
    for(int i=ans.size()-1;i>=0;i--) cout<<ans[i]<<' ';
    cout<<'\n';
}