import random
import string

print('### ZADANIE 1 ###')
k = 10
ls = [i for i in range(5*k)]
s = {}

for i in range(100):
	stable_elements = 0
	new_ls = ls[:]
	random.shuffle(ls)
	for j in range(k):
		if new_ls[j] == ls[j]:
			stable_elements += 1
	if stable_elements in s:
		s[stable_elements] += 1
	else:
		s[stable_elements] = 1

print(s)

print('\n### ZADANIE 2 ###')
rand_letters = random.sample(string.ascii_lowercase, k)
rand_str = '.'.join(rand_letters)
print(rand_str)

print('\n### ZADANIE 3 ###')
rand_numbers = [random.randrange(0,20) for _ in range(10)]
print(rand_numbers)

print('## PODPUNKT A ##')
s = {}
for i,j in enumerate(rand_numbers):
	s.setdefault(j, []).append(i)
print(s)

print('## PODPUNKT B ##')
s = {}
for i in range(len(rand_numbers)):
	s.setdefault(rand_numbers[i], []).append(i)
print(s)

print('\n### ZADANIE 4 ###')
s = {}
for n in range(3,7):
	palindromes = 0
	rand_numbers = [random.randrange(10**(n-1), 10**n) for _ in range(1000)]
	for i in rand_numbers:
		number = str(i)
		if number == number[::-1]:
			palindromes += 1
	s[n] = palindromes
print(s)

print('\n### ZADANIE 5 ###')
s1 = {i: random.randrange(1, 100) for i in range(10)}
s2 = {i: random.randrange(1, 100) for i in range(10)}
print(s1)
print(s2)

s1 = {j: i for i,j in s1.items()}
s2 = {j: i for i,j in s2.items()}
print(s1)
print(s2)

s3 = {i: (s1[i], s2[i]) for i in s1 if i in s2}
print(s3)