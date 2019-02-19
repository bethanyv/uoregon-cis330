#include <string>
#include <streamio>

class Student {
	Student() {
		this->firstName = "UNKNOWN";
		this->lastName = "UNKNOWN";
		this->age = 0;
	}
public:

	int getAge() {
		return this->age;
	}
	bool setAge(int age) {
		if(age <= 0) {
			return false;
		}
		this->age = age;
	}

	string getFirst() {
		return this->firstName;
	}
	bool setFirst(string first) {
		this->firstName = first;
	}

	string getLast() {
		return this->lastName;
	}
	bool setLast() {
		this->lastName = last;
	}

private: 
	string firstName;
	string lastName;
	int age;
}

int main() {
	new Student s;
	cout << s.getFirst << endl;
}