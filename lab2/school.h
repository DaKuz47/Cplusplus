#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "quadEq.h"


class Student {
public:
	Student() {}
	Student(string n);
	string get_name();
	virtual vector<double> solve_quad_eq(vector<double> task);
protected:
	string name;
};

class schoolClass {
public:
	schoolClass(string str);
	void add_student(Student* st);
	vector<Student*> get_students();
private:
	string id;
	vector<Student*> students;
};

class Teacher {
public:
	void add_task(vector<double> t);
	vector<vector<double>> get_task();
	void check_whole_class(schoolClass* cl);
	void check_student_work(Student* st);

private:
	vector<vector<double>> tasks;

};

class GoodStudent : public Student {
public:
	GoodStudent(string n);
	vector<double> solve_quad_eq(vector<double> task);
};

class NormalStudent : public Student {
public:
	NormalStudent(string n);

	vector<double> solve_quad_eq(vector<double> task);
private:
	double solveprob = 51;
};

class BadStudent : public Student {
public:
	BadStudent(string n);

	vector<double> solve_quad_eq(vector<double> task);

};