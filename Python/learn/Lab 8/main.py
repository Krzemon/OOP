import string
import glob
import numpy
import matplotlib.pyplot as plt

print('###ZADANIE 1###')
def zad1(filename, n):
	with open(filename) as f:
		lines = f.readlines()
		print(lines[:n])
		print(lines[-n:])
		print(lines[::n])
		print([l.split()[n-1] for l in lines if len(l.split()) >= n])
		print([l[n-1] for l in lines if len(l) >= n])

zad1('data/data0.in', 5)

print('\n###ZADANIE 2###')
data = []
for file in glob.glob('data/data*in'):
	with open(file) as f:
		values = [float(l) for l in f.readlines()]
		data.append(values)
ind = list(range(min([len(x) for x in data])))
avg = list(map(numpy.average, zip(*data)))
std = list(map(numpy.std, zip(*data)))

with open('data.out', 'w') as out:
	for i in range(len(ind)):
		out.write(f'{ind[i]}\t{avg[i]}\t{std[i]}\n')

print('\n###ZADANIE 3###')
def generate_plot_script():
	with open('plot.py', 'w') as out:
		out.write('''import matplotlib.pyplot as plt
import numpy
import glob

x, y_avg, y_std = numpy.loadtxt('data.out', unpack=True)

for file in glob.glob('data/data*in'):
	y = numpy.loadtxt(file, unpack=True)
	plt.plot(x, y, 'o', ms = 4)

plt.errorbar(x, y_avg, marker='*', yerr=y_std)
plt.xlabel('x')

plt.savefig('res.pdf')''')

generate_plot_script()

print('\n###ZADANIE 4###')
data = {}
years = [2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010, 2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018, 2019, 2020]

for file in glob.glob('rank/*.txt'):
	with open(file) as f:
		lines = f.readlines()
		for l in lines:
			if len(l.split()) == 2:
				name, rank = l.split()
				year = int(file[5:-4])
				if name in data:
					data[name].extend([(year, int(rank))])
				else:
					data[name] = [(year, int(rank))]

print(data)

with open('rank.out', 'w') as out:
	out.write('Nazwisko')
	for y in years:
		out.write(' ' + str(y))
	out.write('\n')
	for name in data.keys(): # niedokończone
		out.write(f'{name}\t')
		for e in data[name]:
			for y in years:
				if e[0] == y:
					out.write(str(e[1]) + '\t')
			else:
				out.write('-\t')
		out.write('\n')

print('\n###ZADANIE 5###')
words = []
letters = {}

for file in glob.glob('zad5*in'):
	with open(file) as f:
		text = f.read()
		for word in text.split():
			words.append(word.upper())
words.sort()

for w in words:
	if (l := w[0]) in string.ascii_uppercase:
		if l in letters:
			letters[l] += 1
		else:
			letters[l] = 1

letters_sorted = [(x,y) for x,y in letters.items()]

letters_sorted.sort()
plt.bar(letters.keys(), letters.values())
plt.savefig('hist1.pdf')
plt.close()

letters_sorted.sort(key = lambda x: x[1], reverse = True)
plt.bar([x[0] for x in letters_sorted], [x[1] for x in letters_sorted])
plt.savefig('hist2.pdf')