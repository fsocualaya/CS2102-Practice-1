#include <iostream>
#include <fstream>
using namespace std;

int tresenemasuno(long int n){
    int count = 1;

    if (n == 0){
        return n;
    }

    while(n!=1){
        if(!(n%2))
            n /= 2;
        else
            n = 3*n+1;
        ++count;
    }
    return count;
};

int getMax(int start, int end){
	int max = tresenemasuno(start);
	for(int i=start;i<=end;i++){
		if(tresenemasuno(i)>max)
			max = tresenemasuno(i);
	}
	return max;
};

int main(){
    	int start=0, end=0;
	while(cin>>start>>end){		
		cout<<start<<' '<<end<<' ';
		if(start>end) cout<<getMax(end,start);
		else cout<<getMax(start,end);
		cout<<'\n';
	}
	return 0;
}
