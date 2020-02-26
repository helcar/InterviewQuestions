#include "src/filter.h"
#include "Test/test.h"

using namespace std;

void showInformation() {

	cout << "Title: Robotic Engineer - Entry/Mid Level" << endl;
	cout << "Name: Gengda Li" << endl;
	cout << "Date: 2020.02.25" << endl;
	cout << "Language: C++" << endl;
	cout << "Environment: VSCode" << endl;
	cout << "GitHub Pages: " << endl;
	cout << " " << endl;

}

int main(){

	showInformation();
	// Run test cases
	Test TEST;
	TEST.tests();

	return 0;
}
