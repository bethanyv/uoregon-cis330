#include <vector>
#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

void printVector(const vector<int> & v) {
	for (vector<int>::const_iterator iter = v.begin(); iter != v.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;
}

void sortVector(const vector<int> & v){

}

int main(int argc, char const *argv[])
{
	std::vector<int> v(15);

	default_random_engine generator;
	uniform_int_distribution<int> distribution(1,100);

	for(int i = 0; i < 15; ++i) {
		int num = distribution(generator);
		v[i] = num;
	}
	printVector(v);
	sort(v.begin(), v.end());
	printVector(v);
	
	return 0;
}