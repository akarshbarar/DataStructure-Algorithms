#include <bits/stdc++.h>
using namespace std;

int main() 
{
   	int t;
    cin >> t;
    while (t > 0)
    {
    	int x, y;
    	cin>>x>>y;
    	int m = min(x, y);
        if( x == y) {
            cout << "ANY"<<endl;
        }
        else if(m == x) {
            cout<< "FIRST"<<endl;
        }
        else if(m == y){
            cout<< "SECOND" << endl;
        }
    	t--;
    }
    return 0;
}