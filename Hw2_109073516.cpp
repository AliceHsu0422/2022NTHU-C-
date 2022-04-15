#include <iostream>
using namespace std;

int main()
{
    printf("Please enter an amount of money to split(1~99): \n");
    int money, dollar_20, dollar_10, dollar_5, dollar_1;
    cin >> money;
    dollar_20 =  money/20;
    dollar_10 = (money-dollar_20*20)/10;
    dollar_5 = (money-dollar_20*20-dollar_10*10)/5;
    dollar_1 = money-(dollar_20*20+dollar_10*10+dollar_5*5);
    cout << "20-dollar bill(s) = " << dollar_20 << endl;
    cout << "10-dollar bill(s) = " << dollar_10 << endl;
    cout << "5-dollar bill(s) = " << dollar_5 << endl;
    cout << "1-dollar bill(s) = " << dollar_1 << endl;
    return 0;
}



