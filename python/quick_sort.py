# partition
def partition(arr, start, end):
  pivot = arr[end]
  p_index = start
  
  for i in range(start, end+1):
    if arr[i] < pivot:
      arr[i], arr[p_index] = arr[p_index], arr[i]
      p_index += 1
  
  arr[end], arr[p_index] = arr[p_index], arr[end]
  return p_index

# quick sort
def quick_sort(arr, start, end):
  if start >= end:
    return None
  
  p_index = partition(arr, start, end)
  quick_sort(arr, start, p_index-1)
  quick_sort(arr, p_index+1, end)

#driver program
input = [3, 5, 1, 9, 2]
print(input)

quick_sort(input, 0, len(input)-1)
print(input)