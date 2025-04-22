#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int P1, P2, P3, X1, X2, X3;
    cin>>P1>>P2>>P3>>X1>>X2>>X3;

    int n=X1;
    while(n<1000000000){
        if(n%P2==X2 && n%P3==X3){
            cout<<n<<'\n';
            break;
        }
        n+=P1;
    }
    if(n>=1000000000) cout<<-1<<endl;
}