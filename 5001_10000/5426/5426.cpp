#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main(){
    // ios::sync_with_stdio(0);cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        string tmp;
        cin>>tmp;
        
        int size_=tmp.size(); 
        int side = sqrt(size_);

        for(int i=side-1;i>=0;i--){
            for(int j=0;j<side;j++){
                int idx=i+side*j;
                cout<<tmp[idx];
            }
        }
        cout<<'\n';
    }
    cout<<endl; //씨이이ㅣ이발 이거 안하면 틀리는게 말이 되냐??
}