#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;


int main(){
    int n;
    cin>>n; // N은 2 이상 100,000 이하
    int list[100000];
    for(int i=0;i<n;i++){
        cin>>list[i];
    }

    //test1
    // int n=8;
    // int list[8] = {1, 2, 3, 4, 5, -3, -14, -2};

    //test2
    // int n=5;
    // int list[5] = {-2, 4, -99, -1, 98};

    //test3
    // int n=3;
    // int list[3] = {3,2,1};

    //test4
    // int n=3;
    // int list[3]={-3, -1, -2};

    sort(list,list+n);


    // cout<<"list : ";
    // for(int i=0;i<n;i++){
    //     cout<<list[i]<<' ';
    // }cout<<endl;


    int start=0;
    int end=n-1;

    int min = INT_MAX;
    int ret_s,ret_e;
    int sum;

    while(start !=end){
        sum = list[start]+list[end];

        if(min>abs(sum)){
            min=abs(sum); 
            ret_s=start; 
            ret_e=end;
        } 

        if(sum ==0) break;

        if(sum>0){
            end--;
        }else{
            start++;
        }

    }

    cout<<list[ret_s]<<' '<<list[ret_e]<<endl;
}



/*

3
-1 -2 -3
-> -2 -1


7 
1 2 3 4 5 -3 -14

*/