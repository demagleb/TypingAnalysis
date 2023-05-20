#ifndef KEYIDLIN_H
#define KEYIDLIN_H

#include "Keyboard/KeyID.h"


namespace NSApplication {
namespace NSKeyboard {
namespace NSLinux {

class CKeyIDMaker
{
public:
  static CKeyID make(int keysym, bool press);
};

}
}
}


#endif // KEYIDLIN_H
