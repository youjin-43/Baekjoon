//"N명의 집단에서 각 사람의 덩치 등수는 자신보다 더 "큰 덩치"의 사람의 수로 정해진다."

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(tuple<int,int,int> a, tuple<int,int,int>b){
    if(get<0>(a) == get<0>(b)){
        return get<1>(a)>get<1>(b);
    }else{
        return get<0>(a)>get<0>(b);
    }

}

int main(){
    int n;
    cin>>n;
    vector<tuple<int,int,int>> list;
    int rankList[50];

    int a,b,c=0;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        list.push_back(make_tuple(a,b,c++));
    }

    sort(list.begin(),list.end(),cmp);

    // for(int i=0;i<n;i++){
    //     cout<<"num : "<<get<2>(list[i])<<" x:"<<get<0>(list[i])<<" y:"<<get<1>(list[i])<<endl;
    // }cout<<endl;

    int cnt=1;
    rankList[get<2>(list[0])] = cnt;

    for(int i=1;i<n;i++){
        // cout<<"num : "<<get<2>(list[i])<<" x:"<<get<0>(list[i])<<" y:"<<get<1>(list[i])<<endl;
        cnt=0;
        for(int j=i-1;j>=0;j--){
            // cout<<"       num : "<<get<2>(list[j])<<" x:"<<get<0>(list[j])<<" y:"<<get<1>(list[j])<<endl;
            if(get<0>(list[j]) > get<0>(list[i]) && get<1>(list[j]) > get<1>(list[i]) ){
                // cout<<"hit"<<endl;
                cnt++;
            }
        }
        rankList[get<2>(list[i])] = cnt+1;


    }

    for(int i=0;i<n;i++){
        cout<<rankList[i]<<' ';
    }cout<<endl;


}

/*
5
55 185
55 183
88 186
60 175
46 155

5
55 185
58 183
88 186
60 190
46 155



5
55 185
55 183
55 186
55 175
55 155

*/