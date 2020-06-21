#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int l,r;
    cin>>l>>r;
    bool prime[r+1];
    memset(prime,true,sizeof(prime));
    prime[0]=prime[1]=false;
    for(int i=2;i*i<=r;i++)
    {
        if(prime[i]==true)
        {
            for(int j=i*i;j<=r;j+=i)
                prime[j]=false;
        }
    }
    for(int i=l;i<=r;i++)
        if(prime[i]==true)
            cout<<i<<" ";
    cout<<endl;

    return 0;
}
