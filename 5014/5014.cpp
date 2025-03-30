#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int f,s,g,u,d;
    cin>>f>>s>>g>>u>>d;

    if(s+u>f && s-d<1){
        cout<<"use the stairs"<<'\n';
    }else{
        if(g>s){
            if((g-s)%u==abs(d-u) && s+u*((g-s)/u+1)-d==g){
                cout<<(g-s)/u+2<<'\n';
            }else{
                cout<<"use the stairs"<<'\n';
            }
        }
        else if(g<s){
            if((s-g)%d==abs(d-u) && s-d*((s-g)/d+1)+u==g){
                cout<<(s-g)/d+2<<'\n';
            }else{
                cout<<"use the stairs"<<'\n';
            }
        }
        else{
            cout<<0<<'\n';
        }
    }

}