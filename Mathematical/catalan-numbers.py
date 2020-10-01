inumber = input("Enter the range: ")
inumber = int(inumber)


def catalan(n):
    if n <= 1:
        return 1
    # Catalan(n) = catalan(i)*catalan(n-i-1) is the formula
    res = 0
    for i in range(n):
        res += catalan(i) * catalan(n-i-1)
    return res


for i in range(inumber):
    print(catalan(i))
