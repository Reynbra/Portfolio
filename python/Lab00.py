#!/usr/bin/env python
# coding: utf-8

# In[1]:


import math
x = 1
lstA = ['roads', 'cities', 'counties', 'states']
 
lstB = []

for i in lstA:
    x = i + ".txt"
    lstB.append(x)
    
print(lstB)


# In[4]:


y = 0
pi = 0

while pi < 10000:
    print(y, "-" , pi)
    pi = math.pow(math.pi, y)
    y = y + 1


# In[14]:


tf = 'lab0.txt'
f = open(tf)

f.readlines(99)


# In[ ]:




