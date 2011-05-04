/*
TASK:friday
LANG:C++
*/
#include<iostream>
#include<fstream>
using namespace std;

const int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int ans[7];

bool leap(int x)
{
    if (x%4==0 && x%100!=0 || x%400==0) return 1;
    return 0;
}

int main()
{
    freopen("friday.in","r",stdin);
    freopen("friday.out","w",stdout);
    
    int n,now,days,i,j;
    scanf("%d", &n);
    now=0;
    for(i=1900; i<1900+n; i++)
      for(j=0; j<12; j++)
         {
           days=a[j];
           if (j==1 && leap(i)) days++;
           ans[(now+13)%7]++;
           now+=days;
         }
    
    printf("%d %d", ans[6], ans[0]);
    for(i=1; i<6; i++)
      printf(" %d", ans[i]);
    printf("\n");
    
    return 0;
}
