//24.7.15(월) 29621 회의실배정2 -> 백트래킹으로 풀어보겠따
// 엥 80에서 틀리는데 -> k번째 회의가 k-1이랑 k+1이랑 안겹친다고 했지 sorting 됐다고는 안함 
// if문은 그대로 가져가고 sorting 시켜봄 

#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(tuple<int,int,int> a,tuple<int,int,int> b){
    if(get<1>(a)==get<1>(b)) return get<0>(a) < get<0>(b);
    return get<1>(a) < get<1>(b);
}

int n;
vector<tuple<int,int,int> > list; 
//get<0>(list[i]) : start
//get<1>(list[i]) : end
//get<2>(list[i]) : 인원

int find(int a, int cnt){
    int start = get<0>(list[a]);
    int end = get<1>(list[a]);
    cnt = cnt+get<2>(list[a]);

    int ret = cnt;
    for(int i=a+1;i<n;i++){
        int next_start = get<0>(list[i]);
        int next_end = get<1>(list[i]);

        // if( next_end<=start || end<=next_start ){ // 안겹치는 경우(전에 오는경우 또는 후에오는 경우)
        if(end<=next_start){
            ret = max(ret,find(i,cnt));
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;

    // test1
    // n=4;
    // list.push_back(make_tuple(10,40,80));
    // list.push_back(make_tuple(30,60,60));
    // list.push_back(make_tuple(50,80,70));
    // list.push_back(make_tuple(70,100,100));


    for(int i=0,a,b,c;i<n;i++){
        cin>>a>>b>>c;
        list.push_back(make_tuple(a,b,c));
    }

    sort(list.begin(),list.end(),cmp);

    int ret =0;
    for(int i=0;i<n;i++){
        ret = max(ret,find(i,0));
    }
    cout<<ret<<'\n';
}