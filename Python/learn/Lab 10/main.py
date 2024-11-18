from datetime import date

print('### ZADANIE 1 ###')

def add_year(year):
	if year < 1900:
		return 80
	if year < 2000:
		return 0
	if year < 2100:
		return 20
	if year < 2200:
		return 40
	if year < 2300:
		return 60

def check(pesel, birth_date, gender):
	if int(pesel[0:2]) != birth_date.year % 100:
		raise ValueError(f'Year {birth_date.year} does not match pesel value of {pesel[0:2]}')
	if int(pesel[2:4]) != birth_date.month + add_year(birth_date.year):
		raise ValueError(f'Month {birth_date.month} does not match pesel value of {pesel[2:4]}')
	if int(pesel[4:6]) != birth_date.day:
		raise ValueError(f'Day {birth_date.day} does not match pesel value of {pesel[4:6]}')
	if int(pesel[6:10]) % 2 == 0 and gender != 'kobieta':
		raise ValueError(f'Gender {gender} does not match pesel value of {pesel[6:10]}')
	if int(pesel[6:10]) % 2 == 1 and gender != 'mężczyzna':
		raise ValueError(f'Gender {gender} does not match pesel value of {pesel[6:10]}')
	checksum = 0
	weights = [1, 3, 7, 9, 1, 3, 7, 9, 1, 3, 0]
	for i in range(len(pesel)):
		checksum += int(pesel[i]) * weights[i]
	checksum = (10 - checksum % 10) % 10
	if int(pesel[10]) != checksum:
		raise ValueError(f'Checksum {checksum} does not match pesel value of {pesel[10]}')

try:
	check('02270803624', date(2002,7,8), 'kobieta')
except ValueError as err:
	print(err)

try:
	check('02270803624', date(2003,7,8), 'kobieta')
except ValueError as err:
	print(err)

try:
	check('02270803624', date(2002,12,8), 'kobieta')
except ValueError as err:
	print(err)

try:
	check('02270803624', date(1902,12,8), 'kobieta')
except ValueError as err:
	print(err)

try:
	check('02270803624', date(2002,7,31), 'kobieta')
except ValueError as err:
	print(err)

try:
	check('02270803624', date(2002,7,31), 'mężczyzna')
except ValueError as err:
	print(err)

try:
	check('02270803625', date(2002,7,8), 'kobieta')
except ValueError as err:
	print(err)


print('\n### ZADANIE 2 ###')

def check_date(date):
	if date[1] == '2':
		if (int(date[2]) % 4 == 0 and int(date[2]) % 100 != 0 ) or int(date[2]) % 400 != 0:
			if int(date[0]) > 28:
				return False
	else:
		if int(date[0]) > 30:
			if date[0] == '31' and date[1] in ['1','3','5','7','8','10','12']:
				return True
			else:
				return False
	return True


def average_age(mode):
	with open('daty.in') as file:
		lines = file.readlines()
		dates = []
		for l in lines:
			if not check_date(l.split()) or len(l.split()) != 3:
				if mode == 'r':
					raise ValueError(f'Invalid date: {l}')
			else:
				dates.append(l.split())
		age = 0
		count = 0
		for l in dates:
			age += date.today().year - int(l[2])
			count += 1
		return age / count
try:
	print(average_age('r'))
except ValueError as err:
	print(err)

try:
	print(average_age('l'))
except ValueError as err:
	print(err)

print('\n### ZADANIE 3 ###')

def pythagorean(l):
	if len(l) < 3:
		raise ValueError(f'Container of length {len(l)} too short, required length at least 3')
	triples = []
	quadruples = []
	for i in range(len(l) - 2):
		if l[i] ** 2 + l[i+1] ** 2 == l[i+2] ** 2:
			triples.append([l[i], l[i+1], l[i+2]])
	for i in range(len(l) - 3):
		if l[i] ** 2 + l[i+1] ** 2 + l[i+2] ** 2 == l[i+3] ** 2:
			quadruples.append([l[i], l[i+1], l[i+2], l[i+3]])
	if len(triples) == 0 and len(quadruples) == 0:
		raise ValueError('No pythagorean triples/quadruples found')
	if len(triples) != 0:
		for nums in triples:
			even, odd = 0, 0
			for i in nums:
				even += 1 if i%2 == 0 else 0
				odd += 1 if i%2 == 1 else 0
			print(f'Triple: {nums} contains {even} even and {odd} odd numbers')
	if len(quadruples) != 0:
		for nums in quadruples:
			even, odd = 0, 0
			for i in nums:
				even += 1 if i%2 == 0 else 0
				odd += 1 if i%2 == 1 else 0
			print(f'Quadruple: {nums} contains {even} even and {odd} odd numbers')

try:
	pythagorean([1,2,2,3,2,3,6,7,1,4,8,9,4,4,7,9,2,6,9,13,6,6,7,11,3,4,12,13,2,5,14,15,2,10,11,15,1,12,12,17,8,9,12,17,1,6,18,19,6,6,17,19,6,10,15,21,4,5,20,21,4,8,19,21,4,13,16,21,8,11,16,21,3,6,22,23,3,13,18,23,6,13,18,23,9,14,20,25,12,15,16,25,2,7,26,27,2,10,25,27,2,14,23,27,7,14,22,27,10,10,23,27,3,16,24,29,11,12,24,29,12,16,21,29,2])
except ValueError as err:
	print(err)
print()

try:
	pythagorean([1,2,2,3,2,3,6,7,1,4,8,9,4,4,7,9,2,6,9,13,6,6,7,11,3,4,12,13,2,5,14,15,2,10,11,15,1,12,12,17,8,9,12,17,1,6,18,19,6,6,17,19,6,10,15,21,4,5,20,21,4,8,19,21,4,13,16,21,8,11,16,21,3,6,22,23,3,13,18,23,6,13,18,23,9,14,20,25,12,15,16,25,2,7,26,27,2,10,25,27,2,14,23,27,7,14,22,27,10,10,23,27,3,16,24,29,11,12,24,29,12,16,21,29])
except ValueError as err:
	print(err)
print()

try:
	pythagorean([3,4,5,5,12,13,7,24,25,9,40,41,6,8,10,60,80,100,18,24,30,15,8,17])
except ValueError as err:
	print(err)
print()

try:
	pythagorean([1,2,3,4,5,6,7,8,9])
except ValueError as err:
	print(err)
print()

try:
	pythagorean([1,2])
except ValueError as err:
	print(err)
print()

try:
	pythagorean([3,4,6])
except ValueError as err:
	print(err)