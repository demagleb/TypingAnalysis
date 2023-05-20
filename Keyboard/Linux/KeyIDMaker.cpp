#include "KeyIDMaker.h"
#include <iostream>
#include <iomanip>

namespace NSApplication {
namespace NSKeyboard {
namespace NSLinux {

CKeyID CKeyIDMaker::make(int keysym, bool press) {
  if (press) {
    std::cout << std::hex <<"KeyId maker keysym: 0x" << keysym << std::endl;
  }
  switch (keysym) {
  case 0xff08:
    return CKeyIDEnum::Backspace;
  case 0xff09:
    return CKeyIDEnum::Tab;
  case 0xff0d:
    return CKeyIDEnum::Enter;
  case 0x1008ff14:
    return CKeyIDEnum::Pause;
  case 0xffe5:
    return CKeyIDEnum::Capslock;
  case 0xff1b:
    return CKeyIDEnum::Esc;
  case 0x20:
    return CKeyIDEnum::Spacebar;
  case 0xff9a:
    return CKeyIDEnum::PageUp;
  case 0xff55:
    return CKeyIDEnum::PageUp;
  case 0xff9b:
    return CKeyIDEnum::PageDown;
  case 0xff56:
    return CKeyIDEnum::PageDown;
  case 0xff57:
    return CKeyIDEnum::End;
  case 0xff95:
    return CKeyIDEnum::Home;
  case 0xff50:
    return CKeyIDEnum::Home;
  case 0xff51:
    return CKeyIDEnum::LeftArrow;
  case 0xff52:
    return CKeyIDEnum::UpArrow;
  case 0xff53:
    return CKeyIDEnum::RightArrow;
  case 0xff54:
    return CKeyIDEnum::DownArrow;
  case 0xff63:
    return CKeyIDEnum::Insert;
  case 0xff9e:
    return CKeyIDEnum::Insert;
  case 0xffff:
    return CKeyIDEnum::Delete;
  case 0xff9f:
    return CKeyIDEnum::Delete;
  case 0xffeb:
    return CKeyIDEnum::LeftWin;
  case 0xffb0:
    return CKeyIDEnum::Numpad_0;
  case 0xffb1:
    return CKeyIDEnum::Numpad_1;
  case 0xffb2:
    return CKeyIDEnum::Numpad_2;
  case 0xffb3:
    return CKeyIDEnum::Numpad_3;
  case 0xffb4:
    return CKeyIDEnum::Numpad_4;
  case 0xffb5:
    return CKeyIDEnum::Numpad_5;
  case 0xffb6:
    return CKeyIDEnum::Numpad_6;
  case 0xffb7:
    return CKeyIDEnum::Numpad_7;
  case 0xffb8:
    return CKeyIDEnum::Numpad_8;
  case 0xffb9:
    return CKeyIDEnum::Numpad_9;
  case 0xffbe:
    return CKeyIDEnum::F1;
  case 0xffbf:
    return CKeyIDEnum::F2;
  case 0xffc0:
    return CKeyIDEnum::F3;
  case 0xffc1:
    return CKeyIDEnum::F4;
  case 0xffc2:
    return CKeyIDEnum::F5;
  case 0xffc3:
    return CKeyIDEnum::F6;
  case 0xffc4:
    return CKeyIDEnum::F7;
  case 0xffc5:
    return CKeyIDEnum::F8;
  case 0xffc6:
    return CKeyIDEnum::F9;
  case 0xffc7:
    return CKeyIDEnum::F10;
  case 0xffc8:
    return CKeyIDEnum::F11;
  case 0xffc9:
    return CKeyIDEnum::F12;
  case 0xff7f:
    return CKeyIDEnum::Numlock;
  case 0xffe1:
    return CKeyIDEnum::LeftShift;
  case 0xffe2:
    return CKeyIDEnum::RightShift;
  case 0xffe3:
    return CKeyIDEnum::LeftCtrl;
  case 0xffe4:
    return CKeyIDEnum::RightCtrl;
  case 0xffe9:
    return CKeyIDEnum::LeftAlt;
  case 0xff10:
    return CKeyIDEnum::RightAlt;
  default:
    return CKeyIDEnum::Regular;// '"*/
  }
}

}
}
}

