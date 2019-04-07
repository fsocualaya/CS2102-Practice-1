#include <iostream>
using namespace std;

int main(){
	string encoded;
	while(cin>>encoded){
		for(auto&i:encoded)
			cout<<(char)(i-7);
		
		cout<<endl;
	}
	return 0;	
}
