
Factorial Of Large Number
Factorial Biginteger Arrays
Factorial of a non-negative integer n, denoted by n!, is the product of all positive integers less than or equal to n. Logic of calculating Factorial is very easy .

5! = 5 * 4 * 3 * 2 * 1 = 120. It can be calculated easily using any programming Language.

But Factorial of 100 has 158 digits. It is not possible to store these many digits even if we use "long long int". Following is a simple solution where we use an array to store individual digits of the result.

Here, I will try to give you a step by step method to solve the problem in C++/C:

factorial(n):

Create an array ‘res[ ]’ of MAX size where MAX is number of maximum digits in output.
Initialize value stored in ‘res[ ]’ as 1 and initialize ‘res_size’ (size of ‘res[ ]’) as 1.
Do following for all numbers from x = 2 to n......

a) Multiply x with res[ ] and update res[ ] and res_size to store the multiplication result.

multiply(res[ ], x)

Initialize carry as 0.
Do following for i = 0 to res_size – 1 .....

a) Find value of res[i] * x + carry. Let this value be prod.

b) Update res[i] by storing last digit of prod in it.

c) Update carry by storing remaining digits in carry.

Put all digits of carry in res[ ] and increase res_size by number of digits in carry

Below is C++ implementation:

#include<iostream>
using namespace std;

#define MAX 500

int multiply(int x, int res[], int res_size);

void factorial(int n)
{
    int res[MAX];

    res[0] = 1;
    int res_size = 1;

    for (int x=2; x<=n; x++)
    {
        res_size = multiply(x, res, res_size);
    }

    cout << "Factorial of given number is \n";
    for (int i=res_size-1; i>=0; i--)
        cout << res[i];
}

int multiply(int x, int res[], int res_size)
{
    int carry = 0;

    for (int i=0; i<res_size; i++)
    {
        int prod = res[i] * x + carry;
        res[i] = prod % 10;  
        carry  = prod/10;    
    }

    while (carry)
    {
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}

int main()
{
    factorial(100);
    return 0;
}
