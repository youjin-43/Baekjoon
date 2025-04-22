//24.8.15(목) 17386 선분교차1
#include<iostream>
#include<vector>
using namespace std;


bool CCW(long long a1,long long a2, long long b1,long long b2, long long c1,long long c2){
    //b가 기준점
    vector<long long> L1;
    L1.push_back(a1-b1);
    L1.push_back(a2-b2);
    
    vector<long long> L2;
    L2.push_back(c1-b1);
    L2.push_back(c2-b2);

    return L1[0]*L2[1]-L1[1]*L2[0]>0;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    vector<long long> a1(2);
    vector<long long> a2(2);

    vector<long long> b1(2);
    vector<long long> b2(2);

    cin>>a1[0]>>a1[1]>>a2[0]>>a2[1]>>b1[0]>>b1[1]>>b2[0]>>b2[1];

    //a 기준 으로 다른 두 점이 어디에 위치하는지 
    long long ret1_1 = CCW(a1[0],a1[1],a2[0],a2[1],b1[0],b1[1]);
    long long ret1_2 = CCW(a1[0],a1[1],a2[0],a2[1],b2[0],b2[1]);

    long long ret2_1 = CCW(b1[0],b1[1],b2[0],b2[1],a1[0],a1[1]);
    long long ret2_2 = CCW(b1[0],b1[1],b2[0],b2[1],a2[0],a2[1]);

    if(ret1_1!=ret1_2 && ret2_1!=ret2_2){
        cout<<1<<'\n';
    }    
    else{
        cout<<0<<'\n';
    }
}