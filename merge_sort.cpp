#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void merge(int array[], int s, int m, int e){
	int fsize = m - s + 1;
	int farray[fsize];

	int esize = e - m;
	int earray[esize];

	int i;
	for(i = 0; i < fsize; i++){
		farray[i] = array[s+i];
	}

	for(i = 0; i < esize; i++){
		earray[i] = array[m+1+i];
	}

	int li = 0;
	int ri = 0;
	int arrayindex = s;

	while(li < fsize && ri < esize){
		if(earray[ri] < farray[li]){
			array[arrayindex] = earray[ri];
			ri++;
		}

		else{
			array[arrayindex] = farray[li];
			li++;
		}
		arrayindex++;
	}

	while(li < fsize){
		array[arrayindex] = farray[li];
		li++;
		arrayindex++;
	}

	while(ri < esize){
		array[arrayindex] = earray[ri];
		ri++;
		arrayindex++;
	}
}

void mergesort(int array[], int s, int e){
	int m = (s+e)/2;
	if(s < e){
		mergesort(array, s, m);
		mergesort(array, m+1, e);
		merge(array, s, m, e);
	}
}

int main(){
	cout << "Enter size of array: ";
	int n;
	cin >> n;

	int array[n];

	cout << "Enter elements of the array, separated by a space, then press enter: " << endl;

	int i;
	for(i=0; i<n; i++){
		cin >> array[i];
	}

	cout << endl << "This is your unsorted array: [";
	for(i=0; i<n-1; i++){
		cout << array[i] << ", ";
	}

	cout << array[n-1]<<"]" << endl;

	mergesort(array, 0, n-1);

	cout << "This is your sorted array: [" ;
	for(i=0; i<n-1; i++){
		cout << array[i] <<", ";
	}
	cout << array[n-1] <<"]" << endl;

	return 0;
}





