    //25.03.31(일) 10799 쇠막대기
    #include<iostream>
    #include<stack>
    using namespace std;
    int main(){
        ios::sync_with_stdio(0);cin.tie(0);
        
        char list[100001]; cin>>list;
    
        stack<char> st;
        st.push(list[0]);
        
        bool isLaser=0;
        int ret=0;
    
        int i=1;
        while(list[i] !='\0'){
             // '(' 인 경우 
            if(list[i] =='('){
                st.push('(');
                isLaser=0;
            }
            // ')' 인 경우 
            else{
                st.pop();
    
                if(isLaser){ // 이전이 ')'이면 막대 끝!
                    ret++;
                } else { // 이전이 '('이면 레이저!
                    isLaser=1;
                    ret+=st.size(); // 현재 열려있는 막대 수만큼 조각
                }
            }
            i++;
        }
        cout<<ret<<'\n';
    }