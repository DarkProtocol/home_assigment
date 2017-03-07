def quickSort(array):
    if array == []: 
        return []
    else:
        first = array[0]
        left = quickSort([x for x in array[1:] if x < first])
        right = quickSort([x for x in array[1:] if x >= first])
        return left + [first] + right

array = [3, 2, 1, 5, 7]

array = quickSort(array)

print(array)