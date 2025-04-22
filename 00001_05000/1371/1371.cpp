#include<iostream>
using namespace std;
int main(){
    int list[26]={0,};

    for(int k=0;k<50;k++){
        string str;
        getline(cin,str);
        // if(str =="") break;
        
        for(int i=0;i<str.size();i++){
            if(str[i]==' ') continue;
            list[str[i]-'a']++;
        }    
    }
    
    int max=-1;
    for(int i=0;i<26;i++){
        if(max<list[i]){
            max=list[i];
        }
    }

    for(int i=0;i<26;i++){
        if(list[i]==max){
            char ret = 'a'+i;
            cout<<ret;
        }
    }
    
    
}