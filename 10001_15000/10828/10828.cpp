#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    stack<int> st;

    int n;// N (1 ≤ N ≤ 10,000)
    cin>>n;
    // n=1;
    cin.ignore();

    string tmp;
    for(int i=0;i<n;i++){
        getline(cin,tmp);
        // tmp = "push 13";

        //push X: 정수 X를 스택에 넣는 연산이다.
        if(tmp[0]=='p' && tmp[1]=='u'){
            string num ="";
            int k=tmp.size()-1;

            while(tmp[k]!=' '){
                num=tmp[k]+num;
                k--;
            }
            st.push(stoi(num));
        }
        // pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
        else if(tmp[0]=='p'&&tmp[1]=='o'){
            if(!st.empty()){
                int top = st.top();
                st.pop();
                cout<<top<<'\n';
            }else{
                cout<<-1<<'\n';
            }
        }
        // size: 스택에 들어있는 정수의 개수를 출력한다.
        else if(tmp[0]=='s'){
            cout<<st.size()<<'\n';
        }
        // empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
        else if(tmp[0]=='e'){
            cout<<st.empty()<<'\n';
        }
        // top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
        else{
            if(!st.empty()){
                cout<<st.top()<<'\n';
            }else{
                cout<<-1<<'\n';
            }
        }
        
    }



}