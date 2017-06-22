#include <iostream>
#include <bits/stdc++.h>

/*reverse a single linked list*/

struct Node
{
    int data;
    Node* next=nullptr;
};

void Add(Node** n,int new_val)
{
    Node* new_node=new Node;
    new_node->data=new_val;

    if(*n==nullptr)
    {
        *n=new_node;
    }
    else
    {
        new_node->next=*n;
        *n=new_node;
    }
}

void PrintList(Node* n)
{
    while(n!=nullptr)
    {
        std::cout<<n->data<<" ";
        n=n->next;
    }
    std::cout<<std::endl;
}

Node* ReverseList(Node** n)
{
    if(*n==nullptr || (*n)->next==nullptr)
    {
        return *n;
    }

    Node* pre=nullptr;
    Node* now=*n;
    Node* next;

    while(now!=nullptr)
    {
        next=now->next;
        now->next=pre;
        pre=now;
        now=next;
    }

    return pre;
}

int main()
{
    Node* n=nullptr;
    Add(&n,1);
    Add(&n,2);
    Add(&n,3);
    Add(&n,4);
    Add(&n,5);
    Add(&n,6);

    std::cout<<"Before Reverse:";
    PrintList(n);
    std::cout<<"After Reverse:";
    n=ReverseList(&n);
    PrintList(n);
    return 0;
}
