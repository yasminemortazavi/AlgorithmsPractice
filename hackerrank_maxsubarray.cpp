#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int numoftests;
    int sizeofarray;
    cin >> numoftests;
    int somenumber;
    for(int i=0; i<numoftests; i++){
        cin >> sizeofarray;
        int origarray[sizeofarray];
        for(int j=0; j<sizeofarray; j++){
            cin >> somenumber;
            origarray[j] = somenumber;
        }//finished filling array;
        
        int maxsum = 0;
        int currsum = 0;
        int currnon = 0;
        int currneg = origarray[0];
        int somepos = 0;
        
        for(int q=0; q<sizeofarray; q++){
            
            if(origarray[q] > 0){
                currnon = currnon + origarray[q];
                somepos = 1;
            }
            if(somepos == 0 && origarray[q] > currneg){
                currneg = origarray[q];
            }
            
            currsum = currsum + origarray[q];
            if(currsum > maxsum){
                maxsum = currsum;
            }
            if(currsum < 0){
                currsum = 0;
            }
            
        }
        
        if(somepos == 0){
            cout<<currneg<<" "<<currneg<<endl;
        }
        else{
           cout<<maxsum<<" "<<currnon<<endl; 
        }
    }
    return 0;
}






