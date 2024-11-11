#include<iostream>
#include<string>
using namespace std;

string bigNumAdd(string n1,string n2){
	long long sum = 0;
	string result;

	while (!n1.empty() || !n2.empty() || sum){
		if (!n1.empty()){
			sum += n1.back() - 48;
			n1.pop_back();
		}
		if (!n2.empty()){
			sum += n2.back() - 48;
			n2.pop_back();
		}
		result += to_string(sum % 10);

		sum /= 10; //check
	}

	reverse(result.begin(),result.end());
	return result;
}
int main(){
    cout<<bigNumAdd("11020","291")<<endl;
}