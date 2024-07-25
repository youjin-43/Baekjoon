#include <iostream>
#include <algorithm>
using namespace std;

long long Answer;
int list[300000];

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);cin.tie(0);
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		 int n;cin>>n;
		 for(int i=0;i<n;i++){
		     cin>>list[i];
		 }
		 sort(list,list+n);

        int cnt=n/4; //배달해야하는 횟수
        for(int i=0;i<cnt;i++){
            // int a=list[i],b=list[i+cnt],c=list[i+2*cnt],d=list[i+3*cnt];
            int a=list[i],d=list[n-1-i];
            // Answer+= d-c + c-b + b-a + d-a;
            Answer+= 2*(d-a);

        }


		 
		 
		 
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}