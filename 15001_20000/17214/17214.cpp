//24.8.9(금) 17214 다항 함수의 적분
#include<iostream>
#include<string>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    string str; cin>>str;

    //첫번째 항 계수
    int num1=0;
    bool end=0;
    int i=0;

    if(str[0]=='-'){
        i++;
    }

    for(;i<str.size();i++){
        
        if(str[i]=='x'){
            end=1;
            break;
        }
        int tmp= str[i]-'0';
        num1=num1*10+tmp;
    }

    if(str[0]=='-') num1*=-1;

    if(end==0){
        if(num1==0){
            cout<<'W'<<'\n';
        }else{ 
            if(num1==1){
                cout<<"x+W"<<'\n';
            }else if(num1==-1){
                cout<<"-x+W"<<'\n';
            }
            else{
                cout<<num1<<"x+W"<<'\n';
            }
            
        }
        
        exit(0);
    }

    if(num1==0) num1=1;

    i++;//x
    int idx=i;
    i++;//+
    int num2=0;//상수 
    for(;i<str.size();i++){
        int tmp= str[i]-'0';
        num2=num2*10+tmp;
    }
    if(str[idx]=='-') num2*=-1;
    
    if(num1/2==1){
        cout<<"xx";
    }else if(num1/2==-1){
        cout<<"-xx";
    }
    else{
        cout<<num1/2<<"xx";
    }
    

    if(num2==0){
        cout<<"+W"<<'\n';
    }else{
        if(num2>1){
            cout<<"+"<<num2<<"x+W"<<'\n';
        }else if(num2==1){
            cout<<"+"<<"x+W"<<'\n';
        }else if(num2==-1){
            cout<<"-"<<"x+W"<<'\n';
        }
        else{
            cout<<num2<<"x+W"<<'\n';
        }
        
    }

    
    
}