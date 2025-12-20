//2836 수상택시
#include<iostream>
#include<algorithm>
using namespace std;

vector<pair<int,int>> vec_r;
vector<pair<int,int>> vec_l;

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second<b.second;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    // freopen("input.txt","r",stdin);

    int n,m,s,e; cin>>n>>m;
    for(int k=0,a,b;k<n;k++){
        cin>>a>>b;
        if(a<b) vec_r.push_back({a,b}); // 오른쪽으로 가는 경우
        else vec_l.push_back({a,b}); // 왼쪽으로 가는 경우 
    }
    vec_r.push_back({0,m}); // 최종 도착지 

    sort(vec_r.begin(),vec_r.end(),cmp);
    sort(vec_l.begin(), vec_l.end(),cmp);


    long long ret=0;
    int cur=0,r_idx=0,l_idx=0;
    while(r_idx!=vec_r.size() || l_idx != vec_l.size()){

        // 들렸다 가기 
        if(l_idx < vec_l.size() && vec_l[l_idx].first <= vec_r[r_idx].second){

            int p=vec_l[l_idx].first,q=vec_l[l_idx].second;
            l_idx++;

            // 여러 왼쪽 구간이 겹치면 병합해서 한 번에 처리
            while(1){
                if(l_idx>=vec_l.size()) break;
                if(
                    p>=vec_l[l_idx].first && vec_l[l_idx].first >=q 
                    || p>=vec_l[l_idx].second && vec_l[l_idx].second>=q

                    || vec_l[l_idx].second<=p && p<=vec_l[l_idx].first
                    || vec_l[l_idx].second<=q && q<=vec_l[l_idx].first
                ){
                    p = max(p,vec_l[l_idx].first);
                    q = min(q,vec_l[l_idx].second);
                    l_idx++;
                    continue;
                }
                break;
            }

            ret+=p-cur;
            ret+=(p-q)*2;
            cur=p;
            continue;
        }

        // 쭈욱 전진 
        else if(r_idx<vec_r.size()){
            ret+=vec_r[r_idx].second-cur;
            cur=vec_r[r_idx].second;
            r_idx++;
            continue;
        }
    }
    cout<<ret<<'\n';
}