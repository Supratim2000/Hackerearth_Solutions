#include<iostream>
#include<cstring>
#include<vector>
#define max_size 1000001
using namespace std;

int main()
{
    bool prime[max_size];
    memset(prime,true,sizeof(prime));
    prime[0]=prime[1]=false;
    for(int i=2;i*i<=max_size;i++)
    {
        if(prime[i])
        {
            for(int j=i*i;j<=max_size;j+=i)
                prime[j]=false;
        }
    }

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        vector<int> pr;
        for(int i=0;i<n;i++)
            if(prime[arr[i]])
                pr.push_back(arr[i]);

        long long sum=0;
        for(int i=k-1;i<pr.size();i+=k)
            sum+=pr.at(i);
        
        cout<<sum<<endl;
    }
    return 0;
}
