/*
TASK:packrec
LANG:C++
*/
#include<iostream>
#include<fstream>
using namespace std;

const int inf=1000000;
int a[4][2], ans[100][2];
int tot=0, best=inf;
int s1,s2,s3,s4,d1,d2,d3,d4,w,h;

void update()
{
	if(w*h>best) return;
	if(w*h<best) best=w*h, tot=0;
	if(w>h) swap(w,h);
	for(int i=0; i<tot; i++)
		if(ans[i][0]==w && ans[i][1]==h) return;
	ans[tot][0]=w; ans[tot][1]=h;
	tot++;
}

void calc()
{
	int w1=a[s1][d1], w2=a[s2][d2], w3=a[s3][d3], w4=a[s4][d4];
	int h1=a[s1][1^d1], h2=a[s2][1^d2], h3=a[s3][1^d3], h4=a[s4][1^d4];
 	w=w1+w2+w3+w4;
 	h=max(max(max(h1,h2),h3),h4);
 	update();
 	w=max(w1+w2+w3,w4);
	h=max(max(h1,h2),h3)+h4;
 	update();
 	w=max(w1+w2,w3)+w4;
	h=max(max(h1,h2)+h3,h4);
	update();
	w=w1+w2+max(w3,w4);
	h=max(max(h1,h2),h3+h4);
	update();
	h=max(h1+h3,h2+h4);
	if(h4>=h1+h3) w=max(max(w2,w1+w4),w3+w4);
	if(h3>=h2+h4) w=max(max(w1,w2+w3),w4+w3);
	if(h3>h4 && h3<h4+h2) w=max(max(w1+w2,w2+w3),w3+w4);
	if(h4>h3 && h4<h3+h1) w=max(max(w1+w2,w1+w4),w3+w4);
	if(h3==h4) w=max(w3+w4,w1+w2);
	update(); 	
}

int main()
{
	freopen("packrec.in","r",stdin);
	freopen("packrec.out","w",stdout);
	int i, j;
	for(i=0; i<4; i++) scanf("%d%d", &a[i][0], &a[i][1]);
	for(s1=0; s1<4; s1++)
		for(s2=0; s2<4; s2++)
 		if(s1!=s2)
	    {
	    	for(s3=0; s3<4; s3++)
	    	if(s2!=s3 && s3!=s1)
	    	{
	    		s4=6-s1-s2-s3;
	    		for(d1=0; d1<2; d1++)
   		  			for(d2=0; d2<2; d2++)
   		  				for(d3=0; d3<2; d3++)
   		  					for(d4=0; d4<2; d4++) calc();
	    	}
	    }
	for(i=0; i<tot; i++)
	  for(j=i+1; j<tot; j++)
	    if(ans[i][0]>ans[j][0])
	    {
    	 	swap(ans[i][0],ans[j][0]); 
    	 	swap(ans[i][1],ans[j][1]);
    	}
	printf("%d\n", best);
	for(i=0; i<tot; i++)
	  printf("%d %d\n", ans[i][0], ans[i][1]);
		
	return 0;
}
