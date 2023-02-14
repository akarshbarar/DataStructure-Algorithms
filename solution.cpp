#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isEven(long long n)
{
 
    // n^1 is n+1, then even, else odd
    if ((n ^ 1) == (n + 1))
        return true;
    else
        return false;
}

int main() {
    // your code goes here
    
    long long n;
    cin>>n;
    cout<<n<<" ";
    while(n != 1) {
        if(isEven(n)){
            n= n/2;
        }
        else {
            n = (n*3)+1;
        }
        cout<<n<<" ";
    }
    return 0;
}
