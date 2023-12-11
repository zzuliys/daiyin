#include "Company.h"
#include "Staff.h"
#include "Company2.h"
#include<iostream>

int main(){
    Company company;
    company.addStaff("xiaolu",19,"001");
    company.addStaff("xiaozhen",19,"002");
    company.addStaff("xiaoqi",19,"003");

    company.first();
    while(!company.isEnd()){
        Staff s = company.next();
        std::cout << s.name << std::endl;
    }

    Company2 company2;
    company2.addStaff("xiaolu",19,"001");
    company2.addStaff("xiaozhen",19,"002");
    company2.addStaff("xiaoqi",19,"003");

    Staff* p = company2.head->next;
    while(p!=nullptr){
        std::cout << p->name << std::endl;
        p = p->next;
    }

    return 0;
}