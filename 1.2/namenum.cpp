/*
TASK:namenum
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

ifstream dict("dict.txt");
ifstream fin("namenum.in");
ofstream fout("namenum.out");

const char dic[26]={'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','0','7','7','8','8','8','9','9','9','0'};

int main()
{
    string a,b,c;
    fin >>a;
    bool flag=false;
    while(dict >>b)
    {
        if(a.size()!=b.size()) continue; 
        c.assign("");
        for(int i=0; i<b.size(); i++)
          c=c+dic[b[i]-'A'];
        if(a==c) 
          {
                 flag=true;
                 fout <<b <<endl;
          }
    }
    if(!flag) fout <<"NONE" <<endl;

    return 0;
}
