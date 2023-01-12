#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int firstOcc(vector<int> &arr, int k) {
    int s = 0;
    int e = arr.size()-1;

    int ans = -1;
  int m= e+((s-e)/2);

    while(s <=e) {
        if(arr[m] == k) {
            ans=m;
            e=m-1;
        }
        else if(arr[m] < k) {
            s=m+1;
        }
        else if(arr[m] > k) {
            e=m-1;
        }
    m= e+((s-e)/2);

    }


    return ans;
}

int lastOCc(vector<int> &arr, int k) {
    int s = 0;
    int e = arr.size()-1;

    int ans = -1;
  int m= e+((s-e)/2);

    while(s <=e) {
        if(arr[m] == k) {
            ans=m;
            s=m+1;
        }
        else if(arr[m] < k) {
            s=m+1;
        }
        else if(arr[m] > k) {
            e=m-1;
        }
    m= e+((s-e)/2);

    }


    return ans;
}



int main() {
    // your code goes here
    int t; cin>>t;
    
    while(t--) {
        int n,k;
        cin>>n>>k;

        vector<int> arr;
        for (int i = 0; i < n; ++i) {
            /* code */
            int x;
            cin>>x;
            arr.push_back(x);
        }

        cout<<firstOcc(arr,k)<<endl;
        cout<<lastOCc(arr,k)<<endl;

        
    }
    return 0;
}
