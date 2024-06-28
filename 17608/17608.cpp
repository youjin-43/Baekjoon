#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;

    vector<int> list;

    int tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        list.push_back(tmp);
    }

    int max=list[n-1];
    int ret=1;
    for(int i=n-2;i>=0;i--){
        if(list[i]>max){
            max=list[i];
            ret++;
        }
    }

    cout<<ret<<endl;

}