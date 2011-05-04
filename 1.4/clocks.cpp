/*
TASK:clocks
LANG:C++
*/
#include<iostream>
#include<fstream>
using namespace std;

int tot=0;
int a[9],b[9],s[10];
int ans[30];

void calc()
{
	bool flag=true;
	b[0]=(a[0]+3*(s[1]+s[2]+s[4]))%12;
	b[1]=(a[1]+3*(s[1]+s[2]+s[3]+s[5]))%12;
	b[2]=(a[2]+3*(s[2]+s[3]+s[6]))%12;
	b[3]=(a[3]+3*(s[1]+s[4]+s[5]+s[7]))%12;
	b[4]=(a[4]+3*(s[1]+s[3]+s[5]+s[7]+s[9]))%12;
	b[5]=(a[5]+3*(s[3]+s[5]+s[6]+s[9]))%12;
	b[6]=(a[6]+3*(s[4]+s[7]+s[8]))%12;
	b[7]=(a[7]+3*(s[5]+s[7]+s[8]+s[9]))%12;
	b[8]=(a[8]+3*(s[6]+s[8]+s[9]))%12;
	for(int i=0; i<9; i++)
	  if(b[i]!=0)
       {
	  	 flag=false;
	  	 break;
       }
 	if(flag)
 	{
 		for(int i=1; i<=9; i++)
 		{
			int tmp=s[i];
			while(tmp>0)
			{
				ans[tot]=i;
				tmp--; tot++;
			} 	
		}
	}
}

int main()
{
	freopen("clocks.in","r",stdin);
	freopen("clocks.out","w",stdout);
	int i;
	for(i=0; i<9; i++) scanf("%d", &a[i]);
	for(s[1]=0; s[1]<4; s[1]++)
		for(s[2]=0; s[2]<4; s[2]++)
			for(s[3]=0; s[3]<4; s[3]++)
		 		for(s[4]=0; s[4]<4; s[4]++)
		 			for(s[5]=0; s[5]<4; s[5]++)
		 				for(s[6]=0; s[6]<4; s[6]++)
		 					for(s[7]=0; s[7]<4; s[7]++)
		 						for(s[8]=0; s[8]<4; s[8]++)
		 							for(s[9]=0; s[9]<4; s[9]++) calc();
	for(i=0; i<tot-1; i++) printf("%d ", ans[i]);
	printf("%d\n", ans[tot-1]);
	
	return 0;
}
