//# Implement all the functions of a dictionary (ADT) using hashing and 
// handle collisions using chaining #with / without replacement. 
//Data: Set of (key, value) pairs, Keys are mapped to values, 
//Keys must be comparable, a)Keys must be unique. 
//Standard Operations: Insert(key, value), Find(key), Delete(key) 
table = []
b,totl = 0,0
buckets = {}
def create():
 global b
 b = int(input("Enter the table size: "))
 for i in range(b):
  table.append([None,-1])
  buckets[i] = -1
def printtable():
 global b
 for i in range(b):
  print(table[i],end="|")
 print("")

def chaininsert(key):
 global b,totl
 hash = key%b
 if(table[hash][0]==None):
  table[hash][0] = key
  buckets[key%b]=hash
 else:
  flag = 0
  for i in range(b):
   hash = (key+i)%b
   if(table[hash][0]==None):
    table[hash][0] = key
    flag=1
    totl+=1
    if buckets[key%b] != -1:
     table[buckets[key%b]][1] = hash
    buckets[key%b] = hash
    break
  if(flag==0):
   print("Key cannot be accommodated, table full.")

def chainsearch(key):
 global b
 hash = key%b
 if(table[hash][0]==key):
  print("Key : ",key," found at index : ",hash)
 else:
  flag,i,chain = 0,0,-1
  while(table[hash][0]%b != key%b):
   hash = (key+i)%b
   chain = table[hash][1]
   if (table[hash][0]==key):
    print("Key : ",key," found at index : ",hash)
    chain = -1
    flag = 1
    break
   i += 1
  else:
      chain = table[hash][1]
  while(chain != -1):
   value = table[chain][0]
   if (value==key):
    print("Key : ",key," found at index : ",chain)
    flag = 1
    break
   chain = table[chain][1] 
  if(flag==0):
   print("Key : ",key," not found.")

def chaindelete(key):
 global b
 hash = key%b
 if(table[hash][0]==key):
  table[hash][0],table[hash][1] = None,-1
  print("Key : ",key," deleted from index : ",hash)
 else:
  flag,i,pchain,chain = 0,0,-1,-1
  while(table[hash][0]%b != key%b):
   hash = (key+i)%b
   pchain = chain
   chain = table[hash][1]
   if (table[hash][0]==key):
    if (pchain!=-1):
     table[pchain][1] = table[chain][1]
     table[chain][0],table[chain][1] = None,-1
    else:
     table[chain][0],table[chain][1] = None,-1
    print("Key : ",key," deleted from index : ",hash)
    chain = -1
    flag = 1
    break
   i += 1
  else:
   pchain = hash
   chain = table[hash][1]
  while(chain != -1):
   value = table[chain][0]
   if (value==key):
    table[pchain][1] = table[chain][1]
    table[chain][0],table[chain][1] = None,-1
    print("Key : ",key," found at index : ",chain)
    flag = 1
    break
   pchain = chain
   chain = table[chain][1] 
  if(flag==0):
   print("Key : ",key," not found.")

create()
while(1):
 print("Enter 1-Chaining without replacement | 0-EXIT : ")
 n = int(input())
 if n==1:
  while(1):
   print("Enter 1-Insert | 2-Search | 3-Delete | 0-EXIT : ")
   ch = int(input())
   if(totl==b):
    print("Table Full")
    break
   else:
    if ch==1:
     key = int(input("Enter Key to be Inserted : "))
     chaininsert(key)
    elif ch==2:
     key = int(input("Enter Key to be Searched : "))
     chainsearch(key)
    elif ch==3:
     key = int(input("Enter Key to be Deleted : "))
     chaindelete(key)
    else:
     print("EXITING.")
     break
   printtable()
 elif n==0:
  print("EXITING.")
  printtable()
  break 
 printtable()