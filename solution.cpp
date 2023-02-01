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
        int n; cin>>n;

        vector<int> nums;
        for(int i=0; i<n; i++) {
            int x;
            cin>>x;
            nums.push_back(x);
        }

        int l = nums.size();
        vector<int> left(l,0);
        vector<int> right(l,0);

        left[0] = nums[0];
        right[l-1] = nums[l-1];

        for(int i=1; i< l ; i++) {
            left[i] = left[i-1]+nums[i];
        }
        for(int i=l-2; i>=0; i--) {
            right[i] = right[i+1] + nums[i];
        }


        for(int i=0; i<l; i++){
            cout<<left[i]<<", ";
        }
        cout<<endl;
        for(int i=0; i<l; i++){
            cout<<right[i]<<", ";
        }
        cout<<endl;


        int s = 0;
        int e = l-1;

        while(s <= e) {
            int m = s +(e-s)/2;
            if(left[m-1] == right[m+1]){
                cout<<m<<endl;
                break;
                // return m;
            }
            else if (right[m] > left[m]){
                s = m+1;
            }
            else {
                e = m-1;
            }
        }

    }
    return 0;
}
