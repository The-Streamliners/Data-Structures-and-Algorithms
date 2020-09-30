#To reverse the order of any 4 or more digit number
num=int(input("Enter the number"))
tnum=num
reverse=0
while tnum>0:
    digit=tnum%10
    
    reverse=reverse*10+digit
    tnum=tnum//10
    
print("The number in reverse order is",reverse)
