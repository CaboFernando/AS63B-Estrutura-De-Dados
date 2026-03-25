#include <stdio.h>
#include <iostream>

using namespace std;

int fatorial(int n){
    if(n == 0){
        return 1;
    } else {
        return n * fatorial(n-1);
    }
}

int main(){
    int res;
    res = fatorial(5);
    cout << "O Fatorial: " << res << endl;

    return 0;
}