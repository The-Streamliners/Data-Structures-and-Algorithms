import sys
chain_list = input("Enter the matrix chain:")
chain = chain_list.split()
def MatrixChainOrder(chain):
    n = len(chain)
    table = [[0 for x in range(n)] for x in range(n)]
    for l in range(2,n):
        for i in range(1,n-l+1):
            j = i+l-1
            table[i][j] = sys.maxsize
            for k in range(i,j):
                q=table[i][k]+table[k+1][j]+int(chain[i-1])*int(chain[k])*int(chain[j])
                if q < table[i][j]:
                    table[i][j]=q
    return table[1][n-1]

print(MatrixChainOrder(chain))