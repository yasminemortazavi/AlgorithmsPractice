#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int find(int array[], int l, int r){
	int i;
	int m = (l + r)/2;
	if(array[l] == l){
		return l;
	}
	if(array[m] == m){
		return m;
	}
	if(r-l == 1){
		return -1;
	}
	if(array[m] > m){
		return find(array, m, r);
	}
	else{
		return find(array, l, m);
	}
}


int main(){
	int n;
	int i;

	cout << "Enter the size of the array: " << endl;
	cin >> n;
	int array[n];

	cout << "Enter sorted array of integers with format" <<  "[a1, a2, a3, .... , an]"<<endl;

	char randomchar;
	cin >> randomchar;
	for(i = 0; i < n; i++){		
		cin >> array[i];
		cin >> randomchar;
	}

	int k = find(array, 0, n);
	if(k<0){
		cout<<"There is no integer k such that array[k] = k"<<endl;
	}
	cout <<"There is an integer " << k << " such that array["<<k<<"] = "<<k<<endl;
}















