#include "Course.h"

class LabCourse : public Course
{
public:
    LabCourse(string Coursecode, int credits);
    void calculateGrade();
    void display();
};