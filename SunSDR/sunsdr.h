#ifndef SUNSDR_H
#define SUNSDR_H
#include <QLibrary>

#ifdef Q_OS_WIN
#include "windows.h"
#define EXPORT extern "C" __declspec(dllexport) __cdecl
#endif

#ifdef Q_OS_LINUX
typedef unsigned char  BYTE;
typedef unsigned short  WORD;
typedef unsigned long  DWORD;
typedef int BOOLEAN;
typedef unsigned int UINT_PTR;
typedef long LONG;
#define EXPORT __attribute__((__visibility__("default")))
#endif



enum StateChgReason {
    crPtt = 0,
    crDash = 1,
    crDot = 2,
    crAdc = 3
};

#ifdef Q_OS_LINUX
typedef void (*CallbackFunc_SdrStateChanged)(UINT_PTR handle, StateChgReason reason, bool arg1, int arg2, int arg3);
#endif

#ifdef Q_OS_WIN
typedef __cdecl void (*CallbackFunc_SdrStateChanged)(UINT_PTR handle, StateChgReason reason, bool arg1, int arg2, int arg3);
#  endif

void PttChanged(bool KeyPtt);
void DashChanged(bool KeyDash);
void DotChanged(bool KeyDot);
void AdcChanged(int Ufwd, int Uref);

#endif // SUNSDR_H
