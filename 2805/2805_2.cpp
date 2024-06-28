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

    //test7
    // long long n=9,m=44444;
    // trees.push_back(1232);
    // trees.push_back(2343);
    // trees.push_back(17124242);
    // trees.push_back(1232344444);
    // trees.push_back(342433);
    // trees.push_back(233333);
    // trees.push_back(1232323232);
    // trees.push_back(1424242424);
    // trees.push_back(3);

    sort(trees.begin(),trees.end());
    
    // cout<<"sorted : ";
    // for(int i=0;i<n;i++){
    //     cout<<trees[i]<<' ';
    // }cout<<'\n';

    //2진탐색
    long long left=0;
    long long right=trees.size()-1;

    bool include = 0;
    bool up =0;
    long long mid=(left+right)/2;

    while(left<=right){

        long long sum=0;
        for(int i=mid;i<trees.size();i++){
            sum+=(trees[i]-trees[mid]);
        }

        if(sum==m){
            cout<<trees[mid]<<'\n';
            include =1;
            break;
        }

        if(sum<m){  
            right = mid-1;
            up = 0;
        }

        if(m<sum){
            left = mid+1;
            up = 1;
        } 

        mid=(left+right)/2;
    }


    //include 하지않는다면
    if(!include){
        long long i_left;
        long long i_right;
        long long ret;

        if(up){
            i_left = trees[left]+1;
            i_right = trees[left+1]-1;
            
        }else{
            if(left==0){
                i_left = 0;
                i_right = trees[left]-1;
            }else{
                i_left = trees[left-1]+1;
                i_right = trees[left]-1;
            }
        }

        long long i_mid =(i_right+i_left)/2;
        while(i_left<=i_right){
            long long sum=0;
            for(int i=0;i<trees.size();i++){
                if(trees[i]>i_mid) sum+=(trees[i]-i_mid);
            }

            if(m>sum){
                i_right = i_mid-1;
                
            }
            else{
                i_left = i_mid+1;
            }
            i_mid =(i_right+i_left)/2;
        }

        cout<<i_mid<<'\n';
    }
    
}