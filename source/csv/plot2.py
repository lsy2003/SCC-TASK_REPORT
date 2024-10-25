from matplotlib import *
import matplotlib.pyplot as plt
import numpy as np
import csv
 
def read_csv_file(file_path):
    with open(file_path, 'r') as file:
        data = [row for row in csv.reader(file)]
    return data

tim=[];    #
for FILE in [ "bubble5_results", "bin5_results" ,"fib5_results"]: #["bin6_results" ,"fib6_results"]:
	
	data=read_csv_file(FILE+".csv");
	data=np.array(data)
	title=data[0,:]
	data=data[1:,:];
	O=data[:,0];
	s=data[:,1];
	k=data[:,2];
	time=np.array(list(map(eval,s)));
	mem=np.array(list(map(eval,k)));
	tim.append(time);
	tick=list(O);


index=np.array([0,1,2,3])

fig=plt.figure();
plt.bar(index-0.2, tim[0], width=0.2, color='r', label='bubble')  
plt.bar(index, tim[1], width=0.2, color='b', label='binary heap')  
plt.bar(index+0.2, tim[2], width=0.2, color='g', label='fibonacci heap')  

plt.xticks(index, tick)                               
plt.ylim(0,20)                                              
plt.title('10^5 Scale Time(s)')                            
plt.legend()                                        
plt.show();

fig.savefig(FILE+'.svg',format='svg',dpi=1000);





