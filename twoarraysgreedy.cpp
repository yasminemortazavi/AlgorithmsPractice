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

int main() {
    int test, n, i, k, q;
    cin >> test;
    for(q=0; q<test; q++){
        cin >> n;
        cin >> k;
        int A[n];
        int B[n];
        for(i=0; i<n; i++){
            cin >> A[i];
        }
        for(i=0; i<n; i++){
            cin >> B[i];
        }

        mergesort(A, 0, n-1);
        mergesort(B, 0, n-1);
        

        int t=0;

        for(i=0; i<n; i++){
            if(A[i] + B[n-i-1] >= k){
                t++;
            }
        }

        if(t==n){
            cout << "YES" << endl;
        }
        if(t<n){
            cout << "NO" << endl;
        }
        

    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}