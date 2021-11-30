#include "/Users/swassow/Downloads/stdc++.h"

using namespace std;

class node{
public:
    int data;
    node *link;
};
node *head=NULL;

void push(int val)
{
    node *ptr;
    ptr=new node();
    ptr->data=val;
    ptr->link=head;
    head=ptr;
}
void pop()
{
    head=head->link;
}
int top()
{
    return head->data;
}

int main()
{
    push(3);
    push(4);
    push(1);
    push(5);
    cout<<top()<<endl;
    pop();
    cout<<top()<<endl;
}
