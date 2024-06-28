#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    // string a = "A";
    // string b = "BBAB";

    string a;
    string b;
    cin>>a>>b;

    int i = b.size()-1;
    char tmp;
    while(a.size() != b.size()){
        if(b[i] == 'A' || b[i] == 'B'){
            tmp = b[i];
            if(i == b.size()-1){
                b.erase(b.end()-1);
            }else{
                b.erase(b.begin());
            }
        
            if(tmp == 'A'){
                if(i==0){
                    
                }else{
                    i= b.size()-1;
                }

            }
            else{
                if(i==0){
                    i = b.size()-1;
                }else{
                    i=0;
                }
            }

        }else{
            break;
        }


    }

    if(b.size() ==1){
        if(a==b){
            cout<<1<<endl;
        }else{
            cout<<0<<endl;
        }

    }else{
        if(i==0){
            reverse(b.begin(), b.end());
        }

        if(a==b){
            cout<<1<<endl;
        }else{
            cout<<0<<endl;
        }
    }
}