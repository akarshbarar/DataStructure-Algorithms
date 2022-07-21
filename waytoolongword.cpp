#include <bits/stdc++.h>
using namespace std;

int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
    	string s;
        cin>>s;
        int l = s.length();
        if(l < 10) {
            cout<<s<< endl;
        }
        else {
            s = s[0]+to_string(l-2) + s[l-1];
            cout<< s<< endl;
        }
        
    }
    return 0;
}