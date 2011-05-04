/*
TASK:ride
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);
    string s1, s2;
    cin>>s1; cin>>s2;
    int l1=s1.size();
    int l2=s2.size();
    int ans1=1,ans2=1;
    int i;
    for(i=0;i<l1;i++) ans1=(ans1*(s1[i]-64))%47;
    for(i=0;i<l2;i++) ans2=(ans2*(s2[i]-64))%47;
    if (ans1==ans2) cout<<"GO"<<endl;
    else cout<<"STAY"<<endl;
    return 0;
}
