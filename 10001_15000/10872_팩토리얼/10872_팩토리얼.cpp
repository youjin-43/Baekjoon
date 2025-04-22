/*10872_팩토리얼 240227*/

#include <iostream>
using namespace std;

int main(){
    int a;
    int ret = 1;
    cin>>a;

    for(int i=1;i<=a;i++){
        ret *=i;
    }
    cout<<ret;

}