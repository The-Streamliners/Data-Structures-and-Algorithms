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