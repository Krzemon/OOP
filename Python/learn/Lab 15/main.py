import sys
sys.path.append('build/lib.linux-x86_64-3.8')

import mod
import random
import time

print('### ZADANIE 1 ###')
print(mod.met(1,2))
print(mod.met(1,2,5))
print(mod.met(1,2,5,[2,3,4]))

print('### ZADANIE 2 ###')

def RandSqr(n):
	result = [0] * 10
	sizes = [0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0] #lista dla uniknięcia błędów numerycznych
	for i in range(10):
		for _ in range(n):
			x, y = random.random(), random.random()
			if x <= sizes[i] and y <= sizes[i]:
				result[i] += 1
		result[i] /= n
	return result

#iterations = [10**2, 10**3, 10**4, 10**5, 10**6]
iterations = [10**2, 10**3]
time_python = []
results_python = []
time_c = []
results_c = []

for n in iterations:
	t1 = time.time()
	results_python.append(RandSqr(n))
	t2 = time.time()
	time_python.append(t2 - t1)

	t1 = time.time()
	results_c.append(mod.randsqr(n))
	t2 = time.time()
	time_c.append(t2 - t1)

print(time_python)
print(time_c)
print()
print(results_python)
print(results_c)

print('### ZADANIE 3 ###')

d = {}

for _ in range(100):
	i = random.randint(10, 100)
	v = random.randint(10, 100)
	d[i] = v

d = {15: 50, 30: 60, 3 : 45}
#print(mod.euclid(d))