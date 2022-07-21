#include <bits/stdc++.h>
using namespace std;

int main() 
{
   	int t;
    cin >> t;
    while (t > 0)
    {
    	int x, y, z;
    	cin>>x>>y>>z;
    	int ans = 0;
    	while(x > 0){
    		if(x > 3) {
    			ans += 3*y;
    			ans += z;
    			x -= 3;
    		}
    		else {
    			ans += (x*y);
    			x= 0;
    		}
    	}
    	cout<< ans<< endl;
    	t--;
    }
    return 0;
}