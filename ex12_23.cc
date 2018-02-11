#include <iostream>
#include <string>
#include <cstring>
#include <memory>

using namespace std;

int main() {
	string s1 = "how are you ";
	string s2 = "Fine, thank you";

	string::size_type length1 = s1.size() + s2.size();
	char *s = new char[length1];

	for (size_t i = 0; i != length1; i++) {
		if (i < s1.size()) {
			s[i] = s1[i];
		} 
		else {
			s[i] = s2[i - s1.size()];
		}
	}

	cout << s << endl;
	delete[] s;

	const char *s3 = "What's wrong? ";
	const char *s4 = "Nothing";

	size_t length2 = strlen(s3) + strlen(s4);
	unique_ptr<char[]> up(new char[length2]);

	for (size_t i = 0; i != length2; i++) {
		if (i < strlen(s3)) {
			up[i] = *(s3 + i);
		}
		else {
			up[i] = *(s4 + i - strlen(s3));
		}

		cout << up[i];
	}

	cout << endl;

	return 0;
}