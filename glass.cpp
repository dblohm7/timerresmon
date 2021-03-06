#include <windows.h>
#include <commctrl.h>
#include <ShellScalingApi.h>
#include <string>

#include "glasswnd.h"

using namespace std;
using aspk::GlassWindow;

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                     LPSTR lpCmdLine, int nCmdShow)
{
  InitCommonControls();

  GlassWindow mainWindow(hInstance, wstring(L"Glass Scratch"));
  mainWindow.Show(nCmdShow);
  mainWindow.Update();

  MSG msg;
  BOOL bRet;
  while (bRet = GetMessage(&msg, NULL, 0, 0)) {
    if (bRet == -1) {
      return 1;
    } else {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }
  }
  return (DWORD)(msg.wParam);
}

