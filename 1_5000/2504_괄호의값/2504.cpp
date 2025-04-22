// 2504_괄호의 값
// 코드 리펙토링
#include<iostream>
#include<stack>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    string str; cin>>str;

    // '(' : -1
    // '[' : -2
    stack<int> st; 
    for(int i=0;i<str.size();i++){
        // // 올바르지 못한 경우 
        // if(str[i]!='(' && str[i]!=')' && str[i]!='[' && str[i]!=']'){
        //     cout<<0<<'\n'; exit(0);
        // }

        char ch = str[i];
        // 닫는 괄호 인경우
        if(ch==')' || ch==']'){
            int expectedOpen = (ch == ')') ? -1 : -2;
            int multiplier = (ch == ')') ? 2 : 3;
        
            int tmp=0;
            // 숫자인경우 
            if(st.size() && st.top()>0){ tmp+=st.top(); st.pop();}

            // 여는 괄호가 나오면 
            if(st.size() && st.top() == expectedOpen){
                if(tmp==0){ tmp += multiplier; st.pop();}
                else{ tmp *= multiplier; st.pop();}

                // 숫자가 또 있으면 처리
                if(st.size() && st.top()>0){ tmp += st.top(); st.pop(); }

                st.push(tmp);
                continue;
            }else{
                // 올바르지 못한 경우 
                cout<<0<<'\n';
                exit(0);
            }
        }
        // 여는 괄호이면 그냥 push
        else{
            //'(' : -1, '[' : -2
            if(ch=='(') st.push(-1);
            else st.push(-2);
        }
    }

    if(st.size()==1 && st.top()>0) cout<<st.top()<<'\n';
    else cout<<0<<'\n';
    
}