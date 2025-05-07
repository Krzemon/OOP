#include "Department.h"


Department::Department(std::string name, int number, Company* where):_name(name), _maxlen(number){
	if (where->_len == where->_maxlen){
		std::cout<<"Error"<<std::endl;
	}
	else{
		Department* wsk = new Department[where->_len+1];
		for ( int i = 0; i < where->_len; i++)
			wsk[i] = where->_tab[i];
		wsk[where->_len] = *this;
		where->_len++;
		delete[] where->_tab;
		where->_tab = wsk;
	}
}


Department::~Department(){
	delete[] this->_tab;
}

Employee& Department::operator [](int number){
	return this->_tab[number];
}





