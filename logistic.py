# Importing the necessary matplotlib and scipy modules
import matplotlib.pyplot as plt
from scipy import stats
# Creating the data set that will be used for Regression
#different data sets are used of 3 hours’ time interval of sample size 10
x = [0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 
160, 170, 180]
y = [67.74, 68.72, 68.04, 66.67, 66.47, 65.69, 65.1, 65.59, 64.91, 64.81, 
65.1, 64.32, 64.03, 63.54, 63.25,
 63.73, 63.15, 62.37, 61.97]
# Returning important parameters values of regression
slope, intercept, r, p, std_err = stats.linregress(x, y)
# Creating a function that uses the slope and intercept values to return a 
# new value.This new value represents where
# on y-axis the corresponding x value will be placed
def myfunc(x):
 return slope * x + intercept
# Use each value of the array x to give a new array containing the values for 
y-axis
mymodel = list(map(myfunc, x))
# Drawing the original scatter plot
plt.scatter(x, y)
# Draw the resultant line obtained through regression
plt.plot(x, mymodel)
# Displaying the slope and intercept of the line obtained
print(slope)
print(intercept)
# Displaying the scatter plot and the line of regression
plt.show()