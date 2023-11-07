#pragma once


#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             
#include <windows.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <crtdbg.h>
#include <assert.h>

#include <vector>
#include <list>
#include <map>
#include <string>

#pragma comment(lib, "Msimg32.lib")


// Png ����
#include <objidl.h>
#include <gdiplus.h>
#pragma comment(lib, "Gdiplus.lib")

using namespace::Gdiplus;

// ����
#include <mmsystem.h>
#include <dsound.h>
#include <dinput.h>

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "dsound.lib")


// ����Ž����
#include "commdlg.h"

using std::vector;
using std::list;
using std::map;
using std::make_pair;
using std::string;
using std::wstring;

#include "global.h"
