/*2752_세수정렬*/
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm> 

int main(){
    int list[3];
    for(int i=0;i<3;i++){
        cin>>list[i];
    }
    sort(list,list+3);

    cout<<list[0]<<" "<<list[1]<<" "<<list[2]<<endl;
}