#include <iostream>
#include <cmath>
using namespace std;

long long getgcd(long long a, long long b)
{
    long long temp = 0;
    while (b > 0)
    {
        temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

long long getlcm(long long a, long long b)
{
    return a * b / getgcd(a, b);
}

int main()
{
    while (1)
    {
        long long M, N;
        cin >> M >> N;
        if (M == 0 && N == 0)
            return 0;

        while (M != 1)
        {
            int temp = (int)ceil((double)N / (double)M);
            while (1)
            {
                long long lcm = getlcm(N, temp);

                long long numerator = (lcm / N) * M;
                long long denominator = (lcm / temp);
                long long res = numerator - denominator;

                long long gcd = getgcd(res, lcm);
                res /= gcd;
                lcm /= gcd;
                if (lcm >= 1000000)
                    temp += 1;
                else
                {
                    cout << temp << " ";
                    M = res;
                    N = lcm;
                    break;
                }
            }
        }
        cout << N << endl;
    }
}