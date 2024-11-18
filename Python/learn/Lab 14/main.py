import math

print('### ZADANIE 1 ###')
class Point:
	def __init__(self):
		self.x = 0
		self.y = 0
	
	@property
	def x(self):
		return self._x
	
	@x.setter
	def x(self, v):
		self._x = v
	
	@x.getter
	def x(self):
		return self._x
	
	@property
	def y(self):
		return self._y
	
	@y.setter
	def y(self, v):
		self._y = v
	
	@y.getter
	def y(self):
		return self._y

p = Point()
p.x = 5
print(p.x, p.y)

print('\n### ZADANIE 2 ###')
def Area(a, b):
	def fz(pf):
		def fw(p1, p2):
			for i in (p1.x, p1.y, p2.x, p2.y):
				if i < a or i > b:
					raise ValueError
			else:
				return pf(p1, p2)
		return fw
	return fz

@Area(2,4)
def AddPoints(p1, p2):
	result = Point()
	result.x = p1.x + p2.x
	result.y = p1.y + p2.y
	return result

@Area(2,4)
def SubtractPoints(p1, p2):
	result = Point()
	result.x = p1.x - p2.x
	result.y = p1.y - p2.y
	return result

p1, p2, p3 = Point(), Point(), Point()
p1.x, p1.y = 4, 4
p2.x, p2.y = 2, 3
p3.x, p3.y = 1, 5

r1 = AddPoints(p1, p2)
r2 = SubtractPoints(p1, p2)
#r3 = AddPoints(p1, p3)

print(r1.x, r1.y)
print(r2.x, r2.y)

print('\n### ZADANIE 3 ###')
def dist(p1, p2):
	return math.sqrt((p1.x - p2.x) ** 2 + (p1.y - p2.y) ** 2)

class Formulas:
	@staticmethod
	def PerimeterTriangle(p1, p2, p3):
		return dist(p1, p2) + dist(p2, p3) + dist(p3, p1)
	
	@staticmethod
	def PerimeterQuadrangle(p1, p2, p3, p4):
		return dist(p1, p2) + dist(p2, p3) + dist(p3, p4) + dist(p4, p1)

	@staticmethod
	def Heron(p1, p2, p3):
		p = Formulas.PerimeterTriangle(p1, p2, p3) / 2
		return math.sqrt(p * (p - dist(p1, p2)) * (p - dist(p2, p3)) * (p - dist(p3, p1)))

	@staticmethod
	def Brahmagupta(p1, p2, p3, p4):
		p = Formulas.PerimeterQuadrangle(p1, p2, p3, p4) / 2
		return math.sqrt((p - dist(p1, p2)) * (p - dist(p2, p3)) * (p - dist(p3, p4)) * (p - dist(p4, p1)))

t1, t2, t3 = Point(), Point(), Point()
t1.x, t1.y = 0, 0
t2.x, t2.y = 1, 0
t3.x, t3.y = 1, 1
print(Formulas.PerimeterTriangle(t1, t2, t3))
print(Formulas.Heron(t1, t2, t3))

q1, q2, q3, q4 = Point(), Point(), Point(), Point()
q1.x, q1.y = 0, 0
q2.x, q2.y = 1, 0
q3.x, q3.y = 1, 1
q4.x, q4.y = 0, 1
print(Formulas.PerimeterQuadrangle(q1, q2, q3, q4))
print(Formulas.Brahmagupta(q1, q2, q3, q4))

print('\n### ZADANIE 4 ###')
class Counter:
	count = {}

	def __init__(self, pf):
		self._pf = pf
		Counter.count[self] = 0
	
	def __call__(self, *p):
		Counter.count[self] += 1
		return self._pf(*p)

	@staticmethod
	def get_count(func):
		return Counter.count[func]

@Counter
def Test():
	return 0

@Counter
def Test2(a, *b):
	return 0

Test()
print(Counter.get_count(Test))
Test()
print(Counter.get_count(Test))

Test2(1, [2, 3])
print(Counter.get_count(Test2))
Test2(1, [2, 3])
print(Counter.get_count(Test2))
t = Test2
t(1, [2, 3])
print(Counter.get_count(Test2))
print(Counter.get_count(t))