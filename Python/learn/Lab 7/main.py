import random
import math

print('### ZADANIE 1 ###')
def pascal():
	row = [1]
	while True:
		yield (row, sum(row))
		row = [row[i - 1] + row[i] if i < len(row) and i > 0 else 1 for i in range(len(row) + 1)]

g = pascal()
for i in range(10):
	print(next(g))

print('\n### ZADANIE 2 ###')
def gen(seq):
	zeroes = 0
	for i in seq:
		if i == 1:
			yield zeroes
			zeroes = 0
		else:
			zeroes += 1


N = 50
bits = random.choices([0,1], k=N)
print(bits)

for i in gen(bits):
	print(i,end=' ')
print()

avg = sum(gen(bits)) / len(bits)
print(avg)

print('\n### ZADANIE 3 ###')
def fib():
	a, b = 0, 1
	while True:
		yield a
		a,b = b, a+b

def even(seq):
	for i in seq:
		if i%2 == 0:
			yield i

def odd(seq):
	for i in seq:
		if i%2 == 1:
			yield i

def limit(seq, limit):
	for i in seq:
		if i >= limit:
			return
		yield i

print(sum(limit(even(fib()), 100)))
print(sum(limit(odd(fib()), 100)))

print('\n### ZADANIE 4 ###')
def r_range(*params):
	if len(params) == 1 and params[0] > 0:
		start, end, step = 0, params[0], 1
	elif len(params) == 2 and params[1] - params[0] > 0:
		start, end, step = params[0], params[1], 1
	elif len(params) == 3 and (params[1] - params[0]) * params[2] > 0:
		start, end, step = params[0], params[1], params[2]
	else:
		return
	
	i = start
	while (i >= start and i < end) or (i > end and i <= start):
		yield i
		i += step


print(list(range(7)))
print(list(range(-7)))
print(list(range(2,7)))
print(list(range(7,2)))
print(list(range(2,7,2)))
print(list(range(2,7,-2)))
print(list(range(7,2,2)))
print(list(range(7,2,-2)))
print()
print(list(r_range(7)))
print(list(r_range(-7)))
print(list(r_range(2,7)))
print(list(r_range(7,2)))
print(list(r_range(2,7,2)))
print(list(r_range(2,7,-2)))
print(list(r_range(7,2,2)))
print(list(r_range(7,2,-2)))
print()
print(list(r_range(7.5)))
print(list(r_range(1.5,7.5)))
print(list(r_range(7.5,1.5,-0.5)))

print('\n### ZADANIE 5 ###')
def gen(a):
	u, x, x0, i = 0, 1, 1, 0
	while True:
		yield (x, u, math.log(x))
		i += 1
		u = u + a / x
		x = x0 + i * a

g = gen(0.05)
x = 0
while x < 1.5:
	x, y, l = next(g)
	print(x, y, l, sep='  \t')