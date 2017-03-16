
mylist = [1, 2, 3]
mylist.append(4)
print(mylist)

mylist.insert(1, 5)
print(mylist)

mylist = mylist[:-1]
print(mylist)

mylist.remove(1)
print(mylist)

mydict = {0:"hello", 1:"world"}

try:
  print(mydict[2])
except:
  print('error occurred')
  
  
