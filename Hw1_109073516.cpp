#include <iostream>
#define PI 3.14
using namespace std;

int main()
{
    printf("Please enter the radius of a sphere (in meter): ");
    float radius;
    cin >> radius;
    double surface;
    surface = 4 * PI * radius * radius;
    double volume;
    volume = (4.0 / 3.0) * PI * radius * radius * radius;
    cout << "The surface area of the sphere is: " << surface << "(square meter)\n";
    cout << "The volume of the sphere is: " << volume << "(square meter)\n";
    return 0; 
}