#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int m; 
    int n;

    cin >> n; 
    
    cin >> m;
    
    uint64_t coinarray[m];
    
    int i;
    int j;
    
    for(i=0; i<m; i++){
        cin >> coinarray[i];
    }
    
    int table[n+1];
    for(i=0; i<=n; i++){
        table[i] = 0;
    }
    table[0] = 1;
    
    for(i=0; i<m; i++){
        for(j=coinarray[i]; j<=n; j++){
            table[j] = table[j] + table[j - coinarray[i]];
        }
    }
    
    cout << table[n];
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

