/*
TASK:transform
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

int main()
{
    freopen("transform.in","r",stdin);
    freopen("transform.out","w",stdout);
    
    int n,i,j;
    char a[11][11];
    char b[11][11];
    int res[10];
    memset(res,0,sizeof(res));
    scanf("%d", &n);
    for(i=1; i<=n; i++)
     for(j=1; j<=n; j++)
       cin >>a[i][j];
    for(i=1; i<=n; i++)
     for(j=1; j<=n; j++)
       cin >>b[i][j];
    
    for(i=1; i<=n; i++)
      for(j=1; j<=n; j++)
      {  
        if(a[i][j]==b[j][n-i+1]) res[1]++;
        if(a[i][j]==b[n-i+1][n-j+1]) res[2]++;
        if(a[i][j]==b[n-j+1][i]) res[3]++;
        if(a[i][j]==b[i][n-j+1]) res[4]++;
        if(a[i][j]==b[i][j]) res[6]++;
        if(a[i][n-j+1]==b[j][n-i+1]) res[9]++;
        if(a[i][n-j+1]==b[n-i+1][n-j+1]) res[7]++;
        if(a[i][n-j+1]==b[n-j+1][i]) res[8]++;
      }
    for(i=1; i<10; i++)
      if(res[i]==n*n)
        {
          if(i<7) printf("%d\n", i);
          else printf("5\n");
          break;
        }
    if(i==10) printf("7\n");
    
    return 0;  
}
