// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 从 Windows 头中排除极少使用的资料
#define ENABLE_LANGUAGEBAR

// Windows 头文件:
#define NOIME
#include <windows.h>
#include <tchar.h>
#include <crtdbg.h>

#include "imm.h"
#pragma comment(lib,"imm32.lib")

#include "imeContext.h"

#include "../include/version.h"
#include "../include/sinstar-i.h"

#include "../sinstar3_core/core_loader.h"

extern HINSTANCE g_hInst;
extern DWORD g_dwSystemInfoFlags;

void Helper_Trace(LPCTSTR pszFormat,...);
