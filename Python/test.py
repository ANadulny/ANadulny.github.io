print("welcome")  # ctrl+b for building 

'''
/*
another comments
*/
'''

print( 10.0 + 5 )
print(2**5)
print(2/4)
print(23//5)
print(25%4)

string1 = "I am string in Python!"
print(string1[5:11])
print(string1[15:])

print("Today I had {0} cups of {1}".format(3,"coffee"))
print('prices: ({x}, {y}, {z})'.format(x = 2.0, y = 1.5, z = 5))
print("The {vehicle} had {0} crashes in {1} months".format(5,6, vehicle = 'car'))
print('{:<20}'.format("text"))
print('{:>20}'.format("text"))
print('{:b}'.format(21)) # binary format
print('{:x}'.format(21)) # hexa format
print('{:o}'.format(21)) # octan format

print(r'c:\number\nan')
print(""" 
	Hello:
		 I am Adrian
		 What is your name?""")


passerby_speech = 'Hello'
me = "Hi" if passerby_speech == "Hello" or passerby_speech == "Hi" else "Hey"
print(me)

#range(start, stop, step)
for i in range(1,10):
	print(i)

for i in range(0,13,3):
	print(i)

for i in range(3):
	for j in range(2):
		print(i , " ", j )

for i in range(1,11):
	print('{:<3}|'.format(i), end="")

	for j in range(1,11):
		print('{:>4}'.format(i * j), end="")

	if i == 1:
		print('\n{:#^44}'.format(""),end="")
	print("")


condition = 10

print("")
while condition != 0:
	print(condition)
	condition = condition - 1

print("")
for i in range(1, 11):
	if i == 5:
		continue
	print(i)

def function():
	print("This is our first function!")

function()

def returning():
	return "I am a result!"

result = returning()

print(result)

def multival():
	return "this is a result", 2
print(multival())

def parameters(a):
	print(a)

parameters("This is a parameter")

def add(a,b):
	c = a + b
	return c

result = add(12,5)
print(result)

def default_param(a,b = 4, c =5):
	return a + b + c

result = default_param(3)
print(result)

result = default_param(3, 5, 6)
print(result)

def scope(a):
	a = a + 1
	print(a)
	return a
scope(5)

def outer(a):

	def nested(b):
		return b * a

	a = nested(a)
	return a

print(outer(4))

def f(a):
	def g(b):
		def h(c):
			return a * b * c
		return h
	return g

print(f(5)(2)(3))

def factorial(n):
	if n == 1: 
		return 1
	else:
		return n * factorial(n - 1)

print(factorial(5))

def sum(n):
	if n == 1:
		return 1
	else:
		return n + sum( n - 1 )
def tail_sum(n, accumulator = 0):
	if n == 0:
		accumulator
	else:
		return tail_sum( n - 1, accumulator + n)
print(sum(10))
print(tail_sum(10))


f = lambda x, y: x + y
print(f(2,3))

f = lambda a: lambda b: lambda c: a * b * c
print(f(5)(3)(2))

f = lambda c: lambda a, b: lambda d: (c * ( a + b )) % d
print(f(2)(4,3)(11)) 

####### Exception Handling ##########
try:
	a = 5/0
except Exception as e:
	print(e)
'''
try:
	n = int(input("Enter an Integer: "))
except ValueError:
	print("That is not an integer")
'''
'''
try:
	sum = 0
	file = open('numbers.txt', 'r')
	for number in file:
		sum = sum + 1.0/int(number)
	print(sum)
except ZeroDivisionError: 
	print("Number in file equal to zero!")
except IOError:
	print("File DNE")
finally:
	print(sum)
	file.close()
'''

a = 'a'
# a = 1
def RaiseException(a):
	if type(a) != type('a'):
		raise ValueError("This is not string!")
try:
	RaiseException(a)
except ValueError as e:
	print(e)

def TestCase(a, b):
	assert a < b, "a is greater than b"
try:
	TestCase(2,1)
except AssertionError as e:
	print(e)


#age = input("How old are you: ")
#print(age)

######### File Management ##############3
#open(filename, access, buffering)
file = open("C:\\Users\\DOM.DESKTOP-0EBC15L\\Desktop\\Python code\\file.txt", "r")
#print(file.read(5))
#print(file.tell())

#print(file.read(5))
#file.seek(6)
#print(file.tell())

#for line in file:
#	print(line)

print("File Name: " + file.name)
print("is closed: " + str(file.closed))
print("Model " + file.mode)

file.close()

file = open("write.txt", "w+")
file.write("Hello file. I am string!")
file.seek(0)
file.write("this")
file.seek(0)
print(file.read())
file.close()

###### Data Structures #############
tup = (1, 'abc', 2, 'cde')
tup1 = 3, 'efg', True
tup2 = 'A' # tup2 = ('A', )
print(tup)
print(tup[1])
print(tup[0:2])

try:
	tup[3] = 5
except Exception as e:
	print(e)

tup = tup[0:3] + (5, )
print(tup)
print(tup2 * 4)
print(5 in tup)
for x in ('a', 'b', 'c'):
	print(x)
def multiple_result():
	return(1,2,'a')
print(multiple_result())
print((1,2,3) == (1,2))

####### List functions ############3
list1 =[1, 'abc', (2,3)]
print(list1[2][0])
print(list1 + ['4'])
print(list1 * 2)
print(2 in list1)
print(list1 == [1, 'abc', (2,3)])
print(list1[:2])
list1.append(6)
list1[len(list1):] = [7]
print(list1)

print(list(map(lambda x: x**2 + 3*x + 1, [1,2,3,4])))
print(list(filter(lambda x: x < 4, [1,2,3,4,5,4,3,2,1])))

import functools
print(functools.reduce(lambda x, y: x * y, [1,2,3,4]))


my_dictionary = {'Key': 'Value', ('K', 'E', 'Y'):5}
my_dictionary1 = {x: x + 1 for x in range(10) }

print(my_dictionary)
print(my_dictionary['Key'])
print(my_dictionary1)

try:
	print(my_dictionary[1])
except Exception as e:
	print(e)

print(my_dictionary.keys())
print(my_dictionary.values())

my_dictionary[1] = 3
print(my_dictionary)
del my_dictionary[1]
print(my_dictionary)

my_dictionary.clear()
print(my_dictionary)

my_dictionary = {'Iteam': 'Shirt', 'Size': 'Medium', 'Price': 50}
my_dictionary1 = my_dictionary

print(my_dictionary)
my_dictionary['Size'] = 'Small'
print(my_dictionary1)

my_set = set(['one', 'two', 'three', 'one'])
my_set1 = set(['two', 'three', 'four'])

print(my_set1 | my_set)
print(my_set1 ^ my_set)
print(my_set1 - my_set)

a = my_set1 - my_set1
print(a <= my_set1)

my_set.add('five')
print(my_set)

print(set.union(my_set, my_set1))
print(set.intersection(my_set, my_set1))
print(set.difference(my_set, my_set1))

#import prime #import other file
#prime.PrimesFunction(100)

#import prime as pr
#pr.PrimesFunction(100)

''' # It is the same
from prime import PrimesFunction
PrimesFunction(100)
'''
'''
import prime
print(dir(prime))

'''

#import main.sub2.prime as sub2
#sub2.PrimesFunction(100)

import copy
my_dictionary = {'Key': 'Values',('K', 'E', 'Y'):5}
my_dictionary1 = copy.deepcopy(my_dictionary)
my_dictionary[1] = 1
print(my_dictionary)
print(my_dictionary1)

import math as m
import cmath as cm
import random as ran
print(m.cos(m.pi))
print(m.exp(2))
print(m.ceil(1.6))
print(dir(cm))
print(cm.sqrt(9))
print(cm.polar(complex(0,1)))
print(dir(ran))
print(ran.sample([1,2,3,4,5],3))
print(ran.random()%10)
print(ran.randint(5,100))
import sys
print(sys.getrecursionlimit())
print(sys.version)
print(sys.path)

print("")
######## Object Oriented Programmming ##############
import math
class Complex:
	'this class simulates complex numbers'
	def __init__(self,real = 0,imag = 0):
		if(type(real) not in (int, float)) or type(imag) not in(int, float):
			raise Exception('Args are not numbers!')
		self.__real = real # __ it is mean that the value is private
		self.__imag = imag
		#self.SetReal(real)
		#self.SetImag(imag)
	def GetReal(self):
		return self.__real
	def GetImag(self):
		return self.__imag
	def GetModules(self):
		return math.sqrt(self.GetReal() * self.GetReal() + self.GetImag() * self.GetImag())
	def GetPhi(self):
		return math.atan2(self.GetImag(), self.GetReal())
	def SetReal(self, val):
		if type(val) not in (int, float):
			raise Exception('real part must be a number')
		self.__real = val
	def SetImag(self, val):
		if type(val) not in (int, float):
			raise Exception('imag part must be a number')
		self.__imag = val

	def __str__(self):
		return str(self.GetReal()) + '+' + str(self.GetImag()) + 'i';
	def __add__(self, other):
		return Complex(self.GetReal() + other.GetReal(), self.GetImag() + other.GetImag())
	def __mul__(self, other):
		if type(other) in (int, float):
			return Complex(self.GetReal() * other, self.GetImag() * other)
		else:
			return Complex(self.GetReal() * other.GetReal() - self.GetImag() * other.GetImag(),
				self.GetImag() * other.GetImag() + self.GetReal() * other.GetReal())
	def __truediv__(self, other):
		if type(other) in (int, float):
			return Complex(self.GetReal() / float(other), self.GetImag() / float(other))
		else:
			a, b, c, d = self.GetReal(), self.GetImag(), other.GetReal(), other.GetImag()
			nominator = c * c + d * d
			return Complex((a*c + b*d) / nominator, (b*c - a*d) / nominator) 

c = Complex(1,1)
#print(c.real, c.imag)
try:
	c = Complex(2)
	print(c.real, c.imag)
except Exception as e:
	print(e)

try:
	c = Complex((1,2,3),[1,2,3])
	print(c.real, c.imag)
except Exception as e:
	print(e)

c = Complex(2.5, 5.2)
print(c.GetReal(), c.GetImag())

c = Complex()
c.SetImag(1)
c.SetReal(2)
print(c.GetReal(), c.GetImag())

try:
	c.SetReal((1,2,3))
except Exception as e:
	print(e)

c = Complex(-3, 4)
print(c.GetModules(), c.GetPhi())

a = Complex(5, 0.3)
b = Complex(-3, 4)

print(a + b)
print(a * b)
print(a * 2)
print(a / b)
print(b / 2)

class Vehicle:
	def __init__(self, VIN, weight, manufacturer):
		self.vin_number = VIN
		self.weight = weight
		self.manufacturer = manufacturer
	def GetWeight(self):
		return self.weight
	def GetManufacturer(self):
		return self.manufacturer
	def VehicleType(self):
		pass

class Car(Vehicle):
	def __init__(self, VIN, weight, manufacturer, seats):
		self.vin_number = VIN
		self.weight = weight
		self.seats = seats
		self.manufacturer = manufacturer
	def NumberOfSeats(self):
		return self.seats
	def VehicleType(self):
		return 'CAR'

class Truck(Vehicle):
	def __init__(self, VIN, weight, manufacturer, capacity):
		self.vin_number = VIN
		self.weight = weight
		self.capacity = capacity
		self.manufacturer = manufacturer
	def TransportCapacity(self):
		return self.capacity
	def VehicleType(self):
		return 'TRUCK'

a = Car('ABC1', 1000, 'BMW', 4)
b = Truck('BCD2', 1000, 'MAN', 10000)
c = Car('DEF3', 1200, 'FORD', 4)
d = Truck('EFG4', 11000, 'MERCEDES', 15000)

print(a.GetWeight(), b.GetManufacturer(), c.NumberOfSeats(), d.TransportCapacity())
for v in [a,b,c,d]:
	print(v.GetManufacturer(), v.VehicleType())

##############
class Complex(object): # class object is a basic class 
	'this class simulates complex numbers'
	def __init__(self,real = 0,imag = 0):
		self._real = real # __ it is mean that the value is private
		self._imag = imag
	def GetReal(self):
		return self._real
	def GetImag(self):
		return self._imag
	def SetReal(self, val):
		if type(val) not in (int, float):
			raise Exception('real part must be a number')
		self._real = val
	def SetImag(self, val):
		if type(val) not in (int, float):
			raise Exception('imag part must be a number')
		self._imag = val
	real = property(GetReal, SetReal)
	imag = property(GetImag, SetImag)
######################33
class Student(object):
	"""STUDENT"""
	number_of_student = 0

	def __init__(self, name, index):
		self.name = name
		self.index = index
		Student.number_of_student += 1
	def __del__(self):
		Student.number_of_student -= 1

s1 = Student('Python Pythoniski', 12345)
s2 = Student('Guido van Rossum', 34567)
print(Student.number_of_student, s1.number_of_student,s2.number_of_student)
del s1
print(Student.number_of_student)

###### Visualization in Python ############
'''
import matplotlib.pyplot as plt

fig = plt.figure("Histogram")
ax = fig.add_subplot(1,1,1)
#ax.hist([21,12,23,35,45,60,33,22,56,34,28,40,41], bins = 7, facecolor = 'r', normed = True)
ax.hist([21,12,23,35,45,60,33,22,56,34,28,40,41], bins = 7, facecolor = 'g', normed = False)
plt.title("Distribution")
plt.xlabel("Range")
plt.ylabel("Amount")
plt.show()

fig2 = plt.figure('Box-plot')
ax1 = fig2.add_subplot(1,1,1)
ax1.boxplot([21,12,18,23,35,45,60,33,22,56,34,28,40,41])
plt.show()

fig3 = plt.figure('Bar')
ax2 = fig3.add_subplot(1,1,1)
ax2.set_xlabel('X')
ax2.set_ylabel('Y')
ax2.set_title("Bars")
ax2.bar([0,1,2,3], [5,10,15,5], [0.5,1,1.3,1], color = ['b', 'r'])
plt.show()

fig4 = plt.figure('Line')
ax3 = fig4.add_subplot(1,1,1)
ax3.set_xlim([-2,10])
ax3.set_ylim([0,6])
ax3.set_xlabel('X')
ax3.set_ylabel('Y')
ax3.set_title("Lines")
ax3.plot([-1,2,4,7,8], [5,2,3,4,3], 'r')
plt.show()


data = {'Player': ['Wade', 'James', 'Kobe', 'Curry '],
		'First': [10,10,8,12],
		'Second': [12,8,13,8],
		'Third': [15, 12,8,8],
		'Fourth': [18,20,15,8]}
fig5 = plt.figure('Stacked bar')
ax4 = fig5.add_subplot(1,1,1)
bar_width = 0.5
bars = [i+1 for i in range(len(data['First']))]
ticks = [i + (bar_width / 2) for i in bars]
ax4.bar(bars,
		data['First'],
		width = bar_width,
		label = 'First Quarter',
		color = '#AA5439')
ax4.bar(bars,
		data['Second'],
		width = bar_width,
		bottom = data['First'],
		label ='Second Quarter',
		color = '#FFD600')
ax4.bar(bars,
		data['Third'],
		width = bar_width,
		bottom = [i+j for i, j in zip(data['First'], data['Second'])],
		label = 'Third Quarter',
		color = '#FF9200')
ax4.bar(bars,
		data['Fourth'],
		width = bar_width,
		bottom = [i+j+k for i,j,k in zip(data['First'], data['Second'], data['Third'])],
		label = 'Fourth Quarter',
		color = 'r')
plt.xticks(ticks, data['Player'])
ax4.set_xlabel('Total')
ax4.set_ylabel('Player')
plt.legend(loc = 'upper right')
plt.xlim([min(ticks) - bar_width, max(ticks)+bar_width])
plt.show()


fig6 = plt.figure('Scatter')
ax5 = fig6.add_subplot(1,1,1)
ax5.scatter([-1,0,2,3,5], [2,1,3,0.5,4], [120,200,300,150,30],['r', 'g', '#BCDFF0', '#BB5500'])
plt.show()

fig8 = plt.figure('Pie')
sizes = [50,50,44,36]
labels = ['Wade', 'James', 'Kobel', 'Curry']
explode = (0.1,0,0,0)
color = ['red', 'purple', 'yellow', 'blue']
plt.pie(sizes, explode = explode, labels = labels, colors = color, autopct = '%1.1f%%', shadow = True, startangle = 140)
plt.axis('equal')
plt.show()
'''
import pandas as pd
df = pd.read_csv('AirPassengers.csv')
print(df['AirPassengers'])
print(df['time'][135])

names = ['Wade', 'James', 'Kobe', 'Curry']
total = [55,50,44,36]
data_set = list(zip(names, total))
data_frame = pd.DataFrame(data = data_set, columns = ['Names', 'Total'])
data_frame.to_csv('points.csv', index = True, header = True)


####### Numpy Library ##################

import numpy as np
a1 = np.array([2,1,3,4])
a2 = np.array([[1,2,1],[2,1,2],[1,2,3]])
a3 = np.array([[[1,1,1],[1,1,1]],[[2,2,2],[2,2,2]],[[3,3,3],[3,3,3]]])
print(a1)
print(a2)
print(a3)
