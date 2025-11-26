#include<iostream>
#include<string>
#include<stack>
using namespace std;

double list[26];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int n; cin>>n;
    string str; cin>>str;
    for(int i=0;i<n;i++) cin>>list[i];

    stack<double> st; 
    double ret=0;
    for(auto s:str){
        if(s == '*' || s=='+' || s=='/' || s=='-'){
            double tmp = st.top(); st.pop();
            if(s == '*') st.top() *= tmp;
            else if(s=='+') st.top() += tmp;
            else if(s=='/') st.top() /= tmp;
            else st.top() -= tmp;
        }else st.push(list[s-'A']);
    }
    cout<<fixed;
    cout.precision(2);
    cout<<st.top()<<'\n';
    
}