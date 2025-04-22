//24.7.7(일) 1202 보석도둑
// 그뭐냐 upperbound나 lower bound 이용해보자 

//lower bound = 찾으려는 key 값보다 같거나 큰 숫자가 언제 처음 등장하는지 
//upper bound = key 값을 초과하는 숫자가 언제 처음 등장하는지 -> 이거 이용하면 될것 같은데 

// 아니 왜 얘도 3퍼에서 시간초과???? 아 사실 전꺼랑 다른게 없는것 같긴 한데....아.... 그래도....

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.first<b.first;
}

bool cmp2(pair<int,int> a, pair<int,int> b){
    return a.first < b.first;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int n,k;
    cin>>n>>k;

    vector<pair<int,int> > gems; //무게, 가치
    for(int i=0,m,v;i<n;i++){
        cin>>m>>v;
        gems.push_back(make_pair(m,v));
    }

    sort(gems.begin(),gems.end(),cmp); //무게 기준 오름차순 정렬

    vector<int> bags;
    for(int i=0,tmp;i<k;i++){
        cin>>tmp;
        bags.push_back(tmp);
    }
    sort(bags.begin(),bags.end());//담을 수 있는 무게 기준 오름차순 정렬

    int sum_value=0;
    int check[300000]={0,}; //가방에 넣은 보석인지 체크

    for(int bag=0;bag<k;bag++){ //작은 가방부터 각 가방에 대해 
        // 담을 수 있는 보석 중 가치가 가장 큰걸 담음 
        vector<pair<int,int> >::iterator it = upper_bound(gems.begin(), gems.end(), make_pair(bags[bag],0), cmp2);

        int max_value=0;
        int max_idx=-1;
        for(auto idx = gems.begin(); idx != it; idx++){

            int tmp_idx = idx-gems.begin();
            int tmp_value = (*idx).second;

            if(check[tmp_idx]==0 && tmp_value>max_value){
                max_value = tmp_value;
                max_idx = tmp_idx;
            }
        }
        check[max_idx]=1;
        sum_value+=max_value;
    }


    cout<<sum_value<<'\n';
}
