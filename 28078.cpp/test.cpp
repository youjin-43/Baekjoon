#include<iostream>
#include<deque>
using namespace std;
int main(){
    deque<int> q;
    q.push_back(0);
    q.push_back(1);
    q.push_back(2);
    q.push_front(3);

    //앞부터 인덱스
    for(int i=0;i<q.size();i++){
        cout<<q[i]<<' ';
    }cout<<endl;
    // 3 0 1 2

    //iterater도 앞부터
    cout<<find(q.begin(),q.end(),0)  - find(q.begin(),q.end(),3) <<endl; //1
    cout<<find(q.begin(),q.end(),3)  - find(q.begin(),q.end(),0) <<endl; //-1

    
}