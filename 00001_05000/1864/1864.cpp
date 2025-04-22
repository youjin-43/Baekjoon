#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main(){
    string tmp;
    
    while(cin>>tmp){
        if(tmp == "#")break;
        
        int ret=0;
        for(int i=0;i<tmp.size();i++){
            //-는 0에 대응한다.
            if(tmp[i]=='-'){
                
            }
            //\는 1에 대응한다.
            else if(tmp[i]=='\\'){
                ret+=pow(8,tmp.size()-i-1)*1;
            }
            //(는 2에 대응한다.
            else if(tmp[i]=='('){
                ret+=pow(8,tmp.size()-i-1)*2;
            }
            //@는 3에 대응한다.
            else if(tmp[i]=='@'){
                ret+=pow(8,tmp.size()-i-1)*3;
            }
            //?는 4에 대응한다.
            else if(tmp[i]=='?'){
                ret+=pow(8,tmp.size()-i-1)*4;
            }
            //>는 5에 대응한다.
            else if(tmp[i]=='>'){
                ret+=pow(8,tmp.size()-i-1)*5;
            }
            //&는 6에 대응한다.
            else if(tmp[i]=='&'){
                ret+=pow(8,tmp.size()-i-1)*6;
            }
            //%는 7에 대응한다.
            else if(tmp[i]=='%'){
                ret+=pow(8,tmp.size()-i-1)*7;
            }
            ///는 -1에 대응한다.
            else{
                ret+=pow(8,tmp.size()-i-1)*(-1);
            }
        }
        cout<<ret<<endl;
    }
}