#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
#include <string>
#include <string.h>
using namespace std ;

typedef string stack_elm_type ;

class stacklist
{
private:
    struct node ;
    typedef node* link ;
    struct node
    {
        stack_elm_type elem ;
        link next ;
    };
    link head ;
public:
    stacklist() ;
    void push (const stack_elm_type &item) ;
    string pop () ;
    string top () ;
    bool IsEmpty() ;
} ;

stacklist :: stacklist()
{
    head=NULL ;
}

void stacklist :: push (const stack_elm_type &item)
{
    link addednode ;
    addednode=new node ;
    addednode->elem=item ;
    addednode->next=head ;
    head=addednode ;
}

string stacklist :: pop()
{
        stack_elm_type tempo ;
        tempo=head->elem ;
        head=head->next ;
        return tempo ;

}

string stacklist :: top()
{
    stack_elm_type tempo ;
    tempo=head->elem ;
    return tempo ;
}

bool stacklist :: IsEmpty()
{
    if(head==NULL)
        return 1 ;
    else
        return 0 ;
}

#endif // STACK_H_INCLUDED
