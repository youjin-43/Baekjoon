#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    int n;
    cin>>n; // N은 2 이상 100,000 이하

    int pos[100000];
    int neg[100000];

    int a,s=0,t=0;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a>=0){
            pos[s]=a;
            s++;
            // cout<<"s : "<<s<<"  pos[s-1] : "<<pos[s-1]<<endl;

        }else{
            neg[t]=a;
            t++;
            // cout<<"t : "<<t<<"    neg[t-1] : "<<neg[t-1]<<endl;
        }
    }
    // cout<<"s : "<<s<<"   t: "<<t<<endl;

    sort(pos,pos+s);
    sort(neg,neg+t);

    cout<<"pos :";
    for(int i=0;i<s;i++){
        cout<<pos[i]<<" ";
    }cout<<endl;
    cout<<"neg : ";
    for(int i=0;i<t;i++){
        cout<<neg[i]<<" ";
    }cout<<endl;


    int min =INT_MAX;
    int ret_s,ret_t;
    for(int i=0;i<s;i++){
        // cout<<" i: "<<i<<endl;
        for(int j= t-1;j>=0;j--){
            int tmp = pos[i]+neg[j];
            // cout<<"tmp : "<<tmp<<endl;
            if(abs(tmp)<min){
                // cout<<"hit"<<endl;
                min = abs(tmp);
                ret_s = i;
                ret_t = j;
                break;
            }
        }
    }
    
    cout<<neg[ret_t]<<" "<<pos[ret_s]<<endl;

}

/*
5
-2 4 -99 -1 98
-> -99 98


6
1 2 3 4 5 -6
pos :1 2 3 4 5 
neg : -6 
-6 5

6
1 2 3 4 5 -1
pos :1 2 3 4 5 
neg : -1 
-1 1

8
1 2 3 4 5 -3 -14 -2
*/