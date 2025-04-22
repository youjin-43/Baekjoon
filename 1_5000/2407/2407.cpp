//24.11.9(토)
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


string Add(string str1, string str2){
    int s = max(str1.size(),str2.size());

    int check =0;
    string str_ret="";
    for(int i=0;i<s;i++){
        int pos1 = str1.size()-i-1; 
        int pos2 = str2.size()-i-1;
        
        int a=0;
        if(0<=pos1) a=str1[pos1]-'0';

        int b=0;
        if(0<=pos2) b=str2[pos2]-'0';
    
        int ret = a+b + check;

        if(ret>=10){
            check=1;
            ret%=10;
        }else{
            check=0;
        }

        ret+='0';
        str_ret=(char)ret+str_ret;
    }
    
    //마지막에 체크가 있는지 확인 
    if(check) str_ret="1"+str_ret;
    return str_ret;
}

string mem[101][101];
string Cal_nCm(string n, string m){  //nCm = n-1Cm + n-1Cm-1
    int n_int = stoi(n);
    int m_int = stoi(m);
    
    //baseStep
    if(m_int==0 || n_int == m_int){
        mem[m_int][n_int]="1";
        return "1";
    }
    
    //recursiveStep
    string first; //Cal_nCm(n-1,m)
    if(mem[n_int][m_int-1] != ""){
        first=mem[m_int][n_int-1];
    }else{
        first = Cal_nCm(to_string(n_int-1),m);
    }
    
    string secoond; //Cal_nCm(n-1,m-1)
    if(mem[m_int-1][n_int-1]!= ""){
        secoond=mem[m_int-1][n_int-1];
    }else{
        secoond = Cal_nCm(to_string(n_int-1),to_string(m_int-1));
    }

    string ret= Add(first,secoond);
    mem[m_int][n_int]=ret;
    return ret;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
   
    int n,m; cin>>n>>m;
    // int n=5,m=3;
    for(int i=0;i<=m;i++) for(int j=0;j<=i;j++) mem[i][j]="";
    
    cout<<Cal_nCm(to_string(n),to_string(min(m,n-m)))<<endl;;

}