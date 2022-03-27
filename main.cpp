#include "stacknode.h"
#include <iostream>
using namespace std;

int main () {
	Stack<int> stk;
	int n;

	cout << "Enter an int, or 0 to quit: ";
	cin >> n;
	while (n != 0) {
		stk.push(n);
		cout << "Enter an int, or 0 to quit: ";
		cin >> n;
	}

	cout << endl;
	while (!stk.empty()) {
		cout << stk.top() << endl;
		stk.pop();
	}

	return 0;
}