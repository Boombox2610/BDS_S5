#include <iostream>
using namespace std;

int factorial(int n){
    if(n == 1){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }
}
int GCD(int m, int n){
    int rem;
    rem = n%m;
    if(rem == 0){
        return m;
    }
    else{
        return GCD(n, rem);
    }
}

int main(){
    int n = 5;
    cout<<"Factorial of "<<n<<" is "<<factorial(n);
    int m = 8;
    n = 62;
    cout<<"\nGC of "<<n<<" and "<<m << " is "<<GCD(n, m);
    return 0;
}
