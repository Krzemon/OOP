import matplotlib.pyplot as plt

def get_d():
	dirs = [(1, 0), (0, 1), (-1, 0), (0, -1)]
	i = 0
	while True:
		i += yield
		yield dirs[i % 4]

def gen_f(n, filename = 'plot.png', recipe = 'F+F-F-F+F', cx = 0, cy = 0, dx = 1, dy = 0):
	'''
	Generates a fractal with a depth of n in file with the given name
	n needs to be a positive integer
	recipe is the fractal generating recipe
	[cx,cy] is the starting point
	[dx,dy] is the starting direction vector
	'''
	seq = 'F'
	for _ in range(n):
		seq = seq.replace('F', recipe)
	x, y = [cx], [cy]
	g = get_d()
	for c in seq:
		if c == 'F':
			cx += dx
			cy += dy
			x.append(cx)
			y.append(cy)
			#print(f'Appending [{cx},{cy}]')
			continue
		elif c == '+':
			next(g)
			dx, dy = g.send(1)
		elif c == '-':
			next(g)
			dx, dy = g.send(-1)
		#print(f'Direction [{dx},{dy}]')
	plt.plot(x,y)
	plt.savefig(filename)
	

roman_nums = [[1000, 'M'], [900, 'A'], [500, 'D'], [400, 'B'], [100, 'C'], [90, 'E'], [50, 'L'], [40, 'F'], [10, 'X'], [9, 'G'], [5, 'V'], [4, 'H'], [1, 'I'], ]

def a_to_r(a):
	'''
	Converts arabic numeral to its roman equivalent
	a needs to be a positive integer
	'''
	r = ''
	while a > 0:
		for n in roman_nums:
			if a >= n[0]:
				r += n[1]
				a -= n[0]
				break
	r = r.replace('A','CM')
	r = r.replace('B','CD')
	r = r.replace('E','XC')
	r = r.replace('F','XL')
	r = r.replace('G','IX')
	r = r.replace('H','IV')
	return r

def r_to_a(r):
	'''
	Converts roman numeral to its arabic equivalent
	r needs to be a string containing a roman numeral
	'''
	r = r.replace('CM','A')
	r = r.replace('CD','B')
	r = r.replace('XC','E')
	r = r.replace('XL','F')
	r = r.replace('IX','G')
	r = r.replace('IV','H')
	a = 0
	for l in r:
		for n in roman_nums:
			if l == n[1]:
				a += n[0]
				break
	return a

if __name__ == '__main__':
	pass