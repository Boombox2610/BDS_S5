#include <iostream>
using namespace std;
#define n1 50
int Q[n1], front1 = - 1, rear1 = - 1;
void Insert() {
   int val;
   if (rear1 == n1 - 1)
   cout<<"Queue Overflow\n";
   else {
      if (front1 == - 1)
      front1 = 0;
      cout<<"Insert the element in queue : "<<endl;
      cin>>val;
      rear1++;
      Q[rear1] = val;
   }
}
void Delete() {
   if (front1 == - 1 || front1 > rear1) {
      cout<<"Queue Underflow ";
      return ;
   } else {
      cout<<"Element deleted from queue is : "<< Q[front1] <<"\n";
      front1++;;
   }
}
void Display() {
   if (front1 == - 1)
   cout<<"Queue is empty"<<endl;
   else {
      cout<<"Queue elements are : ";
      for (int i = front1; i <= rear1; i++)
      cout<<Q[i]<<" ";
         cout<<"\n";
   }
}
int main() {
   int ch;
   cout<<"1) Insert element\n";
   cout<<"2) Delete element\n";
   cout<<"3) Display all the elements\n";
   cout<<"4) Exit"<<endl;
   do {
      cout<<"Enter your choice : "<<endl;
      cin>>ch;
      switch (ch) {
         case 1: Insert();
         break;
         case 2: Delete();
         break;
         case 3: Display();
         break;
         case 4: cout<<"STOP\n";
         break;
         default: cout<<"invalid\n";
      }
   } while(ch!=4);
   return 0;
}