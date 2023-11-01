#include <iostream>
using namespace std;
struct item{
    int value;
    int priority;
};
item priorityQ[100];
int siz = -1;
void enqueue(int val, int prio){
    siz++;
    priorityQ[siz].value = val;
    priorityQ[siz].priority = prio;
}
void dequeue(){
    
}

int main(){


    return 0;
}