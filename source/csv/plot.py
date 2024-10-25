from matplotlib import *
import matplotlib.pyplot as plt
import numpy as np
import csv
 
def read_csv_file(file_path):
    with open(file_path, 'r') as file:
        data = [row for row in csv.reader(file)]
    return data

FILE="bubble5_results"
data=read_csv_file(FILE+".csv");
data=np.array(data)
title=data[0,:]
data=data[1:,:];
O=data[:,0];
s=data[:,1];
k=data[:,2];
time=np.array(list(map(eval,s)));
mem=np.array(list(map(eval,k)));
tick=list(O);

index=np.array([0,1,2,3])

fig=plt.figure();
plt.bar(index, time, width=0.2, color='r', label='time/s')  
plt.bar(index+0.2, mem/1000, width=0.2, color ='b', label='memory/10^3KB') 
plt.xticks(index, tick)                               
plt.ylim(0,20)                                              
plt.title('Bubble Sort 10^5 Scale Time&Memory')                            
plt.legend()                                        
plt.show();

fig.savefig(FILE+'.svg',format='svg',dpi=150);





