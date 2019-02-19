#include <string>
#include <streamio>

class Student {
	Student(int age, string firstName, string lastName) {
		this->firstName = firstName;
		this->lastName = lastName;
		this->age = age;
	}
public:
	int getAge();
	bool setAge(int age);
	string getFirst();
	bool setFirst(string first);
	string getLast();
	bool setLast(string last);
private: 
	string firstName;
	string lastName;
	int age;
}