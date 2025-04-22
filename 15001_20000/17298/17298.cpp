//24.9.28(토) 17298 오큰수
#include<iostream>
#include<stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int n; cin>>n;
    int ret[1000000]={0,};
    stack<pair<int,int> > st; //value, idx
    
    for(int i=0,v;i<n;i++){
        cin>>v;

        //새로들어운 수가 top보다 크면 커버하는거 다 pop 하고 push
        while(!st.empty() && st.top().first<v){
            ret[st.top().second] = v;
            st.pop();
        }
        st.push(make_pair(v,i));
    }

    for(int i=0;i<n;i++){
        if(ret[i]==0){
            cout<<-1<<' ';
        }else{  
            cout<<ret[i]<<' ';
        }
    }
}