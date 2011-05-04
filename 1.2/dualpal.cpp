/*
TASK:dualpal
LANG:C++
*/
#include<fstream>
#include<cstring>
using namespace std;

const int maxint = 1<<31-1;

ifstream fin("dualpal.in");
ofstream fout("dualpal.out");

bool be(int x, int b)
{
     int ss[50];
     int i=0;
     while(x>0)
     {
          ss[i++]=x%b;
          x/=b;
     }
     int nn=i;
     for(i=0; i<nn; i++)
       if(ss[i]!=ss[nn-i-1]) return 0;
     return 1;
}

bool check(int x)
{
     int t=2;
     for(int i=2; i<=10; i++)
        if(be(x,i))
        {
             t--;
             if(t==0) return 1;
        }
     return 0;
}

int main()
{
    int n, k, nn=0;
    fin >>n >>k;
    for(int i=k+1; i<=maxint; i++)
      if(check(i))
      {
         nn++; fout <<i <<endl;
         if(nn==n) break;
      } 
    
    return 0;
}
