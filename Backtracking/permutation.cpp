#include <iostream>
#include <bits/stdc++.h>

/*this algorithm is to solve the all permutations of a given string*/

void permute(char *a, int l, int r)
{
   int i;
   if (l==r)
   {
        std::cout<<a<<"\n";
   }
   else
   {
       for (i=l;i<=r;i++)
       {
          std::swap(*(a+l),*(a+i));
          permute(a,l+1,r);
          std::swap(*(a+l),*(a+i)); //backtracking
       }
   }
}

int main()
{
    std::string s="ABCDEFGHIJ";
    std::sort(s.begin(),s.end(),std::greater<char>());
    int64_t count=1;
    for(int i=1;i<=s.size();++i)
    {
        count*=i;
    }
    std::cout<<"Expect:"<<count<<std::endl;  //total possible is: n!
    count=0;
    do
    {
        std::cout<<s<<"\n";
    } while(std::prev_permutation(s.begin(), s.end()));

    std::cout<<"\nNext Method\n"<<std::endl;
    char str[]="ABCDEFGHIJ";
    int n = strlen(str);
    permute(str, 0, n-1);
    return 0;
}
