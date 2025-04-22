#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(string a, string b){
    if(a.size() == b.size()){
        return a < b;
    }
    else{
        return a.size() < b.size();
    }
}

int main(){
    string list[200000];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>list[i];
    }

    sort(list,list+n,cmp);
    
    // cout<<"----답-----"<<endl;
    
    for(int i=0;i<n;i++){
        if(list[i] == list[i-1]){
            continue;
        }
        cout<<list[i]<<endl;
    }
    
}

/*

3
wait
wont
more


12
but
i
wont
no
more
no
more
it
cannot
wait
im
yours


11
but
i
wont
no
more
no
more
it
wait
im
yours


9
but
i
wont
no
no
it
wait
im
yours


7
but
wont
no
no
wait
im
yours




*/