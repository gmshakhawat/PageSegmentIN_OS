#include<bits/stdc++.h>
using namespace std;

int main()
{

    int a=4;
    int p0,p1;
    if(((a>>0)& 1))p0=1;
    else p0=0;
    if(((a>>0)& 1))p1=2;
    else p1=0;
    int p=1,s=0;
        for(int i=0;i<10;i++)
        {
            if(((a>>i)& 1)){

                s+=p;

            }
            else p+=p;
        }

        cout<< s;


    //cout<<p2<<"\t"<<p3<<endl;


    return 0;
}
