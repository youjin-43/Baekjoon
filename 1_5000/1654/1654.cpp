#include <iostream>
#include <algorithm>
using namespace std;

int k,n;
int k_list[10000];
int min_size=1 ,max_size=0;

int n_cnt(int n_size);
int resize(int n_size,int n_cnt);


int main(){
    cin>>k>>n;
    for(int i=0;i<k;i++){
        cin>>k_list[i];
        max_size = max(k_list[i],max_size);
    }

    int n_size=max_size;
    
    while(true){
        int n_tmp=n_cnt(n_size);
        if(n_tmp == n){
            break;
        }
        n_size= resize(n_size,n_tmp);
        cout<<"n_size : "<< n_size<<endl;
    }



    while(n==n_cnt(n_size)){
        n_size++;
    }
    n_size--;
    cout<<n_size<<endl;
    
}

int n_cnt(int n_size){
    int n_cnt=0;
    for(int i=0;i<k;i++){
        n_cnt+=(k_list[i]/n_size);
    }
    return n_cnt;


}

int resize(int n_size,int n_cnt){
    if(n_cnt<n){ //부족한경우 size를 줄임
        max_size=n_size-1;
    }
    else{ //넘치는경우 if(n_cnt>n) size를 늘림
        min_size=n_size+1;
    }        
    return (min_size+max_size)/2;
}


/*
4 15
802
743
457
539
*/