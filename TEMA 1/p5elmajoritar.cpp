#include <iostream>
using namespace std;

int main()
{
    int n,v[100];
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>v[i];
    int maj=v[0];
    int cnt=1;
    for(int i=0;i<n;++i)
        if(v[i]==maj)
            cnt++;
        else{
            cnt--;
            if(cnt<0){
                maj=v[i];
                cnt=1;
            }
        }
    cnt=0;
    for(int i=0;i<n;++i)
        if(v[i]==maj)
            cnt++;
    if(cnt>n/2)
        cout<<"Elementul majoritar este: "<<maj;
    else
        cout<<"Nu exista";
    return 0;
}
