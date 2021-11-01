# Python implementation of gnome sort
# This program is a sorting technique which is also called as stupid sort
# Contributed by Amit Zope
# github link :https://github.com/amitsat27
# userid : amitsat27

# Gnome sort function which helps to sort the array
def gnomesort(array,size): 
    # initialising index to 0
	index = 0
	while(index < size):
        # checks if index is zero if zero increments index by 1 
		if(index == 0): 
			index = index + 1
        # checks if present element is larger than previous element
        # if larger then goes to right of array increments index
		if(array[index] >= array[index - 1]): 
			index = index + 1
		else: 
            # else if present element is smaller then 
            # it swaps the two elements and goes to left decrements index value
			array[index], array[index-1] = array[index-1], array[index] 
			index = index - 1

	return array
# declaring array of numbers
arrayofNumbers = [8,1,6,9,2,-1]
# taking length of array of numbers
size = len(arrayofNumbers) 
# function call for gnomeSort
arrayofNumbers = gnomesort(arrayofNumbers, size) 
# printing the sorted array
print("Sorted Numbers after applying Gnome sort : ") 
for i in arrayofNumbers: 
	print(i,end=" ") 


