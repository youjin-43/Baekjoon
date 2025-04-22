#include<iostream>
#include<stack>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int n; cin>>n;
    int ret=0;
    stack<int> st;
    long num;
    while(n--){
        cin>>num;
        if(st.empty()){
            st.push(num);
        }else{
            while(!st.empty() && st.top()<=num){
                st.pop();
            }

            ret+=st.size();
            st.push(num);
        }
    }

    cout<<ret<<endl;
}