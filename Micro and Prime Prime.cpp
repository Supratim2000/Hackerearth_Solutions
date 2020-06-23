#include<iostream>
#include<cstring>
typedef long long ll;
#define Nmax 1000000
using namespace std;

bool prime[Nmax+1];
int count[Nmax+1];
int result[Nmax+1];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    memset(prime,true,sizeof(prime));
    prime[0]=prime[1]=false;
    for(int i=2;(ll)i*i<=Nmax;i++)
    {
        if(prime[i])
        {
            for(int j=(ll)i*i;j<=Nmax;j+=i)
                prime[j]=false;
        }
    }

    //memset(count,0,sizeof(count));
    for(int i=2;i<=Nmax;i++)
    {
        if(prime[i])
            count[i]=count[i-1]+1;
        else
            count[i]=count[i-1];
    }

    int temp=0;
    for(int i=2;i<=Nmax;i++)
    {
        if(prime[count[i]])
            result[i]=++temp;
        else
            result[i]=temp;
    }


    int t;
    scanf("%d",&t);
    while(t--)
    {
        int l,r;
        int ppcount=0;
        scanf("%d%d",&l,&r);
        printf("%d\n",result[r]-result[l-1]);
    }
    return 0;
}
