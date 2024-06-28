#include<iostream>
#include <string>
using namespace std;
int main(){
    int t;
    cin>>t;

    while(t--){
        int num;
        cin>>num;

        string str_p="";
        string str_q="";
        string str;
        cin>>str;

        int j=0;
        while(str[j]!='/'){
            str_p+=str[j];
            j++;
        }
        j++;

        while(j<str.size()){
            str_q+=str[j];
            j++;
        }

        long p = stol(str_p);
        long q = stol(str_q);

        // cout<<"p :"<<p<<" q : "<<q<<endl;

        long ret_p =q;
        long ret_q;
        
        //첫번쨰 경우의 수 : 같은 부모를 가지고 있는 경우
        if(p<q){
            ret_q = q-p;
        }
        //두번째 : 다음층으로 넘어가는 경우
        else if(q==1){
            ret_p=1;
            ret_q=p+1;
        }
        //세번째 : 다른 부모를 가지고 있는 경우
        else if(q==2){
            ret_q=p;
        }
        else{
            long i = 2*(p/q+1)-1;
            ret_q=i*q-p;
            
        }

        cout<<num<<' '<<ret_p<<'/'<<ret_q<<endl;

    }

}