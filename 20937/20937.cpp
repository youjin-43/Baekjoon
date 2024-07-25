//24.7.5(금) 20937 떡국

#include<iostream>
#include<algorithm>

using namespace std;

#define NUM 500000

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int list[NUM];
    
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>list[i];
    }

    //tets3
    // int n=12;
    // int list[NUM]={1,2,3,4,1,2,3,4,1,2,3,4};

    sort(list,list+n,greater<int>());

    // cout<<"list : ";
    // for(int i=0;i<n;i++){
    //     cout<<list[i]<<' ';
    // }cout<<endl;

    int ret=0;
    int check[NUM]={0,};
    int s;
    for(int i=0;i<n;i++){

        if(!check[i]){
            s = list[i];
            check[i]=1;
            ret++;

            for(int j=i+1;j<n;j++){
                if(!check[j] && s>list[j]){
                    check[j]=1;
                    s=list[j];
                }
            }
        }
    }

    cout<<ret<<endl;
}