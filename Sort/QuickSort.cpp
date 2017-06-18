#include <iostream>
#include <bits/stdc++.h>

/*Quicksort is a comparison sort, meaning that it can sort items of any type for which a "less-than" relation (formally, a total order) is defined. 
In efficient implementations it is not a stable sort, meaning that the relative order of equal sort items is not preserved. 
Quicksort can operate in-place on an array, requiring small additional amounts of memory to perform the sorting.

Mathematical analysis of quicksort shows that, on average, the algorithm takes O(n log n) comparisons to sort n items. 
In the worst case, it makes O(n2) comparisons, though this behavior is rare.*/

int Partion(int* a,int start,int end)
{
    int i=start-1;
    int provit=a[end];
    for(int j=start;j<end;++j)
    {
        if(a[j]<=provit)
        {
            ++i;
            std::swap(a[i],a[j]);
        }
    }

    std::swap(a[++i],a[end]);
    return i;
}

void QuickSort(int* a,int i,int j)
{
    if(i<j)
    {
        int p=Partion(a,i,j);
        QuickSort(a,i,p-1);
        QuickSort(a,p+1,j);
    }
}

int main()
{
    int a[]={53,-41,3,-454,111,1,515,6,1,-666,43,0};
    std::cout<<"Before:"<<std::endl;
    int N=sizeof(a)/sizeof(int);
    for(int i=0;i<N;++i)
    {
        std::cout<<a[i]<<" ";
    }
    QuickSort(a,0,N-1);
    std::cout<<"\nAfter:"<<std::endl;
     for(int i=0;i<N;++i)
    {
        std::cout<<a[i]<<" ";
    }
    return 0;
}
