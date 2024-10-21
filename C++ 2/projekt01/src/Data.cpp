#include "Data.h"

Data::~Data()
{
}

IntData::IntData(int int_data) : _int_data(int_data)
{
}

IntData::~IntData()
{
    std::cout << __FUNCTION__ << "()" << std::endl;
}

void IntData::print(std::ostream &os) const
{
    os << _int_data;
}

void IntData::clone(Data **dest) const
{
    *dest = new IntData(_int_data);
}

StringData::StringData(std::string string_data) : _string_data(string_data)
{
}

StringData::~StringData()
{
    std::cout << __FUNCTION__ << "()" << std::endl;
}

void StringData::print(std::ostream &os) const
{
    os << _string_data;
}

void StringData::clone(Data **dest) const
{
    *dest = new StringData(_string_data);
}