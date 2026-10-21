#include <stdio.h>
#include <stdbool.h>

int makeNextSum(int n)
{
    // Basic Guard
    if (n <= 0)
    {
        return 1;
    }

    // Finding number of digits
    int nOfDigits = 0;
    int inter = n;

    while (inter != 0)
    {
        inter = (int)(inter / 10);
        nOfDigits++;
    }

    // Building array of digits
    int digits[nOfDigits];

    int remNum = n;
    int interT = n;
    for (size_t i = 0; i < nOfDigits; i++)
    {
        interT = remNum % 10;

        digits[i] = interT;

        remNum = (int)(remNum / 10);
    }

    // Calculating the sum on those digits
    int nextSum = 0;
    for (size_t i = 0; i < nOfDigits; i++)
    {
        nextSum += digits[i] * digits[i];
    }

    return nextSum;
}

bool isHappy(int n)
{
    // 1 is already happy.
    if (n == 1)
    {
        return true;
    }

    // First generation and current generation starting from the second generation for bypass fGen
    int fGen = makeNextSum(n);
    int cGen = makeNextSum(fGen);

    if (fGen == 1 || cGen == 1)
    {
        return true;
    }

    int limit = 0;
    while ((fGen != cGen) && (limit < 10))
    {
        cGen = makeNextSum(cGen);

        if (cGen == 1)
        {
            return true;
        }

        limit++;
    }

    return false;
}

int main()
{
    int tn;

    printf("Please enter you number: ");
    scanf("%d", &tn);

    printf("Is the number %d a happy one?::: %s \n", tn, isHappy(tn) ? "True" : "False");

    return 0;
}