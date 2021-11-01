def isPalindrome(word):
  for i in range(0, int((len(word)/2))):
    if(word[i] != word[(len(word)-1)-i]):
      return False
  return True

print(isPalindrome("ABBA"))
print(isPalindrome("Foo"))