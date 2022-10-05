// This is a program which help us to find the nCr where  'n' and 'r' are provided by the user.

#include <iostream>
using namespace std;

// Function to find the factorial of a number
int get_factorial(int num)
{
    int result = 1;
    for (int i = 1; i <= num; i++)
    {
        result = result * i;
    }
    return result;
}

// Function to find the nCr
int nCr(int n, int r)
{
    int numerator = 0;
    int denominator = 0;
    numerator = get_factorial(n);
    denominator = get_factorial(r) * get_factorial(n - r);
    return numerator / denominator;
}

// This is our main function
int main()
{
    int n, r;
    cin >> n;
    cin >> r;
    cout << "nCr =" << nCr(n, r) << endl;
}
