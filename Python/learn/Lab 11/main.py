import copy
from math import sqrt

print('### ZADANIE 1 ###')
class GameOfLife:
	def __init__(self, grid_size, square_size, iterations):
		self.grid = []
		self.grid_size = grid_size
		self.iterations = iterations
		for i in range(grid_size):
			self.grid.append([])
			for _ in range(grid_size):
				self.grid[i].append(" ")
		for i in range((grid_size - square_size) // 2, (grid_size - square_size) // 2 + square_size):
			for j in range((grid_size - square_size) // 2, (grid_size - square_size) // 2 + square_size):
				self.grid[i][j] = '*'
	
	def print(self):
		for i in self.grid:
			for j in i:
				print(j, sep='', end = '')
			print()
	
	def neighbor_count(self, k, l):
		neighbors = 0
		for i in range(k - 1, k + 2):
			for j in range(l - 1, l + 2):
				if i == k and j == l:
					continue
				if self.grid[i % self.grid_size][j % self.grid_size] == '*':
					neighbors += 1
		return neighbors

	def evolve(self):
		for _ in range(self.iterations):
			new_grid = copy.deepcopy(self.grid)
			for i in range(self.grid_size):
				for j in range(self.grid_size):
					if self.grid[i][j] == ' ':
						if self.neighbor_count(i,j) == 3:
							new_grid[i][j] = '*'
					elif self.grid[i][j] == '*':
						if self.neighbor_count(i,j) > 3 or self.neighbor_count(i,j) < 2:
							new_grid[i][j] = ' '
			self.grid = copy.deepcopy(new_grid)

gol = GameOfLife(30,10,1)
gol.print()
gol.evolve()
gol.print()
gol = GameOfLife(30,11,1)
gol.print()
gol.evolve()
gol.print()

print('### ZADANIE 2 ###')
class Tablica:
	def __init__(self, dims, *elems):
		self.size = len(elems) ** (1.0 / dims)
		if not self.size.is_integer():
			raise ValueError
		self.size = int(self.size)
		self.dims = dims
		self.table = []
		for _ in range(self.size):
			self.table.append([])
		
		ind = 0
		for i in range(self.size):
			for j in range(self.size):
				self.table[i].append(elems[ind])
				ind += 1

	def __add__(self, value):
		for i in range(self.size):
			for j in range(self.size):
				self.table[i][j] += value
		return self
	
	__iadd__ = __add__
	
	def __getitem__(self, key):
		if key < 0 or key > self.size * self.size - 1:
			raise IndexError
		return self.table[key // self.size][key % self.size]
	
	def __setitem__(self, key, value):
		self.table[key // self.size][key % self.size] = value

	def __len__(self):
		return self.size * self.size
	
	def __str__(self):
		result = ''
		for i in self.table:
			for j in i:
				result = result + str(j) + ' '
			result += '\n'
		return result

t = Tablica(2, 1, 2, 3, 4)
print(len(t))
print(t.dims)
print(t)
t = t + 2
print(t)
t += 2
print(t)
print(t[0])
print(t[1])
print(t[2])
print(t[3])
print()
t[3] = 25.0
for elem in t:
	print(elem)