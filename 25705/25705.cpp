#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    string str_n;

    int m;
    string str_m;

    cin>>n>>str_n>>m>>str_m;

    int idx=n-1;
    int ret=0;

    bool include = 1;
    for(int i=0;i<m;i++){

        if(i!=0 && str_m[i-1] == str_m[i]){
            ret+=n;
        }else{
            int tmp=0;

            if(str_n[idx] == str_m[i]){
                ret+=n;
            }else{
                while(str_n[idx] != str_m[i]){
                    idx++;
                    if(idx>n-1) idx-=n;

                    ret++;
                    tmp++;
                    if(tmp>n){
                        cout<<-1<<endl;
                        include=0;
                        break;
                    }
                }
            }
            
        }

        if(include ==0) break;
    }
    if(include){
        cout<<ret<<endl;
    }

}

/*
4
abcd
1
d


*/