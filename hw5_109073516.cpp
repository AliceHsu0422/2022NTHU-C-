#include <iostream>
#include <string>
using namespace std;

int main()
{
	string cs1=" `1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./";
	string is1;
	while(getline(cin,is1))
	{
		
		for(int i=0;i<is1.length();i++)
		{
			if(is1[i]>='A'&&is1[i]<='Z')
			{
				is1[i]=is1[i]+32;
			}
			
			for(int t=0;t<cs1.length();t++)
			{
				if(is1[i]==cs1[0])
				{
					cout<<" ";
					break;
				}

				else if(is1[i]==cs1[t])
				{
					cout<<cs1[t-2];
					break;
				}
                else if(is1[i]=='<')
                {
                    cout<<'n';
                    break;
                }
                else if(is1[i]=='>')
                {
                    cout<<'m';
                    break;
                }
			}
		}
		cout<<endl;
	}
	return 0;
}

