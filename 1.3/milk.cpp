/*
TASK:milk
LANG:C++
*/
#include<fstream>
#include<algorithm>
using namespace std;

ifstream fin("milk.in");
ofstream fout("milk.out");
int n,m;
struct milk
{
       int price,num;
}a[5001];

bool cmp(milk x, milk y)
{
     return x.price<y.price;
}

int main()
{
    fin >>n >>m;
    int i;
    for(i=0; i<m; i++)
       fin >>a[i].price >>a[i].num;
    sort(a, a+m, cmp);
    
    int res=0;
    for(i=0; i<m && n>=a[i].num; i++)
    {
             res+=a[i].num*a[i].price;
             n-=a[i].num;
    }
    res+=n*a[i].price;
    fout <<res <<endl;
    
    return 0;
}
