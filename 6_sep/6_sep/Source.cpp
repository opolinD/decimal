#include<iostream>
#include<string>
static int last_id=11111111;
class FIO {
	std::string name, surname, lastname;
public:
	FIO() {
		name = "no name";
		surname = "no surname";
		lastname = "no lastname";
	}
	FIO(std::string _name, std::string _surname,
		std::string _lastname) :name(_name), surname(_surname), lastname(_lastname) {}
	FIO(const FIO& a) :name(a.name), surname(a.surname), lastname(a.lastname) {}	
	FIO& operator =(FIO& a) {
		if (this != &a) {
			FIO tmp(a);
			this->swap(tmp);
		}
		return *this;
	}
	void swap(FIO& a) {
		std::swap(this->name, a.name);
		std::swap(this->surname, a.surname);
		std::swap(this->lastname, a.lastname);
	}	
	std::string get_fio() {
		std::string full_fio = surname +" " + name + " " + lastname;
		return full_fio;
	}
	friend std::ostream& operator << (std::ostream& out, const FIO& a);
	friend std::istream& operator>>(std::istream& in, FIO& a);
	friend bool operator ==(const FIO& a, const FIO& b);
	friend bool operator <(const FIO& a, const FIO& b);
	friend bool operator >(const FIO& a, const FIO& b);
};
bool operator ==(const FIO& a, const FIO& b) {
	return (a.name == b.name) && (a.surname == b.surname) && (a.lastname == b.lastname);
}
bool operator <(const FIO& a, const FIO& b) {
	if(a.surname!=b.surname){
		int a_size = a.surname.size();
		int b_size = b.surname.size();
		int minimum = std::min(a_size, b_size);
		for (int i = 0; i < minimum-1;i++) {
			if(a.surname[i]<b.surname[i]) {
				return true;
			}
		}
	}
	else if (a.name!=b.name) {
		int a_size = a.name.size();
		int b_size = b.name.size();
		int minimum = std::min(a_size, b_size);
		for (int i = 0; i < minimum - 1; i++) {
			if (a.name[i] < b.name[i]) {
				return true;
			}
		}
	}
	else if (a.lastname!=b.lastname) {
		int a_size = a.lastname.size();
		int b_size = b.lastname.size();
		int minimum = std::min(a_size, b_size);
		for (int i = 0; i < minimum - 1; i++) {
			if (a.lastname[i] < b.lastname[i]) {
				return true;
			}
		}
	}
	else {
		return false;
	}
}
bool operator >(const FIO& a, const FIO& b) {
	if (a.surname != b.surname) {
		int a_size = a.surname.size();
		int b_size = b.surname.size();
		int minimum = std::min(a_size, b_size);
		for (int i = 0; i < minimum - 1; i++) {
			if (a.surname[i] > b.surname[i]) {
				return true;
			}
		}
	}
	else if (a.name != b.name) {
		int a_size = a.name.size();
		int b_size = b.name.size();
		int minimum = std::min(a_size, b_size);
		for (int i = 0; i < minimum - 1; i++) {
			if (a.name[i] > b.name[i]) {
				return true;
			}
		}
	}
	else if (a.lastname != b.lastname) {
		int a_size = a.lastname.size();
		int b_size = b.lastname.size();
		int minimum = std::min(a_size, b_size);
		for (int i = 0; i < minimum - 1; i++) {
			if (a.lastname[i] > b.lastname[i]) {
				return true;
			}
		}
	}
	else {
		return true;
	}
}
std::ostream& operator << (std::ostream& out, const FIO& a) {
	out << a.name << " " << a.surname << " " << a.lastname;
	return out;
}
std::istream& operator>>(std::istream& input, FIO& a) {
	std::cout << "Input name: ";
	input >> a.name;
	std::cout << "Input surname: ";
	input >> a.surname;
	std::cout << "Input lastname: ";
	input >> a.lastname;
	return input;
}
class Student {
	FIO fio;
	float GPA;
	int id;
	bool scolarship;
	bool budget;
public:
	Student() :id(last_id++) {}
	Student(FIO _fio, int _id,float gpa ,bool ss, bool b):fio(_fio), 
	GPA(gpa), id(last_id++),scolarship(ss), budget(b){}
	Student(const Student& a):fio(a.fio), GPA(a.GPA), id(last_id++),
	scolarship(a.scolarship), budget(a.budget){}
	~Student();
	const Student& min_gpa(const Student& a, const Student& b){
		if (a.GPA<b.GPA) {
			return a;
		}
		else {
			return b;
		}
	}
	Student& operator =(Student& a) {
		if (this != &a) {
			Student tmp(a);
			tmp.fio = a.fio;
			this->swap(tmp);
		}
		return *this;
	}
	std::string get_full_fio() {
		return fio.get_fio();
	}
	int get_id() {
		return id;
	}
	void swap(Student& a) {
		std::swap(GPA,a.GPA);
		std::swap(id, a.id);
		std::swap(scolarship, a.scolarship);
		std::swap(budget, a.budget);
	}
	void print(){
		std::cout << id << fio << GPA;
		if (scolarship == true) {
			std::cout << "yes";

		}
		else {
			std::cout << "no";
		}
		if (budget== true) {
			std::cout << "yes";
		}
		else {
			std::cout << "no";
		}
	}
	
};
class archive {
	std::string name;
	Student* arch;
	int size;
public:
	archive(std::string _name):name(_name), size(0){
		arch = new Student[1];
	}
	~archive(){
		delete []arch;
	}
	void add(Student& a){
	Student* new_arch = new Student[++size];
		for (int i = 0; i < size-1; i++) {
			new_arch[i] = arch[i];
		}
	delete[] arch;
	arch = new_arch;
	new_arch[size] = a;
	}
	int find(std::string _fio) {
		for (int i = 0; i < size;i++) {
			if (arch[i].get_full_fio() == _fio){ 
				return arch[i].get_id();
			}
		}
	}
	void del(int _id) {
		for (int i = _id - 11111111; i < size;i++) {
			arch[i - 1] = arch[i];
		}
		size--;
	}
	void print() {
		std::cout << "id" << "FIO" << "GPA" << "scolarship"<<"budget"<<"\n";
		for (int i = 0; i < size;i++) {
			arch[i].print();
			std::cout << "\n";
		}
	}
};

