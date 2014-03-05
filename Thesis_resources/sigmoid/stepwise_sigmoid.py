# -*- coding: UTF-8 -*-
import numpy as np
import pylab
import matplotlib.pyplot as plt

def sigmoid(x):
    y = 1 / (1+np.exp(-x))
    return y

def stepwise_sigmoid(x):
    t=int(x)
    if t==0:
        return 0.4621*x
    if t==1:
        return 0.2995*x+0.1626
    if t==2:
        return 0.1436*x+0.4745
    if t==3:
        return 0.0589*x+0.7285
    if t==4:
        return 0.0226*x+0.8737
    if t==5:
        return 0.0084*x+0.9444
    if t==6:
        return 0.0031*x+0.9763
    if t==7:
        return 0.0012*x+0.9901
    if t==-1:
        return 0.2995*x-0.1626
    if t==-2:
        return 0.1436*x-0.4745
    if t==-3:
        return 0.0589*x-0.7285
    if t==-4:
        return 0.0226*x-0.8737
    if t==-5:
        return 0.0084*x-0.9444
    if t==-6:
        return 0.0031*x-0.9763
    if t==-7:
        return 0.0012*x-0.9901
    if t>=8:
        return 1
    else:
        return -1

x=np.linspace(-9,9,200)
y=[]
z=[]
for xx in x:
    y.append(0.5*stepwise_sigmoid(xx)+0.5)
    z.append(sigmoid(xx))

fig=plt.figure()
ax=fig.add_subplot(1,2,1)
ax.set_title("stepwise sigmoid")
ax.plot(x,y,label='stepwise_sigmoid')
ay=fig.add_subplot(1,2,2)
ay.set_title("comparison")
ay.plot(x,y,label='sigmoid')
#ay.plot(x,y,label='stepwise sigmoid')
fig.show()
##pylab.plot(x,y,label='stepwise_sigmoid')
##pylab.plot(x,z,label='sigmoid')
##pylab.ylim(-0.05, 1.05)
##pylab.legend(loc='best')
##pylab.show()
