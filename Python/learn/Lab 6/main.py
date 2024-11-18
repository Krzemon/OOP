import time
import sys
import random
import math

print("### ZADANIE 1 ###")

powt = 1000
N = 10000

def forStatement():
	result = []
	for i in range(N):
		result.append(i)
		#result.append(i**2)
	return result

def listComprehension():
	return [i for i in range(N)]
	#return [i**2 for i in range(N)]

def mapFunction():
	return map(lambda x: x, range(N))
	#return map(lambda x: x**2, range(N))
	#return list(map(lambda x: x, range(N)))

def generatorExpression():
	return (i for i in range(N))
	#return (i**2 for i in range(N))
	#return list((i for i in range(N)))

def tester(f):
	dt = time.time_ns()
	for _ in range(powt):
		f()
		#sum = 0
		#for i in f():
		#	sum += i
		#sum(f())
	return time.time_ns() - dt
	
print(sys.version)
test = (forStatement, listComprehension, mapFunction, generatorExpression)
for testFunction in test:
    print(testFunction.__name__.ljust(20), '=>', tester(testFunction))

'''
a) dodawanie elementu
3.8.9 (default, Apr  3 2021, 01:00:00) 
[GCC 7.5.0]
forStatement         => 2584501949
listComprehension    => 1386260485
mapFunction          => 2362906
generatorExpression  => 1580027

b) dodawanie elementu podniesionego do kwadratu
3.8.9 (default, Apr  3 2021, 01:00:00) 
[GCC 7.5.0]
forStatement         => 8388306590
listComprehension    => 6313731604
mapFunction          => 926815
generatorExpression  => 1375163

c) sumowanie elementów z wykorzystaniem pętli for
3.8.9 (default, Apr  3 2021, 01:00:00) 
[GCC 7.5.0]
forStatement         => 4094763081
listComprehension    => 2435193247
mapFunction          => 5564483347
generatorExpression  => 4028110125

d) sumowanie z wykorzystaniem funkcji sum
3.8.9 (default, Apr  3 2021, 01:00:00) 
[GCC 7.5.0]
forStatement         => 2718525939
listComprehension    => 1302381731
mapFunction          => 2778605145
generatorExpression  => 1221344852

e) konwersja obiektu map i generatora do listy
3.8.9 (default, Apr  3 2021, 01:00:00) 
[GCC 7.5.0]
forStatement         => 2915555760
listComprehension    => 1296028515
mapFunction          => 2778009595
generatorExpression  => 1701965440
'''

print("\n### ZADANIE 2 ###")
a = [random.randrange(0,20) for _ in range(100)]
b = [random.randrange(0,20) for _ in range(100)]
print(list(filter(lambda x: x[0]+x[1] > 3 and x[0]+x[1] < 15, zip(a, b))))

print("\n### ZADANIE 3 ###")
def fitting(x,y):
	n = len(x)
	avg_x = sum(x) / n
	avg_y = sum(y) / n
	D = sum(map(lambda i: (i - avg_x) ** 2, x))
	a = sum(map(lambda i,j: j*(i - avg_x), x, y)) / D
	b = avg_y - a * avg_x
	err_y = math.sqrt(sum(map(lambda i,j: (j - a * i - b) ** 2, x, y)) / (n - 2))
	err_a = err_y / math.sqrt(D)
	err_b = err_y * math.sqrt( 1 / n + avg_x ** 2 / D )
	return a, b, err_a, err_b

print(fitting([0,1,2,3],[3,5,7,9]))
print(fitting([0,1,2,3],[3,5,7,9.5]))

print("\n### ZADANIE 4 ###")
def myreduce(f,s):
	result = s[0]
	for i in range(1,len(s)):
		result = f(result, s[i])
	return result

print(myreduce(lambda x,y: x+y, [1,2,3,4,5]))
print(myreduce(lambda x,y: x*y, [1,2,3,4,5]))

print("\n### ZADANIE 5 ###")
l = [[1,2], [3,4], [5,6], [7,8], [9,10]]
print([list(map(lambda x: x[0], l)), list(map(lambda x: x[1], l))])
