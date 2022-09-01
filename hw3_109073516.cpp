#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int q[200010],s[200010];
int temp=0;
signed main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;cin>>a;
        q[++temp]=a;
        if(temp==1 || q[temp]!=q[temp-1])
        {
            s[temp]=1;
        }
        else s[temp] = s[temp-1] + 1;
        if( s[temp] == a ) temp -= a;
        cout<<temp<<' ';
    }
}