#include<iostream>
#include<algorithm>
#define SIZE 10000
using namespace std;
int list[SIZE];

long long combi(long long a,long long b){
    long long ret=1;
    long long tmp =b;
    for(int i=0;i<b;i++)ret*=a--;
    for(int i=0;i<b;i++)ret/=tmp--;
    return ret;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    // freopen("input.txt","r",stdin);

    int n; cin>>n;
    for(int i=0;i<n;i++) cin>>list[i];
    sort(list,list+n);

    long long ret=0;
    // 일단 하나 잡고 
    for(int i=0;i<n-2;i++){
        // 나머지 투포인터 
        int l=i+1,r=n-1;
        int s= list[i]+list[l]+list[r];
    
            if(!s&&list[i]==list[r]){
                ret+=combi(r-i+1,3);
                i=r+1;
                break;;
            }
        while(l<r){
            s= list[i]+list[l]+list[r];
            if(s>0)r--;
            else if(s<0)l++;
            else{
                if(list[l]==list[r]){
                    ret+=combi(r-l+1,2);
                    break;
                }

                int cnt_l=1,cnt_r=1;
                int p_l=l,p_r=r;
                while(p_l+1<r && list[p_l]==list[p_l+1]){ cnt_l++; p_l++;}
                while(p_r-1>l && list[p_r]==list[p_r-1]){ cnt_r++; p_r--;}
                ret+=cnt_l*cnt_r;
                l+=cnt_l;
                r-=cnt_r;
            }
        }  
    }
    cout<<ret<<endl;



}