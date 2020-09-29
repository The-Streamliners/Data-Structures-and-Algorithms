# Python program to check if a number is an Armstrong number or not

num = int(input("Enter a number: "))
order = len(str(num))
n = 0
temp = num
while temp > 0:
    digit = temp % 10
    n += digit ** order
    temp = temp/10
if num == n:
    print(num, "is an Armstrong number")
else:
    print(num, "is not an Armstrong number")
