#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    //적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값을 구하는 프로그램을 작성하시오.
    vector<long long> trees;

    long long n,m;
    cin>>n>>m;
    long long tmp;
    while(n--){
        cin>>tmp;
        trees.push_back(tmp);
    }

    //test1
    // long long n=5,m=20;
    // trees.push_back(4);
    // trees.push_back(42);
    // trees.push_back(40);
    // trees.push_back(26);
    // trees.push_back(46);

    //test2
    // int n=3,m=6;
    // trees.push_back(1);
    // trees.push_back(2);
    // trees.push_back(3);

    //test3
    // int n=3,m=5;
    // trees.push_back(3);
    // trees.push_back(3);
    // trees.push_back(3);

    //test4
    // int n=3,m=2000000000;
    // trees.push_back(2000000000);
    // trees.push_back(2000000000);
    // trees.push_back(1);

    sort(trees.begin(),trees.end());
    
    //2진탐색
    long long left=0;
    long long right=trees[trees.size()-1];
    
    long long ret;

    while(left<=right){
        long long mid=(left+right)/2;

        long long sum=0;
        for(int i=0;i<trees.size();i++){
            if(trees[i]>mid){
                sum+=(trees[i]-mid);
            }
        }

        if(sum<m){  
            right = mid-1;
        }
        else{
            left = mid+1;
            ret=mid;
        } 
        
    }
    cout<<ret<<'\n';

    
    
}