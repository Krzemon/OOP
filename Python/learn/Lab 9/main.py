import lab9

print(lab9.a_to_r(1))
print(lab9.a_to_r(2))
print(lab9.a_to_r(4))
print(lab9.a_to_r(56))
print(lab9.a_to_r(919))
print(lab9.a_to_r(5366))

print(lab9.r_to_a('I'))
print(lab9.r_to_a('II'))
print(lab9.r_to_a('IV'))
print(lab9.r_to_a('LVI'))
print(lab9.r_to_a('CMXIX'))
print(lab9.r_to_a('MMMMMCCCLXVI'))

lab9.gen_f(1, 'plot1.png')
lab9.gen_f(3, 'plot3.png')
lab9.gen_f(5, 'plot5.png')

#help(lab9)
#help(lab9.gen_f)
#help(lab9.a_to_r)
#help(lab9.r_to_a)