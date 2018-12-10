#ifndef __RCSTRING_H__
#define __RCSTRING_H__

#include <iostream>

class rcstring{
	  struct rctext;
	  rctext* data;
	public:
	class Range{};
	class Cref;
	rcstring();
	rcstring(const char*);
	rcstring(const rcstring&);
	~rcstring();
	rcstring& operator=(const char*);
	rcstring& operator=(const rcstring&);
	rcstring& operator+=(const rcstring &);
	rcstring operator+(const rcstring &) const;
	friend std::ostream& operator<<(std::ostream&, const rcstring&);
	void check (unsigned int i) const;
	char read(unsigned int i) const;
	void write(unsigned int i, char c);
	char operator[](unsigned int i) const;
	Cref operator[](unsigned int i);
	
	rcstring& toLower();
	int atoi();
	rcstring Left(int n);
};

#endif /* __RCSTRING_H__ */
