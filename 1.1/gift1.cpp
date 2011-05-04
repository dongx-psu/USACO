/*
TASK:gift1
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct people
{
  string name;
  int money;
}p[10];

int main()
{
    freopen("gift1.in","r",stdin);
    freopen("gift1.out","w",stdout);
           
    int n,i,j,money,num;
    string name;
    scanf("%d", &n);
    for(i=0; i<n; i++)
      cin >>p[i].name;
    for(i=0; i<n; i++)
    {
        cin >>name >>money >>num;
        for(j=0; j<n; j++)
          if (p[j].name==name) break;
        if(num!=0) p[j].money+=money%num;  
        p[j].money-=money;
        for(j=0; j<num; j++)
        {
           cin >>name;
           for(int k=0; k<n; k++)
             if(p[k].name==name)   
               {
                 p[k].money+=money/num;
                 break; 
               }   
        }  
    }
    for(i=0; i<n; i++)
      cout <<p[i].name <<" " <<p[i].money <<endl;
	return 0;
}
