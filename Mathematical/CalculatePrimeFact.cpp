//To count total number of prime numbers between 1 to 'a' in O(sqrt('a'))

int countPrimes(int a)
{
    int count = 0;
    for (int p = 2; p * p <= a; ++p)
    {
        while (a % p == 0)
        {
            a /= p;
            count++;
        }
    }
    if (a != 1)count++;
    return count;
}
