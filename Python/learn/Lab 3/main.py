import sys

### ZADANIE 1 ###
if (len(sys.argv) <= 1):
	print('Proszę uruchomić program z parametrami')
	sys.exit(-1)
listParameters = ''.join(sys.argv[1:])
print('Zadanie 1', str, sep='\n')

### ZADANIE 2 ###
listLower = [i for i in listParameters if i.islower()]
listUpper = [i for i in listParameters if i.isupper()]
listDigit = [i for i in listParameters if i.isdigit()]
listNotAlpha = [i for i in listParameters if not i.isalpha()]
print('Zadanie 2', listLower, listUpper, listDigit, listNotAlpha, sep='\n')

### ZADANIE 3 ###
listLowerNoRepeat = []
for i in listLower:
	if i not in listLowerNoRepeat:
		listLowerNoRepeat.append(i)
listLowerCount = [(i, listLower.count(i)) for i in listLowerNoRepeat]
print('Zadanie 3', listLowerNoRepeat, listLowerCount, sep='\n')

### ZADANIE 4 ###
listLowerCount.sort(key = lambda x: x[1], reverse = True)
print('Zadanie 4', listLowerCount, sep='\n')

### ZADANIE 5 ###
a = len([i for i in listParameters.casefold() if i in 'aeiouyąę'])
b = len(listLower) + len(listUpper) - a
listLinear = [(int(i), a*int(i)+b) for i in listDigit]
print('Zadanie 5', a, b, listLinear, sep='\n')

### ZADANIE 6 ###
if len(listDigit) > 1:
	avgX = sum(i for i,_ in listLinear) / len(listLinear)
	avgY = sum(i for _,i in listLinear) / len(listLinear)
	D = sum((i - avgX) ** 2 for i,_ in listLinear)
	a = sum(j * (i - avgX) for i,j in listLinear) / D
	b = avgY - a * avgX
	print('Zadanie 6', f'{avgX=}', f'{avgY=}', f'{D=}', f'{a=}', f'{b=}', sep='\n')