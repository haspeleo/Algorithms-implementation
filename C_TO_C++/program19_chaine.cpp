
using namespace std;
#include <iostream>
#include <cstring>
#include <assert.h>

// chaines avec copie profonde
class chaine{
public:
  chaine(const char *s){
    lg = strlen(s);
    ch = new char [lg +1]; 
    assert(ch != 0);
    ch = strcpy(ch,s);
  };
  // ...
  chaine(const chaine&);
  // ...
  ~chaine(){delete [] ch;} 
private:
  char *ch;
  int lg;
};
chaine::chaine(const chaine &c){
  lg = c.lg;
  ch = new char [lg+1];
  assert(ch != 0);
  ch = strcpy(ch, c);
}