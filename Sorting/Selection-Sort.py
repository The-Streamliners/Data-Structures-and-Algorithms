A = [64, 25, 12, 22, 11, -54, -10, 100, 0, -87]  
for i in range(len(A)): 
	min_idx = i 
	for j in range(i+1, len(A)): 
		if A[min_idx] > A[j]: 
			min_idx = j 		 
	A[i], A[min_idx] = A[min_idx], A[i] 

print ("Sorted array : ",A)
