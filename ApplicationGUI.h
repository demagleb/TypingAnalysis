#ifndef NSAPPLICATION_CAPPLICATIONGUI_H
#define NSAPPLICATION_CAPPLICATIONGUI_H

#include "Qt/MainWindow.h"

#include <memory>

#ifdef KEYBOARD_HANDLER_DEBUG
#include "AppDebug/KeyboardHandlerDebugOut.h"
#endif

#ifdef SEANCE_MANAGER_DEBUG
#include "AppDebug/SeanceManagerDebugOut.h"
#endif

namespace NSApplication {

class CApplicationGUI {
public:
  CApplicationGUI();

protected:
  NSQt::CMainWindow* mainWindow();

private:
  NSQt::CMainWindow AppWindow_;

protected:
#ifdef KEYBOARD_HANDLER_DEBUG
  NSAppDebug::CKeyboardHandlerDebugOut KeyboardHandlerOut_ = mainWindow();
#endif

#ifdef SEANCE_MANAGER_DEBUG
  NSAppDebug::CSeanceManagerDebugOut SeanceManagerOut_ = mainWindow();
#endif
};

} // namespace NSApplication

#endif // NSAPPLICATION_CAPPLICATIONGUI_H
