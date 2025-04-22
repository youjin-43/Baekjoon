//50만번째 소수는 천만을 넘지 않는다.

#include<iostream>
using namespace std;
bool list[10000001];
int main(){

    int k;
    cin>>k;


    int n=2;
    while(n<=10000000){
        if(list[n]){
            n++;
            continue;
        }else{
            k--;
            if(k==0) break;
        }

        int i=2;
        while(n*i<=10000000){
            if(list[n*i]){
                i++;
                continue;
            }
            list[n*i]=1;
            i++;
        }
        n++;
    }
    cout<<n<<endl;

}