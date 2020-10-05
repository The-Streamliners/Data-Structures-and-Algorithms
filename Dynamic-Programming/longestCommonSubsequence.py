# The following solution has time complexity of o(mn) and space complexity of o(m+n) where m is the length of the first input and n is the length of the second input.

# The purpose of the solution is to find the longest common subsequence between 2 strings.
# Example – 
# Input = abcd, abdf
# Output = 3 because abd is the longest subsequence (Continuation does not matter just need to be in the same sequence)


def longest_common_subsequence(X , Y): 
    x = len(X) 
    y = len(Y) 
  
    L = [[None]*(y+1) for i in range(x+1)] 

    for i in range(x+1): 
        for j in range(y+1): 
            if i == 0 or j == 0 : 
                L[i][j] = 0
            elif X[i-1] == Y[j-1]: 
                L[i][j] = L[i-1][j-1]+1
            else: 
                L[i][j] = max(L[i-1][j] , L[i][j-1]) 

    return L[x][y] 

print(longest_common_subsequence(input(), input()))
