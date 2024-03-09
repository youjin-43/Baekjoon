/*9461_파도반수열
2023.11.26(일)*/

#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;//(1 ≤ N ≤ 100)
        cin>>n;

        int64_t list[101]={0,1,1,1};

        if(n<4){
            cout<<1<<endl;
        }else{
            int i = 4;
            while(true){
                list[i] = list[i-2]+list[i-3];
                i++;
                if(i>n){
                    break;
                }
            }
            cout<<list[n]<<endl;
        }
        
    }//while

}