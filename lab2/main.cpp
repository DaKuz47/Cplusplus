#include <vector>
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

#include "Header.h"

class Student {
public:
	Student() {}
	Student(string n) {
		name = n;
	}
	string get_name() {
		return name;
	}
	virtual vector<double> solve_quad_eq(vector<double> task) {
		return task;
	};
protected:
	string name;
};


class schoolClass {
public:
	schoolClass(string str){
		id = str;
	}
	void add_student(Student* st) {
		students.push_back(st);
		return;
	}
	vector<Student*> get_students() {
		return students;
	}
private:
	string id;
	vector<Student*> students;
};

class Teacher {
public:
	void add_task(vector<double> t) {
		tasks.push_back(t);
		return;
	}
	
	vector<vector<double>> get_task() {
		return tasks;
	}

	void check_whole_class(schoolClass* cl) {
		for (auto x : cl->get_students()) {
			check_student_work(x);
		}
	}

	void check_student_work(Student* st) {
		int count = 0;
		for (auto t : tasks) {
			vector<double> sol = st->solve_quad_eq(t);
			if (sol == quad_eq_roots(t)) {
				count++;
			}
		}
		cout << st->get_name() << " solved: " << count << "/" << tasks.size() << endl;
	}
	
private:
	vector<vector<double>> tasks;

};

class GoodStudent : public Student {
public:	
	GoodStudent(string n) {
		name = n;
	}

	vector<double> solve_quad_eq(vector<double> task) {
		return quad_eq_roots(task);
	}
};

class NormalStudent : public Student {
public:
	NormalStudent(string n) {
		name = n;
	}

	vector<double> solve_quad_eq(vector<double> task) {
		double x = rand() % 100 + 1;
		if (x <= solveprob) {
			return quad_eq_roots(task);
		}
		else {
			return { 3.0,3.0 }; // «аведомо неверный ответ 3 корн€ у квадратного ур-ни€, никогда не бывает
		}
	}
private:
	double solveprob = 51;
};

class BadStudent : public Student {
public:
	BadStudent(string n) {
		name = n;
	}

	vector<double> solve_quad_eq(vector<double> task){
		return { 3.0, 3.0 };		// «аведомо неверный ответ 3 корн€ у квадратного ур-ни€, никогда не бывает
	}

};


int main() {
	schoolClass cl("10B");
	Teacher T;
	ifstream fin("students.txt");
	ifstream fitask("tasks.txt");
	//—читываем список класса
	string student;
	while (getline(fin, student)) {
		//–аспределение успеваемости
		Student* st;
		int ran = rand() % 10 + 1;
		if (ran <= 2) {
			st = new GoodStudent(student);
		}
		else if (ran <= 8) {
			st = new NormalStudent(student);
		}
		else {
			st = new BadStudent(student);
		}
		cl.add_student(st);
	}
	//—читываем задани€
	double num;
	vector<double> task;
	int i = 0;
	while ((fitask >> num)) {
		task.push_back(num);
		i++;
		if (i == 3) {
			T.add_task(task);
			task.clear();
			i = 0;
		}
	}
	//ѕроверка работ всего класса
	T.check_whole_class(&cl);

	return 0;
}