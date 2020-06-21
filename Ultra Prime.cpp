#include<iostream>
#include<cstring>
#include<cmath>
#define size 1000001
using namespace std;

bool arr[size];

int main()
{

	memset(arr,true,sizeof(arr));
	arr[0]=arr[1]=false;
	for(int i=2;i*i<=size;i++)
	{
		if(arr[i])
		{
			for(int j=i*i;j<=size;j+=i)
				arr[j]=false;
		}
	}

    int cucount[size],count=0;
	memset(cucount,0,sizeof(cucount));
	cucount[0]=cucount[1]=0;
	for(int i=2;i<=size;i++)
	{
		if(arr[i])
		{
			int sum=0,temp=i;
			while(temp)
			{
				sum+=temp%10;
				temp/=10;
			}
			if(arr[sum])
				count++;
		}
		cucount[i]=count;
	}

	int t;
	cin>>t;
	while(t--)
	{
		int l,r;
		int count=0;
		cin>>l>>r;

		cout<<cucount[r]-cucount[l-1]<<endl;
	}

	return 0;
}
