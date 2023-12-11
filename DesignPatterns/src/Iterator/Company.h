#pragma once

#include "Staff.h"
#include "Iterator.h"
#include <vector>

class Company: public Iterator{
public:
    int addStaff(const std::string& name, int age, const std::string& idcard);

    virtual Staff first() override;
    virtual Staff next() override;
    virtual bool isEnd() override;

    std::vector<Staff> staffVec;
    int pos = 0;
};