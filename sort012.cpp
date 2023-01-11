#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //   Write your code here
    int nz=0,no=0,nt=0;
    for(int i=0; i<n; i++) {
        if(arr[i] == 0) nz++;
        if(arr[i] == 1) no++;
        if(arr[i] == 2) nt++;
    }
    int k=0;
    for(int i=0; i<nz;i++) arr[k++] = 0;
    for(int i=0; i<no;i++) arr[k++] = 1;
    for(int i=0; i<nt;i++) arr[k++] = 2;

}