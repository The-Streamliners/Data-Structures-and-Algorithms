def uppercase(str_data):
    '''Python program to convert the string to uppercase without inbuild functions'''
    result = ''
    for char in str_data:
        if ord(char) >= 65:
            result += chr(ord(char) - 32)
    return result

uppercase("HAI")
