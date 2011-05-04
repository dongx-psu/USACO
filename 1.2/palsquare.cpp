/*
TASK:palsquare
LANG:C++
*/
#include<fstream>
#include<string>
using namespace std;

ifstream fin("palsquare.in");
ofstream fout("palsquare.out");
int n;

string convert(int x)
{
  string dict="0123456789ABCDEFGHIJ";
  string s="";
  while(x>0)
  {
    s.insert(s.begin(),dict[x%n]);
    x/=n;
  }
  return s;
}

bool check(string s)
{
  for(int i=0; i<s.size(); i++)
    if(s[i]!=s[s.size()-i-1]) return 0;
  return 1;
}

int main()
{
  fin >>n;
  
  int a[100],b[100];
  for(int i=1; i<=300; i++)
  {
    int now=i;
    int squ=i*i;
    string s1=convert(now);
    string s2=convert(squ);
    if(check(s2))
    {
      fout <<s1 <<" " <<s2 <<endl;
    }  
  }  
}
