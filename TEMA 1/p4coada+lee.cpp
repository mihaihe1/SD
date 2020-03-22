#include <iostream>
using namespace std;
struct nod{
    int info;
    nod *next;
}*p;
void push(int x){
    nod *t=new nod;
    t->info=x;
    t->next=NULL;
    if(p==NULL)
        p=t;
    else{
    nod *q=p;
    while(q->next != NULL)
        q=q->next;
    q->next=t;
    }
}
int pop(){
    nod *t=p;
    if(t->next==NULL){
        int x=t->info;
        p=NULL;
        delete t;
        return x;
    }
    else{
    while(t->next->next != NULL)
        t=t->next;
    nod *q=t->next;
    int x=q->info;
    t->next=NULL;
    delete q;
    return x;
    }
}
void afis(nod *p){
    if(p==NULL)
        cout<<"Coada vida\n";
    else{
    while(p != NULL){
        cout<<p->info<<" ";
        p=p->next;
    }
    cout<<"\n";
    }
}
int main()
{
    int a[7][7]={{0,0,1,0,0,0,0},
                 {0,0,1,1,0,0,0},
                 {0,0,0,0,1,0,0},
                 {0,0,0,1,1,0,0},
                 {0,1,0,0,1,0,1},
                 {1,1,1,0,0,0,1},
                 {1,1,1,0,0,1,1}};
    int d1[4]={-1,0,1,0};
    int d2[4]={0,1,0,-1};
    int nr=1;
    int lin,col;
    for(int i=0;i<7;++i)
        for(int j=0;j<7;++j)
            if(a[i][j]==1){
        nr++;
        push(i);
        push(j);
        a[i][j]=nr;
        while(p != NULL){
            col=pop();
            lin=pop();
            for(int k=0;k<4;++k)
                if(lin+d1[k]>-1 && lin+d1[k]<7 && col+d2[k]>-1 && col+d2[k]<7)
                    if(a[lin+d1[k]][col+d2[k]]==1){
                        push(lin+d1[k]);
                        push(col+d2[k]);
                        a[lin+d1[k]][col+d2[k]]=nr;
                    }
        }
    }
    for(int i=0;i<7;++i)
    {
        for(int j=0;j<7;++j)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}
