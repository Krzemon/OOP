import math
import random
import abc

print('### ZADANIE 1 ###')
class Calka(abc.ABC):
	def __init__(self, a, b, steps, f):
		if not isinstance(steps, int):
			raise TypeError('steps must be an integer')
		if not callable(f):
			raise TypeError('f must be a callable function')
		self.a = a
		self.b = b
		self.steps = steps
		self.f = f

	@abc.abstractmethod
	def calculate(self):
		'''Oblicza numerycznie wartość całki z funkcji (f) od (a) do (b) w (steps) krokach'''

class CalkaTrapez(Calka):
	def calculate(self):
		h = (self.b - self.a) / self.steps
		return (h / 2) * sum([self.f(self.a + i * h) + self.f(self.a + (i + 1) * h) for i in range(1, self.steps)])

class CalkaSimpson(Calka):
	def calculate(self):
		h = (self.b - self.a) / (2 * self.steps)
		sum1 = sum([self.f(self.a + i * h) for i in range(1, 2 * self.steps, 2)])
		sum2 = sum([self.f(self.a + i * h) for i in range(2, 2 * self.steps, 2)])
		return (h / 3) * (self.f(self.a) + 4 * sum1 + 2 * sum2 + self.f(self.a + 2 * self.steps * h))

# f(x) = ln(x^3 + 3x^2 + x + 0.1) * sin(18x)
# całka z f(x) od 0 do 1 ≈ -0.186486896
f = lambda x: math.log(x**3 + 3*x**2 + x + 0.1) * math.sin(18 * x)
a, b = 0, 1
steps = 1000
print(CalkaTrapez(a, b, steps, f).calculate())
print(CalkaSimpson(a, b, steps, f).calculate())
#print(CalkaSimpson(a, b, 5.5, f).calculate())
#print(CalkaSimpson(a, b, steps, 2).calculate())

print('\n### ZADANIE 2 ###')
class Stos:
	def __init__(self, *stack):
		self.s = []
		if stack and isinstance(stack[0], Stos):
			self.merge(stack[0])
	
	def push(self, elem):
		self.s.append(elem)
	
	def pop(self):
		return self.s.pop()
	
	def merge(self, stack):
		for i in stack.s:
			self.push(i)
	
	def __len__(self):
		return len(self.s)
	
	def __str__(self):
		result = ''
		for i in self.s:
			result += str(i) + ' '
		return result
	
	def __getitem__(self, key):
		return self.s[key]
	
	def __setitem__(self, key, value):
		self.s[key] = value

test1 = Stos()
print(test1)		#
test1.push(1)
test1.push(2)
test1.push(4)
print(test1.pop())	# 4
test1.push(3)
print(test1)		# 1 2 3
print(len(test1))	# 3
test2 = Stos(test1)
print(test2)		# 1 2 3
test2.merge(test1)
print(test2)		# 1 2 3 1 2 3

class StosRosnacy(Stos):
	def push(self, elem):
		if len(self) == 0 or elem > self[-1]:
			self.s.append(elem)

class StosMalejacy(Stos):
	def push(self, elem):
		if len(self) == 0 or elem < self[-1]:
			self.s.append(elem)


sumr, summ = 0, 0
for _ in range(100):
	testr = StosRosnacy()
	testm = StosMalejacy()
	for _ in range(100):
		testr.push(random.randint(0,100))
		testm.push(random.randint(0,100))
	sumr += len(testr)
	summ += len(testm)
print(sumr / 100)
print(summ / 100)

print('\n### ZADANIE 3 ###')
class Licznik:
	total_lines = 0
	total_words = 0
	total_chars = 0

	def __init__(self):
		pass
	
	def count(self, filename):
		filelines, filetext = '', ''
		with open(filename) as file:
			filelines = file.readlines()
		with open(filename) as file:
			filetext = file.read()
		lines = len(filelines)
		words = len(filetext.split())
		chars = len(filetext)
		Licznik.total_lines += lines
		Licznik.total_words += words
		Licznik.total_chars += chars
		return f'{lines}\t{words}\t{chars} {filename}'
	
	@staticmethod
	def total():
		return f'{Licznik.total_lines}\t{Licznik.total_words}\t{Licznik.total_chars} razem'

l = Licznik()
print(l.count('main.py'))
print(l.count('PrzykladDziedziczenie.py'))
print(l.total())