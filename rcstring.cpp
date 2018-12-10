#include "rcstring.h"
#include "rctext.h"
#include "cref.h"
#include <string.h>

rcstring::rcstring()
  {
    data = new rctext(0,"");
  }

rcstring::rcstring(const rcstring& x)
  {
    x.data->n++;
    data=x.data;
  }
rcstring::~rcstring()
{
  if(--data->n==0)
    delete data;
}

rcstring& rcstring::operator=(const rcstring & x)
{
  x.data->n++;
  if(--data->n == 0)
    delete data;
  data=x.data;
  return *this;
}

rcstring::rcstring(const char* s)
{
 data=new rctext(strlen(s),s);
}

rcstring& rcstring::operator=(const char* s)
{
  if(data->n==1)
    data->assign(strlen(s),s);
  else
  {
    rctext* t = new rctext(strlen(s),s);
    data->n--;
    data= t;
  };
  return *this;
}

std::ostream& operator << (std::ostream& o, const rcstring& s)
{
  return o<<s.data->s;
}

rcstring& rcstring::operator+=(const rcstring & s)
{
unsigned int newsize=data->size+s.data->size;
rctext *newdata=new rctext(newsize,data->s);
strcat(newdata->s,s.data->s);
if(--data->n==0)
  delete data;
data = newdata;
return *this;
}

rcstring rcstring::operator+(const rcstring & s) const
{
  return rcstring(*this)+=s;
}

void rcstring::check (unsigned int i) const
{
if(data->size<=i)
  throw Range();
}
char rcstring::read(unsigned int i) const
{
 return data->s[i];
}
void rcstring::write(unsigned int i, char c)
{
  data = data->detach();
  data->s[i] = c;
}

char rcstring::operator[](unsigned int i) const
{
  std::cout << "char rcstring::operator[](unsigned int i) const"<<std::endl;
  check(i);
  return data->s[i];
}

rcstring::Cref rcstring::operator[](unsigned int i)
{
  std::cout << "Cref rcstring::operator[](unsigned int i)"<<std::endl;
  check(i);
  return Cref(*this,i);
}

rcstring& rcstring::toLower()
{
    for(int i = 0; (unsigned)i<this->data->size; i++)
	{
        if(((unsigned)this->data->s[i] - 'A' < 26)==1)
            this->data->s[i] = this->data->s[i] | 32;
        else
            this->data->s[i] = this->data->s[i];
    }
    return *this;
}

int rcstring::atoi()
{
    int res = 0;
    for (int i = 0; (unsigned)i<this->data->size; ++i)
	{
        res = res*10 + this->data->s[i] - '0';
    }
    return res;
}

rcstring rcstring::Left(int n)
{
    rcstring temp;
    data = data->detach();
    int limit = std::min((unsigned)n, this->data->size);
    for (int i = 0; (unsigned)i<(unsigned)limit; i++)
	{
        temp.data->s[i] = this->data->s[i];
    }
    return temp;
}

