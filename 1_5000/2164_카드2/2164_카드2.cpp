/*240215(목) 2164_카드2*/

#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<int> list;
    int n;

    cin>>n;

    for(int i =1;i<=n;i++){
        list.push(i);
    }


    while(list.size() !=1){
        //버리고
        list.pop();
        if(list.size()==1){
            break;
        }
        //넘기고
        list.push(list.front());
        list.pop();
    }
    cout<<list.front();

}