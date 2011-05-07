/*
TASK:humble
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<climits>
using namespace std;

void init();
void solve();
void print();

int k,n;
int num[201],dex[201],hum[200001];

int main()
{
    freopen("humble.in","r",stdin);
    freopen("humble.out","w",stdout);
    
    init();
    solve();
    print();
    
    return 0;
}

void init()
{
    scanf("%d%d", &k, &n);
    for(int i=0; i<k; i++)
        scanf("%d", &num[i]);
}

void solve()
{
    hum[0]=1;
    for(int i=1; i<=n; i++)
    {
        int ans=INT_MAX;
        for(int j=0; j<k; j++)
        {
            while(num[j]*hum[dex[j]]<=hum[i-1]) dex[j]++;
            if(num[j]*hum[dex[j]]<ans) ans=num[j]*hum[dex[j]];
        }
        hum[i]=ans;
    }
}

void print()
{
    printf("%d\n", hum[n]);
}
