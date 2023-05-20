#ifndef NSAPPLICATION_NSKEYBOARD_NSLINUX_CKEYBOARDLISTENERLIN_H
#define NSAPPLICATION_NSKEYBOARD_NSLINUX_CKEYBOARDLISTENERLIN_H


#include "Keyboard/AnyKeyboardKiller.h"
#include "Keyboard/KeyTextData.h"
#include "Keyboard/RawKeyEvent.h"
#include "KeysymMaker.h"

#include <QObject>
#include <future>

namespace NSApplication {
namespace NSKeyboard {

class CKeyboardHandler;

namespace NSLinux {

class CKeyboardListenerImplDisplay {
public:
  CKeyboardListenerImplDisplay();
  ~CKeyboardListenerImplDisplay();

  CKeyboardListenerImplDisplay(const CKeyboardListenerImplDisplay&) = delete;
  CKeyboardListenerImplDisplay(CKeyboardListenerImplDisplay&&) noexcept = delete;
  CKeyboardListenerImplDisplay& operator=(const CKeyboardListenerImplDisplay&) = delete;
  CKeyboardListenerImplDisplay& operator=(CKeyboardListenerImplDisplay&&) noexcept = delete;

protected:
  Display* X11Display_;
};

class CKeyboardListenerImplDesc : protected CKeyboardListenerImplDisplay {
public:
  CKeyboardListenerImplDesc();
  ~CKeyboardListenerImplDesc();

protected:
  XkbDescPtr XkbDesc_;
};

class CKeyboardListenerImplWindow : protected CKeyboardListenerImplDesc {
public:
  CKeyboardListenerImplWindow();
  ~CKeyboardListenerImplWindow();

protected:
  Window MessageWindow_;
};

class CKeyboardListenerLinImpl : public QObject,
                                 protected CKeyboardListenerImplWindow {
  Q_OBJECT

  friend class CKiller;

public:
  using CAnyKillerPromise = std::promise<CAnyKeyboardKiller>;
  CKeyboardListenerLinImpl(CAnyKillerPromise, CKeyboardHandler*);
  ~CKeyboardListenerLinImpl();

Q_SIGNALS:
  void KeyPressing(const CKeyPressing&);
  void KeyReleasing(const CKeyReleasing&);

public:
  int exec();

private:
  CKeysymMaker KeysymMaker_;
  CKeysymMaker DeadLabelMaker_;
  class XGenericEventCookieWrapper{
  public:
    XGenericEventCookieWrapper(Display*, XEvent*);
    ~XGenericEventCookieWrapper();
    XGenericEventCookie* getPtr();

  private:
    XGenericEventCookie* cookie_;
    Display* dpy_;
  };

  int handleKeyPress(XGenericEventCookie*);
  int handleKeyRelease(XGenericEventCookie*);
  int isInteruptionRequested(XEvent&) const;
  XIDeviceEvent* getXIDeviceEvent(XGenericEventCookie*) const;
  xkb_keycode_t getKeycode(XIDeviceEvent*) const;
  NSKernel::CKeyFlags getShifters(XIDeviceEvent*);
  CKeyTextData makeTextFromKeysym(xkb_keysym_t);
  bool isLastDead() const;
  CLabelData getLabel(xkb_keysym_t);
  char buf_[17];
  static constexpr const int buf_len_ = 17;
  static constexpr const char kKillerMsg_[] = "kill";
  // Implementation details
};

// The object provides a way to shut down the listener
class CKiller {
public:
  CKiller(Display*, Window);
  void stopListener() const;

private:
  Display* X11Display_;
  Window MessageWindow_;
  XEvent makeClientMessageEvent(const char*) const;
};

} // namespace NSLinux
} // namespace NSKeyboard
} // namespace NSApplication

#endif // NSAPPLICATION_NSKEYBOARD_NSLINUX_CKEYBOARDLISTENERLIN_H
