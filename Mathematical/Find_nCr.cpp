//Calculate nCr in O(rlogn)

long long combination(int n, int r)
{
    long long ans = 1, k = 1, m = 1;
    if (n - r < r)r = n - r;
    if (r != 0) {
        while (r) {
            ans = ans*n;k = k*r;
            m = __gcd(ans, k);
            ans = ans/m;k = k/m;
            n--;r--;
        }
    }
    else ans = 1;
    return ans;
}
