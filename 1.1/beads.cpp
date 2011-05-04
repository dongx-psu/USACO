/*
TASK:beads
LANG:C++
*/
#include<iostream>
#include<fstream>
using namespace std;

int n;
char s[701];

int main()
{
    freopen("beads.in","r",stdin);
    freopen("beads.out","w",stdout);
    
    int i,res=0,pre=0,curr=0,w=0,color=0;
    scanf("%d", &n);
    for(i=0; i<n; i++) cin >>s[i];
    for(i=0; i<n; i++) s[n+i]=s[i];
    for(i=0; i<n*2 && res<n; i++)
    {
             if (s[i]=='w') w++,curr++;
             else if (s[i]==color) w=0,curr++;
             else
             {
                 color=s[i];
                 if (pre+curr > res) res=pre+curr;
                 pre=curr-w; curr=w+1; w=0;
             }
    }
    if(pre+curr>res) res=pre+curr;
    printf("%d\n", res<n?res:n);
     
    return 0;
}
