#ifndef __CREF_H__
#define __CREF_H__

class rcstring::Cref
{
  friend class rcstring;
  rcstring& s;
  int i;
  Cref (rcstring& ss, unsigned int ii): s(ss), i(ii) {};
public:
  operator char() const
  {
    std::cout << "operator char() const"<<std::endl;
    return s.read(i);
  }
  rcstring::Cref& operator = (char c)
  {
    std::cout << "void operator = (char c)"<<std::endl;
    s.write(i,c);
    return *this;
  }
  rcstring::Cref& operator = (const Cref& ref)
  {
    return operator= ((char)ref);
  }
};

#endif /* __CREF_H__ */
