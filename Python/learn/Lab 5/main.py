import sys
import string
import random

def zad1(s):
	constants = string.ascii_letters.replace('x', '')
	random_values = ''.join([str(random.randrange(10)) for _ in range(len(constants))])
	tr = str.maketrans(constants, random_values)
	return [(x := random.random(), eval(s.translate(tr))) for _ in range(10)]

print(zad1(sys.argv[1]))

def zad2(*p):
	list = []
	for i in p[0]:
		for obj in p:
			if i not in obj:
				break
		else:
			list.append(i)
	return list

print(zad2([1,2,3], (1,3,5), [3,2,1]))

def zad3(a, b, c = True):
	return [(a[i] if i < len(a) else None, b[i] if i < len(b) else None) for i in range(min(len(a),len(b)) if c else max(len(a),len(b)))]

test_a = [1, 2, 3, 5]
test_b = 'abc5xy'
print(zad3(test_a, test_b))
print(zad3(test_a, test_b, False))

def zad4(amount, coins = (10,5,2)):
	change = []
	while amount > 0:
		for i in coins:
			if i < amount:
				amount -= i
				change.append(i)
				break
		else:
			break
	return change

print(zad4(50))

def zad5(n, a, b, t = 'r'):
	searchRange = [i for i in range(a,b)]
	steps = 0
	while True:
		steps += 1
		guess = random.choice(searchRange) if t == 'r' else searchRange[len(searchRange) // 2]
		if guess == n:
			break
		else:
			if t == 'r':
				searchRange = searchRange[:guess] if n < guess else searchRange[guess:]
			else:
				searchRange.remove(guess)
	return steps

#print(zad5(25,0,100))
#print(zad5(25,0,100,'b'))