#include<iostream>
#include<math.h>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        double x1,y1,r1,x2,y2,r2;
        cin>>x1>>y1>>r1>>x2>>y2>>r2;

        double distance = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)); //두 터렛 사이의 거리
        
        // 둘의 위치가 같은경우
        if(x1 == x2 && y1==y2){ 
            if(r1 != r2){
                cout<<0<<endl;
            }else{
                cout<<-1<<endl;
            }
        }
        //외접, 내접 하는 경우
        else if(distance == r1+r2 || distance+min(r1,r2) == max(r1,r2)){
            cout<<1<<endl;
        }
        else if(distance+min(r1,r2) < max(r1,r2) || distance > r1+r2){
            cout<<0<<endl;
        }
        else{
            cout<<2<<endl;
        }
        
    }
}
/*
0 0 4 2 0 2
-> 1
0 0 4 1 0 2
-> 0

*/