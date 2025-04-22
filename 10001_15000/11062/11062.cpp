

#include<iostream>
#include<algorithm>

using namespace std;
int dp[1000][1000] = {0,};
int list[1000];
// int list[9] = {1, 1, 1, 1, 2, 2, 2, 2, 2};

int Game(int i, int j, bool turn){ //turn : 근우가 1
    if(dp[i][j]!=0){
        return dp[i][j];
    }
    else if(i==j) {
        if(turn==1){
            dp[i][j]=list[i];
        }else{
            dp[i][j]=0;
        }

    }
    else if(turn==1) {
        int a= Game(i+1,j,0);
        int b=Game(i,j-1,0);
        dp[i][j] = max(list[i]+a, b+list[j]);
    }
    else {
        int a= Game(i+1,j,1);
        int b=Game(i,j-1,1);
        dp[i][j] = min(a, b);
    }
    return dp[i][j];
}

int main(){
    int t;
    cin>>t;
    while(t--){


        int n;
        cin>>n;
        
        for(int i=0;i<n;i++){
            cin>>list[i];
        }
        // int n=9;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                dp[i][j]=0;
            }
        }

        cout<<Game(0,n-1,1)<<endl;



    }
}