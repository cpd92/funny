#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct HNode
{
    char val;
    int frequent;
    std::shared_ptr<HNode> left=nullptr;
    std::shared_ptr<HNode> right=nullptr;
};

struct Com
{
    bool operator()(const std::shared_ptr<HNode>& lhs,const std::shared_ptr<HNode>& rhs)
    {
        return lhs->frequent>rhs->frequent;
    }
};

void PrintHuffManTree(std::shared_ptr<HNode> node,const std::string& huff_code)
{
    if(node==nullptr)
        return;

    if(node->val!='$')
    {
        std::cout<<node->val<<" "<<huff_code<<std::endl;
    }

    PrintHuffManTree(node->left,huff_code+"0");
    PrintHuffManTree(node->right,huff_code+"1");
}

std::shared_ptr<HNode> CreateHuffManTree(char val_list[],int fre_list[],int size)
{
    std::priority_queue<std::shared_ptr<HNode>,std::vector<std::shared_ptr<HNode> >,Com > pquent;

    for(int i=0;i<size;++i)
    {
        std::shared_ptr<HNode> _HNode(new HNode);
        _HNode->val=val_list[i];
        _HNode->frequent=fre_list[i];

        pquent.push(_HNode);
    }

    while(pquent.size()!=1)
    {
        std::shared_ptr<HNode> left_node=pquent.top();
        pquent.pop();
        std::shared_ptr<HNode> right_node=pquent.top();
        pquent.pop();

        std::shared_ptr<HNode> S(new HNode);
        S->val='$';
        S->frequent=left_node->frequent+right_node->frequent;
        S->left=left_node;
        S->right=right_node;

        pquent.push(S);
    }

    return pquent.top();
}



int main()
{
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 2, 10, 15, 18, 20, 30 };
    std::shared_ptr<HNode> node=CreateHuffManTree(arr,freq,sizeof(arr)/sizeof(arr[0]));
    PrintHuffManTree(node,"");
    return 0;
}
