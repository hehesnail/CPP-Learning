#include <iostream>
#include <cctype>

using namespace std;

int main()
{
	string s = "hello world !!!";
	for (auto &c :s)
	{
		c = toupper(c);
	}
	cout << s << endl;

	string s2 = "some string";

	for (decltype(s2.size()) index = 0;
		index != s2.size() && !isspace(s2[index]);++index)
		s2[index] = toupper(s2[index]);
	cout << s2 << endl;

	string s3;
	cout << s3[0] << endl;

	const string s4 = "Keep out";
	for (auto &c : s4)
	{
		cout << c << endl;
	}

	const string hexdigits = "0123456789ABCDEF";
	string res;
	//string::size_type n;
	char n;
	while (cin >> n)
		if (n < hexdigits.size())
			res += hexdigits[n];
	cout << res << endl;

	return 0;
}