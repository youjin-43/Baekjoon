/* 틀린코드!!!!!*/


#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(string a, string b){
    cout<<endl<<"a : "<<a<<" || b :"<<b<<endl;
    if(a.size() == b.size()){
        int i=0;
        while(a[i]==b[i]){
            i++;
        }

        // cout<<"i : "<<i<<endl;
        // cout<<"a[i],b[i] : "<<a[i]<<','<<b[i]<<endl;
        // bool tmp = a[i] < b[i];
        // cout<<tmp<<endl;

        bool tmp = a[i] < b[i];
        cout<<"size 같음 -> tmp : "<<tmp<<endl;
        
        return a[i] < b[i];
    }
    else{
        bool tmp =a.size() < b.size();
        cout<<"size 다름 -> tmp : "<<tmp<<endl;
        return a.size() < b.size();
    }
}

bool cmp2(string a, string b){
    return a.size() < b.size();    
}

int main(){
    string list[200000];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>list[i];
    }

    // cout<<"-----입력값 확인------"<<endl;
    // for(int i=0;i<n;i++){
    //     cout<<list[i]<<endl;
    // }
    sort(list,list+n,cmp2);
    


    cout<<"----답-----"<<endl;
    
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