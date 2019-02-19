class A {
	A() {d = new int[4];}
	A(A& existing) { this->d = existing.d; } // shallow copy
	A(A&& existing) { this->d = existing.d; }
	A(string CheerfulMessage) { cout << CheerfulMessage << endl; }
	~A() {delete [] this->d; }

	private:
		int *d;
}