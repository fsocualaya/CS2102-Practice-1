//
// Created by fsocualaya on 4/5/19.
//

#ifndef ADA_SORTINGALGORITHMS_H
#define ADA_SORTINGALGORITHMS_H

#include <ctime>
#include <limits>
#include <cmath>

void Merge(int A[], int p, int q, int r){
    //Sizes for new arrays
    int n1 = q-p+1;
    int n2 = r-q;

    //let L[1 ... n1 + 1] and R[1 ... n2 + 1] be new arrays
    int L[n1+1]={};
    int R[n2+1]={};
    for(int i = 0;i<n1;i++) L[i] = A[p+i];
    for(int j = 0;j<n2;j++) R[j] = A[q+j+1];

    L[n1] = std::numeric_limits<int>::max();
    R[n2] = std::numeric_limits<int>::max();

    int i = 0;
    int j = 0;

    for(int k = p; k<=r; k++){
        if(L[i]<=R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
    }
};

void MergeSort(int A[], int p, int r){
    if(p<r){
        int q = floor((float)(p+r)/2);
        MergeSort(A,p,q);
        MergeSort(A,q+1,r);
        Merge(A,p,q,r);
    }
};

void insertionSort(int a[], int size){
    for(int j=1;j<size;j++){
        int key = a[j];
        int i = j-1;
        while(i>=0 and a[i]>key){
            a[i+1] = a[i];
            i--;
        }
        a[i+1] = key;
    }
}

#endif //ADA_SORTINGALGORITHMS_H
