import sys
import array
temp_array = array.array('i', [1, 2, 3, 4, 5, 6])
print("The newly created array is:")
for i in range(0, 6):
    print(temp_array[i])
print("The size of the array:", sys.getsizeof(temp_array))