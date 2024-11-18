k = [8, 0, 17, 1, 10, 13, 19, 13, 10, 3,]
print(k)

print('\n### ZADANIE 1 ###\n')
c = k[:]
r = 13

for i, v in enumerate(c):
	if r in c:
		c.remove(r)
print(c)

print('\n### ZADANIE 2 ###\n')
c = k[:]
r = 13

while r in c:
	c.remove(r)
print(c)

print('\n### ZADANIE 3 ###\n')
c = k[:]

for i in range(len(c) // 2):
	print(c[i * 2 + 1], end = ' ')

print('\n### ZADANIE 4 ###\n')
c = k[:]

for i in c[1::2]:
	print(i, end = ' ')

print('\n### ZADANIE 5 ###\n')
c = k[:]

for i in range(len(c) // 2):
	print(c[-i * 2 - 1], end = ' ')

print('\n### ZADANIE 6 ###\n')
c = k[:]

for i in c[-1::-2]:
	print(i, end = ' ')

print('\n### ZADANIE 7 ###\n')
c = k[:]

c = [(i, c[i]) for i in range(len(c))]
print(c)

print('\n### ZADANIE 8 ###\n')

c.sort(key = lambda x: x[1])
print(c)

print('\n### ZADANIE 9 ###\n')
c = k[:]

c = [(i, c[i]) if not c[i] % 2 else [] for i in range(len(c))]
print(c)

print('\n### ZADANIE 10 ###\n')
c = k[:]

c = [(min(i, c[i]), max(i, c[i])) for i in range(len(c))]
print(c)