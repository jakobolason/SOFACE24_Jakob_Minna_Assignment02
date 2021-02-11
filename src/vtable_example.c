#include "stdio.h"

struct Student;

typedef struct
{
    void (*Student)(struct Student *);
    char* (*get_favorite_drink)(struct Student *);
    int (*get_salary)(struct Student *);
} Student_functable;

typedef struct
{
    int salary;
    Student_functable* vmt;
} Student;


void Student_make_student(Student* self);
int Student_get_salary(Student* self);
char* Student_get_favorite_drink(Student* self);

Student_functable student_vmt = {Student_make_student, Student_get_favorite_drink, Student_get_salary};


void Student_make_student(Student* self)
{
    self->vmt = &student_vmt;
    self->salary = 5000; // SU
}

char* Student_get_favorite_drink(Student* self)
{
    return "coffee";
}

int Student_get_salary(Student* self)
{
    return self->salary;
}


struct Professor;

typedef struct 
{
    void (*Professor)(struct Professor *);
    char* (*get_favorite_drink)(struct Student *);
    int (*get_salary)(struct Student *);

} Professor_functable;

typedef struct
{   
    int bonus_multiplier;
    Student inherited;
} Professor;


void Professor_make_Professor(Professor* self, int bonus_multiplier);

int Professor_get_salary(Professor* self);

char* Professor_get_favorite_drink(Professor* self);

// Inherit get_favorite_drink method from student
Professor_functable professor_vmt = {Professor_make_Professor, Student_get_favorite_drink, Professor_get_salary };

void Professor_make_Professor(Professor* self, int bonus_multiplier)
{
    // instantiate "base class"
    Student_make_student(&self->inherited);

    // setup virtual method table
    self->inherited.vmt = &professor_vmt;

    // other stuff specific to derived class
    self->bonus_multiplier = bonus_multiplier;
}

char* Professor_get_favorite_drink(Professor* self)
{
    return "beer";
}

int Professor_get_salary(Professor* self)
{
    return self->inherited.salary * self->bonus_multiplier;
}

int main(int argc, char** argv)
{
    Student s;
    Professor p;

    Student_make_student(&s);
    Professor_make_Professor(&p,3);
    
    printf("A student likes to drink: %s and earns a salary of: %d\n",s.vmt->get_favorite_drink(&s), s.vmt->get_salary(&s));        
    printf("A professor likes to drink: %s and earns a salary of: %d\n",p.inherited.vmt->get_favorite_drink(&p), p.inherited.vmt->get_salary(&p));        
}