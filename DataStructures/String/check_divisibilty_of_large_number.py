# To check divisibility of any large number by 999
def check_divisibilty(large_num):
    num_len = len(large_num)
    sum_of_digits = 0
     
    for i in range(0,num_len) :
        sum_of_digits = sum_of_digits + (int)(large_num[i])

    return sum_of_digits % 9 == 0

if (check_divisibilty('999999')):
    print('Divisble by 999')
else:
    print('Not divisible by 999')