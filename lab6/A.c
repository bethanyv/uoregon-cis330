class A {
	A() {d = 4;}
	A(A& existing) { this->d = existing.d; }
	A(A&& existing) { this->d = existing.d; }

private:
	int d;
}