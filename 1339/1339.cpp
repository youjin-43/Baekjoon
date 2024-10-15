//24.9.28(토) 1339 단어수학
#include<iostream>
#include<string>
#include<queue>
#include<cmath>
#include<map>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int n;cin>>n; // N(1 ≤ N ≤ 10)

    vector<string> str_list;

    //가중치 구하기
    int w_arr[26]={0,};
    
    string str;
    for(int i=0;i<n;i++){
        cin>>str; 
        str_list.push_back(str);

        for(int idx=str.size()-1;idx>=0;idx--){
            int pos = str.size()-1 - idx; //1의 자리부터 
            w_arr[str[idx]-'A']+= pow(10,pos);
        }
    }

    //가중치가 큰것부터 숫자 할당
    priority_queue<pair<int,int> > pq; // 가중치, 아스키코드-'A'
    for(int i=0;i<26;i++){
        pq.push(make_pair(w_arr[i],i));
    }

    int num=9;
    map<char,int> map_;
    while(!pq.empty()){
        int c = pq.top().second;
        pq.pop();

        map_['A'+c]=num--;

        if(pq.top().first==0) break;
    }

    //문자들을 숫자로 바꾸고 합 구하기
    int ret=0;
    for(string str: str_list){
        for(int i=0;i<str.size();i++){
            str[i]=map_[str[i]]+'0';
        }
        ret+=stoi(str);
    }

    cout<<ret<<endl;

}
