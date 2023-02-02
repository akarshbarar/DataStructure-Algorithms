#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &nums, int s, int e) {
    int x = nums[s];
    int pivotIndex = s +1;

    for (int i = s+1; i <=e; ++i)
    {
        /* code */
        if(nums[i] <= x) {
            
            swap(nums[pivotIndex], nums[i]);
            pivotIndex++;
        }
    }
    swap(nums[pivotIndex-1], nums[s]);
    return pivotIndex -1;
}

void quickSort(vector<int> &nums, int s, int e) {
    if ( s >= e) return;
    int pivot = partition(nums, s, e);
    quickSort(nums, s, pivot-1);
    quickSort(nums, pivot+1, e);
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

        quickSort(nums, 0, n-1);
        for(int i=0; i<n; i++) {
            cout<<nums[i]<<" ";
        }
    }
    return 0;
}
