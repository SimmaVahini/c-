#include <iostream>
using namespace std;
int main()
{
    int n, sum = 0;
    int a[50];
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter array elements:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum = sum + a[i];
    }
    cout << "Sum of array elements = " << sum;
    return 0;
}
