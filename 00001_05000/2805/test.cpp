#include<iostream>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main() {
    FASTIO

    int n, k; cin >> n >> k;
    vector<long long> vec(n);

    for(int i =0 ; i < n ; i++)
        cin >> vec[i];

    vec.push_back(0);

    sort(vec.rbegin(), vec.rend());

    long long i, l = 0;

    for(int i =0 ; i <vec.size() - 1 ; i++){
        long long t = ((vec[i] - vec[i+1]) * (i + 1));
        k-=t;
        
        if(k <= 0){
            l += t / (i + 1) - abs(k / (i+1));
            break;
        }
        else l += t / (i + 1);
    }
    
    cout << vec[0] - l;
    return 0;
}
