# from matplotlib import pyplot as plt
# import numpy as np

import numpy as np
import matplotlib.pyplot as plt
 
list1=[]
with open("out12.txt", "r") as file1:
    data = file1.readlines()
    for line in data:
        #word = line.split()
        #print (word)
        line=float(line)
        list1.append(line)

list2=[]
with open("out22.txt", "r") as file2:
    data = file2.readlines()
    for line in data:
        #word = line.split()
        #print (word)
        line=float(line)
        list2.append(line)

list3=[]
with open("out32.txt", "r") as file3:
    data = file3.readlines()
    for line in data:
        #word = line.split()
        #print (word)
        line=float(line)
        list3.append(line)

print(list1)
print(list2)
print(list3)
# Creating dataset
# a = np.array([22, 87, 5, 43, 56,
#               73, 55, 54, 11,
#               20, 51, 5, 79, 31,
#               27])

#a = np.array(list1)



 
# Creating histogram
#fig, ax = plt.subplots(figsize =(10, 7))
# fig, ax = plt.subplots()
# #ax.hist(a, bins = [0, 25, 50, 75, 100])
# ax.hist(a)

# newx = ax.lines[0].get_ydata()
# newy = ax.lines[0].get_xdata()

# # set new x- and y- data for the line
# ax.lines[0].set_xdata(newx)
# ax.lines[0].set_ydata(newy)
 
# # Show plot
# plt.show()




# set width of bar
# barWidth = 0.25
# fig = plt.subplots(figsize =(12, 8))

# set height of bar
# a = [12, 30, 1, 8, 22]
# b = [28, 6, 16, 5, 10]
# c = [29, 3, 24, 25, 17]

# Set position of bar on X axis
# br1 = np.arange(len(list1))
# # br2 = np.arange(len(list2))
# # br3 = np.arange(len(list3))
# br2 = [x + barWidth for x in br1]
# br3 = [x + barWidth for x in br2]

# # Make the plot
# plt.bar(br1, list1, color ='r', width = barWidth,
# 		edgecolor ='grey', label ='a')
# plt.bar(br2, list2, color ='g', width = barWidth,
# 		edgecolor ='grey', label ='b')
# plt.bar(br3, list3, color ='b', width = barWidth,
# 		edgecolor ='grey', label ='c')

# # Adding Xticks
# plt.xlabel('Branch', fontweight ='bold', fontsize = 15)
# plt.ylabel('Students passed', fontweight ='bold', fontsize = 15)
# # plt.xticks([r + barWidth for r in range(len(list1))],
# # 		['2015', '2016', '2017', '2018', '2019'])

# plt.legend()
#plt.show()

N = 3
ind = np.arange(N) 
width = 0.25
  
xvals = list1
bar1 = plt.bar(ind, xvals, width, color = 'r')
  
yvals = list2
bar2 = plt.bar(ind+width, yvals, width, color='g')
  
zvals = list3
bar3 = plt.bar(ind+width*2, zvals, width, color = 'b')
  
plt.xlabel("Priority")
plt.ylabel('Time')
plt.title("Exec time")
  
plt.xticks(ind+width,['0 1 1', '2 3 3', '2 3 4'])
plt.legend( (bar1, bar2, bar3), ('SCHED_OTHER', 'SCHED_RR', 'SCHED_FIFO') )
plt.show()
