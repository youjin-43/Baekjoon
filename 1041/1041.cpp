#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main(){
    unsigned long long  n;
    cin>>n;

    unsigned long long list[6];
    for(int i=0;i<6;i++){
        cin>>list[i];
    }

    vector<unsigned long long> sum_3;
    sum_3.push_back(list[0]+list[1]+list[2]);
    sum_3.push_back(list[0]+list[2]+list[4]);
    sum_3.push_back(list[0]+list[4]+list[3]);
    sum_3.push_back(list[0]+list[3]+list[1]);

    sum_3.push_back(list[5]+list[1]+list[2]);
    sum_3.push_back(list[5]+list[2]+list[4]);
    sum_3.push_back(list[5]+list[4]+list[3]);
    sum_3.push_back(list[5]+list[3]+list[1]);

    sort(sum_3.begin(),sum_3.end());

    // cout<<"sum_3 : ";
    // for(int i=0;i<8;i++){
    //     cout<<sum_3[i]<<' '<<endl;
    // }
    // cout<<endl;


    vector<unsigned long long> sum_2;
    for(int i=1;i<=4;i++){
        sum_2.push_back(list[0]+list[i]);
        sum_2.push_back(list[5]+list[i]);
    }
    sum_2.push_back(list[1]+list[2]);
    sum_2.push_back(list[2]+list[4]);
    sum_2.push_back(list[3]+list[4]);
    sum_2.push_back(list[1]+list[3]);

    sort(sum_2.begin(),sum_2.end());

    // cout<<"sum_2 : ";
    // for(int i=0;i<8;i++){
    //     cout<<sum_2[i]<<' '<<endl;
    // }
    // cout<<endl;

    sort(list,list+5); 

    // cout<<"list : ";  
    // for(int i=0;i<6;i++){
    //     cout<<list[i]<<' '<<endl;
    // } 
    // cout<<endl;

    //최소값 계산
    unsigned long long ret=0;
    if(n==1){
        for(int i=0;i<5;i++){
            ret+=list[i];
        }
    }else{
        // cout<<"1 : "<<4*(sum_3[0])<<endl;
        // cout<<"1 : "<<((n-2)*8+4)*sum_2[0]<<endl;
        // cout<<"1 : "<<4*(sum_3[0])<<endl;
        // cout<<"1 : "<<4*(sum_3[0])<<endl;
        

        ret = 4*(sum_3[0]) + ((n-2)*8+4)*sum_2[0] + (n-2)*(n-2)*list[0] + (n-2)*(n-1)*4*list[0];
    }
   
    cout<<ret<<endl;

}

