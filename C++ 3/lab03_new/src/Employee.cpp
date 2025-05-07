#include "Employee.h"


Employee::Employee(std::string name):_name(name){}
Employee::Employee(std::string name, Department* where):_name(name), _place(where){
	if (where->_len == where->_maxlen){
		std::cout<<"Error"<<std::endl;
	}
	else{
		Employee* wsk = new Employee[where->_len+1];
		for ( int i = 0; i < where->_len; i++)
			wsk[i] = where->_tab[i];
		wsk[where->_len] = *this;
		where->_len++;
		delete[] where->_tab;
		where->_tab = wsk;
	}
}


void Employee::printInfo() const{
	std::cout<<"Employee: "<<this->_name<<" (Department :"<<this->_place->_name<<")"<<std::endl;
}

