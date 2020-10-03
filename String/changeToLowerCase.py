def lowercase(str_data):
    '''Python program to convert the string to lowercase without inbuilt functions'''
    result = ''
    for char in str_data:
        if ord(char) >= 65 and ord(char)<=90:
            result += chr(ord(char) + 32)
        else:
            result+=char
    return result


print(lowercase("HeLLo WorLD"))
print(lowercase("HeLLo wOrLD"))

