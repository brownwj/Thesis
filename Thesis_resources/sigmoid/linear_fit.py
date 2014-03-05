import numpy as np
from scipy import optimize

def sigmoid(x):
    y = 1 / (1+np.exp(-x))
    return y

def residuals(p):
    k,b = p
    return y-(k*x+b)


x=np.linspace(3.5,4.5,100)
y=sigmoid(x)
r=optimize.leastsq(residuals, [1,0])
k,b=r[0]
print k,b
