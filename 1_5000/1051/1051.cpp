#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    string list[50]={
                    "42101",
                    "22100",
                    "22101"
                    };
    
    int n=3,m=5;

    // string list[50];
    // int n,m;
    // cin>>n>>m;
    // for(int i=0;i<n;i++){
    //     cin>>list[i];
    // }

    int size = min(n,m)-1;
    bool end =0;
    while(size>0){
        for(int i=0;i+size-1<n;i++){
            for(int j=0;j+size-1<m;j++){
                // char d = list[i][j];
                // char a = list[i+size][j];
                // char b = list[i][j+size];
                // char c = list[i+size][j+size];
                if(list[i][j]==list[i+size][j] && list[i][j]==list[i][j+size] && list[i][j]==list[i+size][j+size]){
                    end =1;
                    break;
                }
            }
            if(end) break;
        }
        if(end) break;
        size--;
    }
    size++;
    cout<<size*size<<endl;
}