# pragma once

#include <iostream>
using namespace std;

class Course
{
public:
    string Coursecode;
    int credits;


    virtual void calculateGrade() = 0; 
    virtual void display() = 0; 
};
