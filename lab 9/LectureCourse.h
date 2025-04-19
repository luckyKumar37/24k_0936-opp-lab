# pragma once
#include "Course.h"
class LectureCourse : public Course
{
public:
    LectureCourse(string Coursecode, int credits);
    void calculateGrade();

    void display();

};
