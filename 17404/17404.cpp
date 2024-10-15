//24.7.24(금) 17404 RGB거리 2

#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int list[1001][3];
int ret[1001][3];
int trace[1001][3];
int n;

void fill(){
    ret[0][0]=list[0][0];
    ret[0][1]=list[0][1];
    ret[0][2]=list[0][2];

    for(int i=1;i<n;i++){
        
        //0
        if(ret[i-1][1]<ret[i-1][2]){
            ret[i][0]=ret[i-1][1]+list[i][0];
            trace[i][0]=1;
        }else{
            ret[i][0]=ret[i-1][2]+list[i][0];
            trace[i][0]=2;
        }
        
        //1
        if(ret[i-1][0]<ret[i-1][2]){
            ret[i][1]=ret[i-1][0]+list[i][1];
            trace[i][1]=0;
        }else{
            ret[i][1]=ret[i-1][2]+list[i][1];
            trace[i][1]=2;
        }

        //2
        if(ret[i-1][0]<ret[i-1][1]){
            ret[i][2]=ret[i-1][0]+list[i][2];
            trace[i][2]=0;
        }else{
            ret[i][2]=ret[i-1][1]+list[i][2];
            trace[i][2]=1;
        }
    }
}

int findStart(int color){
    int idx=n-1;
    while(idx>0){
        color=trace[idx][color];
        idx--;
    }
    return color;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    // freopen("input.txt", "r", stdin);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>list[i][0]>>list[i][1]>>list[i][2];
    } 

    vector<int> retList;

    //표채우기 
    fill();

    //최솟값이 처음과 겹치지 않은경우
    int tmp = min(ret[n-1][0],min(ret[n-1][1],ret[n-1][2]));
    int endColor;
    for(int i=0;i<3;i++){
        if(tmp==ret[n-1][i]){
            endColor=i;
            break;
        }
    }

    if(findStart(endColor)!=endColor){
        cout<<tmp;
        exit(0);
    }

    //겹치는 경우
    for(int i=0;i<3;i++){
        if(i!=findStart(i)){
            retList.push_back(ret[n-1][i]);
        }
    }

    list[0][endColor]=INT_MAX; //그 색이 안들어가는 경우로 다시 표 작성 
    
    fill();

    for(int i=0;i<3;i++){
        if(i!=findStart(i)){
            retList.push_back(ret[n-1][i]);
        }
    }
    
    sort(retList.begin(),retList.end());
    cout<<retList[0];

}