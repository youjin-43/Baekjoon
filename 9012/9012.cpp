#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        
        stack<char> st;

        for(int j=0;j<str.size();j++){
            // cout<<"str[i] : "<<str[i]<<endl;
            if(str[j] == '('){
                st.push(str[i]);
                // cout<<"st.size() : "<<st.size()<<endl;
            }else{
                if(st.empty()){
                    cout<<"NO"<<endl;
                    break;
                }else{
                    st.pop();
                    // cout<<"st.size() : "<<st.size()<<endl;
                }   
            }

            if(j == str.size()-1){
                if(st.empty()){
                    cout<<"YES"<<endl;
                }else{
                    cout<<"NO"<<endl;
                }
                
            }
        }

    }
}

/*
6
(())())
(((()())()
(()())((()))
((()()(()))(((())))()
()()()()(()()())()
(()((())()(


1
(((()())()

    
*/