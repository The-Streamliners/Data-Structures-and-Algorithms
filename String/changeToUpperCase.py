def uppercase(str_data):
    '''Python program to convert the string to uppercase without inbuild functions'''
    result = ''
    for char in str_data:
        if ord(char) >= 97 and ord(char)<=122:
            result += chr(ord(char) - 32)
        else:
            result+=char
    return result

uppercase("Hello World")
