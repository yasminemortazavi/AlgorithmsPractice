#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct node{
    int number;
    node* next;
};

struct adjlist{
    node* head;
};

int main() {
    int i, j, numoftests, n, e, q, a, b, testnum, currint;
    cin >> numoftests;
    node* currnode = new node;
    int prevdist;
    for(i=0; i<numoftests; i++){
        cin>>n;
        cin>>e;
        adjlist list[n+1];
        int distance[n+1];
        for(j=0; j<=n; j++){
            distance[j] = -1;
        }
        for(j=0; j<=n; j++){
            list[j].head = NULL;
        }
        for(q=0; q<e; q++){
            cin >> a;
            cin >> b;
            node* nodea = new node;
            node* nodeb = new node;
            nodea->number = a;
            nodeb->number = b; 
            nodeb->next = list[a].head;
            list[a].head = nodeb;
            nodea->next = list[b].head;
            list[b].head = nodea;
        } 
        cin >> testnum;
        distance[testnum] = 0;
        queue<int> bigq;
        bigq.push(testnum);
        currnode = list[bigq.front()].head;
        while(!bigq.empty()){
            prevdist = distance[bigq.front()];
            while(currnode!=NULL){
                if(distance[currnode->number] == -1){
                    bigq.push(currnode->number);
                    distance[currnode->number] = 6 + prevdist;
                }
                currnode = currnode->next;
            }
            bigq.pop();
            if(!bigq.empty()){
                prevdist = distance[bigq.front()];
                currnode = list[bigq.front()].head;
            }
            
        }
        for(q=1; q<=n; q++){
            if(q!=testnum){
                cout<<distance[q]<<" ";
            }
        }
        cout<<endl;
       
    }
    return 0;
}
