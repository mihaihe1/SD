#include <iostream>
using namespace std;
struct coada{
    int info;
    coada *next,*prev;
}*lft,*rgt;
void push_left(int x){
    coada *t=new coada;
    t->info=x;
    if(lft==NULL){
        t->next=NULL;
        t->prev=NULL;
        lft=t;
        rgt=t;
    }
    else{
        t->next=lft;
        t->prev=NULL;
        lft->prev=t;
        lft=t;
    }
}
void push_right(int x){
    coada *t=new coada;
    t->info=x;
    if(rgt==NULL){
        t->next=NULL;
        t->prev=NULL;
        rgt=t;
        lft=t;
    }
    else{
        t->next=NULL;
        t->prev=rgt;
        rgt->next=t;
        rgt=t;
    }
}
int pop_left(){
    if(lft==NULL)
        return -1;
    coada *q=lft;
    int x=q->info;
    if(lft->next==NULL){
        lft=NULL;
        rgt=NULL;
        delete q;
        cout<<"Eliminat din stanga: ";
        return x;
    }
    lft=lft->next;
    lft->prev=NULL;
    delete q;
    cout<<"Eliminat din stanga: ";
    return x;
}
void afis(coada *p){
    if(p==NULL){cout<<"Coada vida";}
    else{
    while(p!=NULL){
        cout<<p->info<<" ";
        p=p->next;
    }
    }
    cout<<"\n";
}
int pop_right(){
    if(rgt==NULL)
        return -1;
    coada *q=rgt;
    int x=q->info;
    if(rgt->prev==NULL){
        rgt=NULL;
        lft=NULL;
        delete q;
        cout<<"Eliminat din dreapta: ";
        return x;
    }
    rgt=rgt->prev;
    rgt->next=NULL;
    delete q;
    cout<<"Eliminat din dreapta: ";
    return x;
}
int main()
{
    push_left(1);
    push_right(2);
    cout<<pop_right()<<"\n";
    cout<<pop_left()<<"\n";
    push_right(3);
    afis(lft);
    return 0;
}
