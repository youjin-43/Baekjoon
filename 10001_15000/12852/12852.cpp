#include<iostream>
#include<climits>
#include<algorithm>
#include<stack>
using namespace std;

int cnt[1000001];
int from[1000001];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin>>n;
    for(int i=0;i<n;i++) cnt[i]=INT_MAX;

    cnt[n]=0;
    from[n]=0;
    for(int i=n;i>0;i--){
        //3으로 나누기
        if(i%3==0){
            if(cnt[i/3]>cnt[i]+1){
                cnt[i/3]=cnt[i]+1;
                from[i/3]=i;
            }
        }

        //2로 나누기
        if(i%2==0){
            if(cnt[i/2]>cnt[i]+1){
                cnt[i/2]=cnt[i]+1;
                from[i/2]=i;
            }
        }

        //1빼기 
        if(cnt[i-1]>cnt[i]+1){
            cnt[i-1]=cnt[i]+1;
            from[i-1]=i;
        }
    }
    cout<<cnt[1]<<'\n';

    //과정 출력
    stack<int> st;
    st.push(from[1]);
    while(st.top()){
        st.push(from[st.top()]);
    }
    st.pop();
    while(!st.empty()){
        cout<<st.top()<<' ';
        st.pop();
    }
    cout<<1<<endl;
}