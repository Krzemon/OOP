import random
import math
import scipy.misc

print('### ZADANIE 1 ###')
class ArithmeticSeries1:
	def __init__(self, start, constant, iterations):
		self.value = start
		self.constant = constant
		self.iterations = iterations
	
	def __iter__(self):
		return self
	
	def __next__(self):
		self.value += self.constant
		self.iterations -= 1
		if self.iterations < 0:
			raise StopIteration
		return self.value

class ArithmeticSeries2:
	def __init__(self, start, constant, iterations):
		self.value = start
		self.constant = constant
		self.iterations = iterations
	
	def __iter__(self):
		return ArithmeticSeries2(self.value, self.constant, self.iterations)
	
	def __next__(self):
		self.value += self.constant
		self.iterations -= 1
		if self.iterations < 0:
			raise StopIteration
		return self.value

series1 = ArithmeticSeries1(0,5,10)
for i in series1:
	for j in series1:
		print(f'({i},{j})', end = ' ')
	print()
print()

series2 = ArithmeticSeries2(0,5,10)
for i in series2:
	for j in series2:
		print(f'({i},{j})', end = ' ')
	print()

print('\n### ZADANIE 2 ###')
class RandomGenerator:
	def __init__(self, m, a, c, x0):
		self.m = m
		self.a = a
		self.c = c
		self.x = x0
	
	def __iter__(self):
		return self
	
	def __next__(self):
		self.x = (self.a * self.x + self.c) % self.m
		return self.x / (self.m - 1) # normalizacja

gen = RandomGenerator(2 ** 48, 44485709377909, 0, 1)

# funkcja f(x) = sin(x)
# na przedziale od 0 do π
# oczekiwana wartość: 2
f = lambda x: math.sin(x)
xmin, xmax = 0, math.pi
ymin, ymax = -10, 10
expected_value = 2
eps = 10 ** -7

n, t = 0, 0
while True:
	n += 1
	x = next(gen) * (xmax - xmin) + xmin
	y = next(gen) * (ymax - ymin) + ymin
	if y > 0 and y <= f(x):
		t += 1
	if y < 0 and y >= f(x):
		t -= 1
	integral = (xmax - xmin) * (ymax - ymin) * t / n
	if abs(integral - expected_value) < eps:
		break
print(integral, n) 

print('\n### ZADANIE 3 ###')
class NewtonRaphson:
	def __init__(self, f, x, eps):
		self.f = f
		self.x = x
		self.eps = eps
	
	def __iter__(self):
		return self
	
	def __next__(self):
		self.x = self.x - self.f(self.x) / scipy.misc.derivative(self.f, self.x)
		if abs(self.f(self.x)) < self.eps:
			raise StopIteration
		return self.x

f = lambda x: math.sin(x) - (0.5 * x) ** 2
x = 1.5
eps = 10 ** -5

nr = NewtonRaphson(f, x, eps)
for i in nr:
	print(i)