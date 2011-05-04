/*
TASK:preface
LANG:C++
*/
#include<iostream>
#include<fstream>
using namespace std;

int n,i,v,x,l,c,d,m;

int main()
{
	freopen("preface.in","r",stdin);
	freopen("preface.out","w",stdout);
	
	scanf("%d", &n);
	for(int p=1; p<=n; p++)
	{
		int k=p;
		do
		{
			if (k>=1000){k-=1000; m++;}
    	    else if(k<1000&&k>=900){k-=900; m++; c++;}
  	  		else if(k<900&&k>=500){k-=500; d++;}
       		else if(k<500&&k>=400){k-=400; d++; c++;}
     		else if(k<400&&k>=100){k-=100; c++;}
	        else if(k<100&&k>=90){k-=90; c++; x++;}
	        else if(k<90&&k>=50){k-=50; l++;}
	        else if(k<50&&k>=40){k-=40; x++; l++;}
	        else if(k<40&&k>=10){k-=10; x++;}
	        else if(k<10&&k>=9){k-=9; i++; x++;}
	        else if(k<9&&k>=5){k-=5; v++;}
	        else if(k<5&&k>=4){k-=4; i++; v++;}
	        else if(k<4&&k>=1){k--; i++;}
		}while(k>0);
	}
	if(i!=0) printf("I %d\n", i);
	if(v!=0) printf("V %d\n", v);
	if(x!=0) printf("X %d\n", x);
	if(l!=0) printf("L %d\n", l);
	if(c!=0) printf("C %d\n", c);
	if(d!=0) printf("D %d\n", d);
	if(m!=0) printf("M %d\n", m);
	
	return 0;
}
