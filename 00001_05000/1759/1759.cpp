//24.8.1(목) 1759 암호만들기
#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;

// L개의 알파벳 소문자들로 구성

// 알파벳 증가하는 순서

int l,c;
char list[16];
string str="aeiou";

deque<char> q;

// 모음 몇개로 구성됐는지
int vCount(){
    int cnt=0;
    for(int i=0;i<q.size();i++){
        char tmp = q[i];
        if(str.find(tmp) != str.npos) cnt++;
    }
    return cnt;
}


void find(int idx,int cnt){
    //base step
    if(cnt==l){
        int tmp = vCount();
        if(tmp && q.size()-tmp>=2){
            for(int i=0;i<l;i++){
                cout<<q[i];
            }cout<<'\n';
        }
        return;
    }
    //recursive step

    for(int i=idx+1;i<c;i++){
        q.push_back(list[i]);
        find(i,cnt+1);
        q.pop_back();
    }
}


int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>l>>c;
    for(int i=0;i<c;i++){
        cin>>list[i];
    }

    sort(list,list+c);

    for(int i=0;i<c;i++){
        q.push_back(list[i]);
        find(i,1);
        q.pop_back();


    }



    
}