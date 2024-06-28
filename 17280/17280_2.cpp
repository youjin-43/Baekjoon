//24.6.28(금) 17280 카풀 매칭

//시간초과 나는 코드

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second){
        return  a.first < b.first;
    }else{
        return a.second < b.second;
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;

        //입력받고 소팅
        int visiter[100000];
        for(int i=0;i<n;i++){
            cin>>visiter[i];
        }
        sort(visiter,visiter+n);

        // cout<<"\nsorted visiter : ";
        // for(int i=0;i<n;i++) cout<<visiter[i]<<' ';
        // cout<<endl;

        vector<pair<int,int> > list(m);
        for(int i=0;i<m;i++){
            cin >> list[i].first >> list[i].second;
        }

        sort(list.begin(),list.end(),cmp);

        // cout<<"sorted"<<endl;
        // for(int i=0;i<m;i++){
        //     cout<<list[i].first<<' '<<list[i].second<<endl;
        // }

        //멀리가는 손님부터 그리디로 배치
        int ret=0;

        bool check[100000]={0,};
        for(int i=n-1;i>=0;i--){
            //탈수 있는 차 중에서 시작지점이 가장 높은 차에 배치.
            int max_dix=-1;
            int max_dis=0;

            for(int j=m-1;j>=0;j--){
                //이미 배치된 차면 넘어감
                if(check[j]==1) continue;
                if(list[j].second<visiter[i]) break;

                if(visiter[i]<=list[j].second && list[j].first<=visiter[i]){
                    if(max_dis<list[j].first){
                        max_dis=list[j].first;
                        max_dix=j;
                    }
                }
            }

            if(max_dix!=-1){
                check[max_dix]=1;
                ret++;
            }
        }
        cout<<ret<<endl;

    }
}