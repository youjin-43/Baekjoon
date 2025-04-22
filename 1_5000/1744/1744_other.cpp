//재원님 코드 
#include<iostream>
#include<queue>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


int main(){
    FASTIO
    freopen("input.txt", "r", stdin);

    priority_queue<int> pqP;
    priority_queue<int,vector<int>,greater<int> > pqN; 

    int n; cin >> n;
    while(n--){
        int d; cin >> d;
        if(d>0)pqP.push(d);
        else pqN.push(d);
    }


    int s= 0;
    while(!pqP.empty()){
        int a, b;
        a=pqP.top();
        pqP.pop();
        if(pqP.empty()) s+=a;
        else {
            b=pqP.top();
            pqP.pop();
            if(a * b > a + b) s+=a*b;
            else s+=a+b;
        }
    }


    while(!pqN.empty()){
        int a, b;
        a=pqN.top();
        pqN.pop();
        if(pqN.empty()) s+=a;
        else {
            b=pqN.top();
            pqN.pop();
            if(a * b > a + b) s+=a*b;
            else s+=a+b;
        }
    }
    cout << s;
}