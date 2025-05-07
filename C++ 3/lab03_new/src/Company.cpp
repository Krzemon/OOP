#include "Company.h"


Company::Company(std::string name, int number): _name(name), _maxlen(number){}
Company::~Company(){
	delete[] this->_tab;
}
void Company::printDepartments(){
	std::cout<<"Company: "<<this->_name<<" departments:"<<std::endl;
	for( int i = 0; i < this->_len; i++){
		std::cout<<"- "<<this->_tab[i]._name<<std::endl;
	}
}
