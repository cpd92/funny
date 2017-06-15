#include <iostream>
#include <bits/stdc++.h>

/*Given an unsorted Array find maximum value of A[j]-A[i] where j>i in O(n) time*/

int main()
{

    int a[]={12,44,-33,55,32,3,54,-78,88,1};
    int N=sizeof(a)/sizeof(int);
    int min_val=a[0];
    int max_result=INT_MIN;
    for(int i=1;i<N;++i)
    {
        max_result=std::max(max_result,a[i]-min_val);   // A[j] - A[i] is maximal, when A[i] is minimal value from {A[0], A[1],.., A[i-1]}
        min_val=std::min(min_val,a[i]);
    }

    std::cout<<"the maximum value is:"<<max_result<<std::endl;
    return 0;
}
