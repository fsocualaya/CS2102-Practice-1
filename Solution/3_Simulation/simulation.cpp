#include <iostream>
#include <ctime>
#include "sortingAlgorithms.h"
#include <fstream>

using namespace std;

float getInsertionTime(int a[], int size){
	//start timer
    std::clock_t start;
	float duration;
	start = std::clock();
    insertionSort(a, size);
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    return duration;
	//end timer
}

float getMergeTime(int a[], int size){
	//start timer
    std::clock_t start;
    float duration;
    start = std::clock();
    MergeSort(a, 0, size-1);
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    return duration;
    // end timer
}

void getRandom(int a[],int size){
	srand(time(NULL));
	for(int i=0;i<size;i++){
		a[i] = rand()%100;
	}
}

float getAverageTime(int times,int a[], int size, float (*f)(int*, int)){
	
	float sum=0;
	for(int i=0;i<times;++i){
		getRandom(a,size);	
		sum+=(*f)(a,size);
	}
	return sum/times;
}

int main(){
	ofstream output("simulation.csv", ios::out);
	output<<"Size,"<<"Merge Sort,"<<"Insertion Sort\n";
	int size, upperSize, times;
	//cout<<"Size\t"<<"Merge Sort\t"<<"INsertion Sort\n";
	cin>>size>>upperSize>>times;
	while(size<=upperSize){
		int a[size];
		output<<size<<','<<getAverageTime(times,a,size,getMergeTime)<<','<<getAverageTime(times,a,size,getInsertionTime)<<'\n';
		size+=10;
	}
	return 0;
}
