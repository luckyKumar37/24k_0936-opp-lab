#include "LabCourse.h"
#include "lectureCourse.h"

int main()
{
    Course* Course1 = new LectureCourse("CS101", 3);
    Course* Course2 = new LabCourse("CS102", 4);

    Course1->display();
    Course1->calculateGrade();
    Course2->display();
    Course2->calculateGrade();

    
    delete Course1;
    delete Course2; 
}