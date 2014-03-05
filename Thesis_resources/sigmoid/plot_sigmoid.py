import numpy as np
import pylab
from scipy.optimize import curve_fit
 
def sigmoid(t):
     y = 1 / (1 + np.exp(-t))
     return y
 
x = np.linspace(-8, 8, 100)
y = sigmoid(x)
 
#pylab.plot(xdata, ydata, 'o', label='data')
pylab.plot(x,y, label='sigmoid')
pylab.ylim(0, 1.05)
pylab.legend(loc='best')
pylab.show()
