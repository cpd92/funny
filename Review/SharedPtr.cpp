#include<bits/stdc++.h>

/*A Review to a shared_ptr implement...*/

template<class T>
class Shared_Ptr
{
private:
    int* count=nullptr;        // a struct on heap indeed
    T* ptr=nullptr;
    
public:
    //Shared_Ptr():count(nullptr),ptr(nullptr)
    //{
        
    //}
    
    explicit Shared_Ptr(T* p=nullptr):count(new int(1)),ptr(p)
    {
        
    }
    
    ~Shared_Ptr()
    {
        --(*count);
        if((*count)==0)
        {
            std::cout<<"Deconstuct the Object..."<<std::endl;
            delete ptr;
        }
    }
    
    Shared_Ptr(const Shared_Ptr& S_ptr)
    {
        ptr=S_ptr.ptr;
        (*(S_ptr.count))++;
        count=S_ptr.count;
    }
    
    Shared_Ptr& operator=(const Shared_Ptr& S_ptr)
    {
        if(&(S_ptr)!=this)
        {
           ptr=S_ptr.ptr;
           (*(S_ptr.count))++;
           count=S_ptr.count; 
        }
        
        return *this;
    }
    
    T* operator->() const
    {
        return ptr;
    }
    
    T& operator*() const
    {
        return *ptr;
    }
};

int main()
{
    Shared_Ptr<int> a(new int(2));
    std::cout<<a.operator*();
    Shared_Ptr<int> b=a;
    return 0;
}
