#ifndef __MYSTRING_H__
#define __MYSTRING_H__



class MyString{
	public:
		MyString(const char *);
		~MyString();
		int print() const;
		class MyStringImpl;
	private:
		MyStringImpl *_myPImpl;
};

#endif
