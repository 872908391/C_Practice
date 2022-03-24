#include <stdio.h>
int isPrime(unsigned int N);
int main(int argc, char **argv)
{
    int N;
    printf("%d\n",isPrime(N));
    return 0;
}

//复杂度为O(根号N)
int isPrime(unsigned int N)
{
    if (N == 1)
        return 0;
    if (N % 2 == 0)
        return 0;
    if (N == 2)
        return 0;
    for (int i = 3; i*i <= N; i += 2)
    {
        if (N % i == 0)
            return 0;
    }
    return 1;
}