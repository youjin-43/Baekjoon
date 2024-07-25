#include <iostream>
#include<queue>
#include<vector>
using namespace std;

long long Answer;

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int T, test_case;
	cin >> T;
    // T=1;

	for(test_case = 0; test_case  < T; test_case++)
	{
        cout << "Case #" << test_case+1 << endl;

		/////////////////////////////////////////////////////////////////////////////////////////////
        int n; 
        cin>>n;
        // n=9;

        vector<long long> list;
        for(int i=0;i<n;i++){
            long long tmp;
            cin>>tmp;
            list.push_back(tmp);
        }

        //test1
        // list.push_back(2);
        // list.push_back(3);
        // list.push_back(2);
        // list.push_back(3);
        // list.push_back(4);
        // list.push_back(3);
        // list.push_back(2);
        // list.push_back(3);
        // list.push_back(2);
        // list.push_back(1);
        // list.push_back(2);
        // list.push_back(2);

        //test2
        // list.push_back(1);
        // list.push_back(2);
        // list.push_back(2);
        // list.push_back(4);
        // list.push_back(5);
        // list.push_back(6);
        // list.push_back(7);
        // list.push_back(8);
        // list.push_back(9);



        int m; //쿼리의 갯수
        cin>>m;
        // m=1;

        for(int i=0;i<m;i++){
            Answer = 0;

            int l,r;
            cin>>l>>r;
            // l=3;r=7;
            
            l--;r--;
            priority_queue<long long, vector<long long>, greater<long long> > pq; // 오름차순 정렬
            for(int j=l;j<=r;j++){
                if(list[j]!=1) pq.push(list[j]);
            }

            while(!pq.empty()){

                long long a = pq.top(); 
                pq.pop();

                if(pq.empty()) break;

                bool able = 1;

                for(int k=0;k<a-1;k++){
                    if(pq.empty()){
                        able=0;
                        break;
                    }
                    
                    long long tmp = pq.top(); 
                    if(tmp==a){
                        pq.pop();
                    }
                    else{
                        able=0;
                        break;
                    }
                }

                if(able){
                    Answer++;
                    pq.push(a*a);
                }
            }

            cout<<Answer<<endl;
        }

		/////////////////////////////////////////////////////////////////////////////////////////////
	}

	return 0;//Your program should return 0 on normal termination.
}