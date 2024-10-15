//24.8.14(수) 2493 탑
#include<iostream>
#include<stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    
    // freopen("input.txt", "r", stdin);

    int n;cin>>n;
    stack<pair<int,int> > st;
    for(int i=0,tmp;i<n;i++){
        cin>>tmp;

        if(st.empty()){
            cout<<0<<' ';
        }else{
            while(!st.empty() && st.top().first<tmp){
                st.pop();
            }

            if(st.empty()){
                cout<<0<<' ';
            }else{
                cout<<st.top().second<<' ';
            }
        }
        st.push(make_pair(tmp,i+1));
    }
}