#pragma once

#include "Staff.h"
#include "Iterator.h"

class Company2 : public Iterator{
public:
    int addStaff(const std::string& name, int age, const std::string& idcard);

    virtual Staff first() override;
    virtual Staff next() override;
    virtual bool isEnd() override;

    Staff * head = new Staff("",0,"");
    Staff* p = nullptr;
};