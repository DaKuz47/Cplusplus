
#include "school.h"



using namespace std;

Student::Student(string n) {
	name = n;
}

string Student::get_name() {
	return name;
}

vector<double> Student::solve_quad_eq(vector<double> task) {
	return task;
};

schoolClass::schoolClass(string str) {
	id = str;
}

void schoolClass::add_student(Student* st) {
	students.push_back(st);
	return;
}

vector<Student*> schoolClass::get_students() {
	return students;
}

void Teacher::add_task(vector<double> t) {
	tasks.push_back(t);
	return;
}

vector<vector<double>> Teacher::get_task() {
	return tasks;
}

void Teacher::check_whole_class(schoolClass* cl) {
	for (auto x : cl->get_students()) {
		check_student_work(x);
	}
}

void Teacher::check_student_work(Student* st) {
	int count = 0;
	for (auto t : tasks) {
		vector<double> sol = st->solve_quad_eq(t);
		if (sol == quad_eq_roots(t)) {
			count++;
		}
	}
	cout << st->get_name() << " solved: " << count << "/" << tasks.size() << endl;
}
GoodStudent::GoodStudent(string n) {
	name = n;
}

vector<double> GoodStudent::solve_quad_eq(vector<double> task) {
	return quad_eq_roots(task);
}

NormalStudent::NormalStudent(string n) {
	name = n;
}

vector<double> NormalStudent::solve_quad_eq(vector<double> task) {
	double x = rand() % 100 + 1;
	if (x <= solveprob) {
		return quad_eq_roots(task);
	}
	else {
		return { 3.0,3.0,3.0 }; // Заведомо неверный ответ 3 корня у квадратного ур-ния, никогда не бывает
	}
}

BadStudent::BadStudent(string n) {
	name = n;
}
vector<double> BadStudent::solve_quad_eq(vector<double> task) {
	return { 3.0, 3.0, 3.0 };		// Заведомо неверный ответ 3 корня у квадратного ур-ния, никогда не бывает
}
