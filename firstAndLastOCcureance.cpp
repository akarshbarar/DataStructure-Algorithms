#include <bits/stdc++.h> 

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
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
    pair<int,int> p;
    p.first= firstOcc(arr,k);
    p.second = lastOCc(arr,k);
    return p;
}