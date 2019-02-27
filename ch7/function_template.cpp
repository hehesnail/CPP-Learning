#include <iostream>

using namespace std;

template <class T>
inline
const T& mymin(const T& a, const T& b)
{
	return b < a? b : a;
}

class stone
{
public:
	stone(int w = 0, int h = 0, int we = 0)
	:_w(w), _h(h), _weight(we){}
	bool operator < (const stone& rhs) const
	{
		return _weight < rhs._weight;
	}
	int getw() const {return _w;}
	int geth() const {return _h;}
	int getwe() const {return _weight;}
private:
	int _w, _h, _weight;
};

inline 
ostream& operator << (ostream& os, const stone& s)
{
	os << '(' << s.getw() << ',' << s.geth() << ',' << s.getwe() << ')';
}

int main()
{
	stone r1(1,1,1), r2(3,3,2), r3;
	r3 = mymin(r1, r2);

	cout << r3 << endl;

	return 0;
}