#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int N, M, a, b;
    cin >> N >> M;

    vector<int> vec[N + 1];
    vector<int> start;

    queue<int> seq;

    // int pre[N + 1]{0};
    int pre[32001]{0,};
    // bool chk[N + 1]{0};
    bool chk[32001]{0,};
    
    for(int i = 0;  i < M; i++){
        cin >> a >> b;    
        vec[a].push_back(b);
        pre[b]++;
        if(!chk[a]){
            start.push_back(a);  
            chk[a] = true;
        }
    }

    vector<int> res;

    for(int i = 0; i < start.size(); i++){
        if(pre[start[i]] == 0) seq.push(start[i]);
    }

    for(int i = 1 ; i <= N; i++){
        int x = seq.front();
        seq.pop();
        res.push_back(x);

        for(int j = 0 ; j < vec[x].size(); j++){
            if(--pre[vec[x][j]] == 0) seq.push(vec[x][j]);
        }
    }

    for(int i = 0 ; i < N; i++){
        cout << res[i] << ' ';
    }
    return 0;
}