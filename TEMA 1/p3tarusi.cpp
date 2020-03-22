#include <iostream>
using namespace std;
struct nod{
    int info;
    nod *next;
}*prim;
void push(int x){
    nod *t=new nod;
    t->info=x;
    t->next=prim;
    prim=t;
}
int pop(){
    nod *t=prim;
    int x=t->info;
    prim=prim->next;
    delete t;
    return x;
}
int main()
{
    int v[8]={1, 2, 2, 3, 1, 4, 3, 4};
    push(v[0]);
    for(int i=1;i<8;++i)
        if(prim && v[prim->info] == v[i])
            pop();
        else
            push(v[i]);
    if(prim)
        cout<<"INVALID";
    else
        cout<<"VALID";
    return 0;
}
