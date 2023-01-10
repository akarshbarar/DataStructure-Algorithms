#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
    vector<vector<int>> res;
    for(int i=0; i<arr.size(); i++) {
        for(int j=i+1; j< arr.size(); j++) {
            if(arr[i]+arr[j] == s) {
                   vector<int> inner;
                   inner.push_back(min(arr[i], arr[j]));
                   inner.push_back(max(arr[i], arr[j]));
                   res.push_back(inner);
            }
        }
    }
    sort(res.begin(), res.end());
    return res;
}