//24.9.22(일) 크게 만들기 -> 앞자리수가 크면 암튼 큰거!
#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
    freopen("input.txt", "r", stdin);

    int n,k;cin>>n>>k;
    string str; cin>>str;
    deque<char> dq; //뒤로 넣고 앞부터 출력할거라

    dq.push_back(str[0]);
    for(int i=1;i<n;i++){

        // if(!k) break; // k가 남아있지 않다면 끝냄 -> 이거 넣으면 나머지 str을 dq에 따로 넣어줘야하네

        while(k && !dq.empty() && dq.back()<str[i]){
            k--;
            dq.pop_back();
        }
        dq.push_back(str[i]);


    }

    //k가 남은 경우 그냥 뒤에서 부터 빼주면 ㅇㅋ
    while(k){
        dq.pop_back();
        k--;
    }

    //출력
    while(!dq.empty()){
        cout<<dq.front();
        dq.pop_front();
    }
}