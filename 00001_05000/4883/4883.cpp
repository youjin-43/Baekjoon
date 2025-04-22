#include<iostream>
#include<climits>
using namespace std;

int main(){
    int cnt=1;
    while(true){
        int list[100000*3+1][2];

        int n;
        cin>>n;
        if(n==0) break;

        for(int i=1;i<=n;i++){
            cin>>list[3*i-2][0];
            cin>>list[3*i-1][0];
            cin>>list[3*i][0];

            //최소비용 초기화
            list[3*i-2][1]=INT_MAX;
            list[3*i-1][1]=INT_MAX;
            list[3*i][1]=INT_MAX;
        }

        int start =2;
        int end = 3*n-1;

        //start 먼저 채움
        for(int i=1;i<=4;i++){
            list[start+i][1] = list[start][0]+list[start+i][0];
        }

        //4부터 end까지 dp
        int i=3;
        int tmp;
        while(i<end){
            //right
            for(int k=2;k<=3;k++){
                tmp = list[i][1]+list[i+k][0];
                // cout<<"i+k : "<<i+k<<" "<<tmp<<endl;

                if(tmp<list[i+k][1]) list[i+k][1] = tmp;
                
            }
            i++;

            //left
            for(int k=1;k<=4;k++){
                if(k==2) continue;

                tmp = list[i][1]+list[i+k][0];
                // cout<<"i+k : "<<i+k<<" "<<tmp<<endl;

                if(tmp<list[i+k][1]) list[i+k][1] = tmp;
                
            }
            i++;

            //mid
            for(int k=1;k<=4;k++){
                tmp = list[i][1]+list[i+k][0];
                // cout<<"i+k : "<<i+k<<" "<<tmp<<endl;

                if(tmp<list[i+k][1]) list[i+k][1] = tmp;
                
            }
            i++;
        }

        // cout<<"[dp]"<<endl;
        // for(int i=0;i<3*n;i++){
        //     cout<<i<<" : "<<list[i][1]<<endl;
        // }cout<<endl;

        cout<<cnt<<". "<<list[end][1]<<endl;
        cnt++;
    }
    return 0;

}

/*
4
13 7 5
7 13 6
14 3 12
15 6 16

4
13 7 -900
7 13 6
14 3 12
15 6 16


*/