def pigeonhole_sort(arr): 
    
    my_min = min(arr) 
    my_max = max(arr) 
    size = my_max - my_min + 1
  
     
    holes = [0] * size 
  
     
    for x in arr: 
        assert type(x) is int, "integers only please"
        holes[x - my_min] += 1
  
    
    i = 0
    for count in range(size): 
        while holes[count] > 0: 
            holes[count] -= 1
            arr[i] = count + my_min 
            i += 1
              
  
arr = [3, 23, 21, 0, 100, 13, 10] 
print("After sorting"),
  
pigeonhole_sort(arr) 
          
for i in range(0, len(arr)): 
    print(arr[i])
