#include<iostream>
#include<algorithm>
using namespace std;

vector<int> list;

bool find(int a){
    int left =0;
    int right=list.size()-1;
    int mid = (left+right)/2;

    while(left<=right){
        int mid_num= list[mid];
        if(mid_num == a){
            return 1;
        }
        else if(a<mid_num){
            right = mid-1;
        }else{
            left = mid+1;
        }
        mid = (left+right)/2;
    }
    return 0;
}

int main(){
    int n,m;
    cin>>n;

    int tmp;
    while(n--){
        cin>>tmp;
        list.push_back(tmp);
    }
    // list.push_back(4);
    // list.push_back(1);
    // list.push_back(5);
    // list.push_back(2);
    // list.push_back(3);
    sort(list.begin(),list.end());

    cin>>m;
    int a;
    while(m--){
        cin>>a;
        cout<<find(a)<<'\n';
    }

    // int arr[5]={1, 3, 7, 9, 5};
    // for(int i=0;i<5;i++){
    //     cout<<find(arr[i])<<endl;
    // }
    
}