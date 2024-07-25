#include <iostream>
#include<string>
using namespace std;

int Answer;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);cin.tie(0);
    
	int T, test_case;
	cin >> T;

	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
        int n; //4≤N≤300,000
        cin>>n;

        string str; 
        cin>>str;

        int i=0;
        while(i<n-1){
            if(str[i]=='B'){
                i++;
                continue;
            }

            int next=str[i+1];

            //다음에 A가 오는경우
            if(next == 'A'){
                Answer+=2;
                i++;
            }
            //다음에 B가 오는 경우
            else{
                //그 다음에 A가 오는 경우
                if(i+2<n){
                    if(str[i+2]=='A'){
                        Answer++;
                        i+=2;   
                    }
                    else{
                        i+=3;
                    }
                }else{
                    i++;
                }
                
            }


        }

		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}