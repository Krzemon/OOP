#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string>

class Data
{
public:
    virtual ~Data();
    virtual void print(std::ostream &os = std::cout) const = 0;
    virtual void clone(Data **dest) const = 0;

private:
};

class IntData : public Data
{
public:
    IntData(int data);
    ~IntData();
    void print(std::ostream &os = std::cout) const override;
    void clone(Data **dest) const override;

private:
    int _int_data;
};

class StringData : public Data
{
public:
    StringData(std::string str);
    ~StringData();
    void print(std::ostream &os = std::cout) const override;
    void clone(Data **dest) const override;

private:
    std::string _string_data;
};

#endif