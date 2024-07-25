//24.7.8(월) 29621 회의실배정2 -> 인원 최대 

#include<iostream>
#include<algorithm>
using namespace std;


// bool cmp(tuple<int,int,int> a,tuple<int,int,int> b){
//     if(get<1>(a)==get<1>(b)) return get<0>(a) < get<0>(b);
//     return get<1>(a) < get<1>(b);
// }

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int n;cin>>n;

    vector<tuple<int,int,int> > list;
    for(int i=0,a,b,c;i<n;i++){
        cin>>a>>b>>c;
        list.push_back(make_tuple(a,b,c));
    }


    // test1
    // int n=6;
    // vector<tuple<int,int,int>> list;
    // list.push_back(make_tuple(10,40,80));
    // list.push_back(make_tuple(30,60,60));
    // list.push_back(make_tuple(50,80,70));
    // list.push_back(make_tuple(70,100,100));
    // list.push_back(make_tuple(90,120,40));
    // list.push_back(make_tuple(110,140,50));


    //test2
    // int n=3;
    // vector<tuple<int,int,int>> list;
    // list.push_back(make_tuple(0,3,10));
    // list.push_back(make_tuple(0,4,20));
    // list.push_back(make_tuple(0,5,30));

    // sort(list.begin(),list.end(),cmp);

    int dp[25];//max 인원
    int end[25];//끝나는 시간

    dp[0]=get<2>(list[0]);
    end[0]=get<1>(list[0]);

    for(int i=1;i<n;i++){
        
        if(end[i-1]<=get<0>(list[i])){
            dp[i]=dp[i-1]+get<2>(list[i]);
            end[i]=get<1>(list[i]);
        }
        else{
            int idx= upper_bound(end,end+i,get<0>(list[i]))-end; //이번 회의를 시작 할 수 있었던 인덱스를 찾음
            int tmp = dp[idx]-get<2>(list[idx])+get<2>(list[i]); 

            dp[i]=max(dp[i-1],tmp); 
            end[i]=get<1>(list[i]);
        }
        
    }

    cout<<dp[n-1]<<endl;
}