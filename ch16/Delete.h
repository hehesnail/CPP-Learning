#ifndef __DELETE__
#define __DELETE__

//删除器
class Delete {
public:
	template <typename T>
	void operator() (T *p) const { delete p;}
};

#endif
