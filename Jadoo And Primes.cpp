#include <iostream>
#include <cstring>
#include <vector>
#define size 100000000
using namespace std;

bool arr[size+1];

int main()
{
    memset(arr, true, sizeof(arr));
    arr[0] = arr[1] = false;
    for (unsigned long long int i = 2; i * i <= size; i++)
    {
        if (arr[i] == true)
        {
            for (unsigned long long int j = i * i; j <= size; j += i)
                arr[j] = false;
        }
    }

    int t;
    cin >> t;
    while(t--)
    {
        long long range;
        cin >> range;
        unsigned long long int sum = 0;
        for(int i=0,j=0;j<range;i++)
        {
            if(arr[i])
            {
                sum+=i;
                j++;
            }
        }
        cout<<sum<<endl;
    }

    return 0;
}
