#pragma once
#include "ThreadObject.h"

struct SHELLEXECUTEDATA
{
	int nType;
	SStringT strOp;
	SStringT strFileName;
};

#define UM_PROCESSEXIT	(WM_USER+400)

class CShellExecuteMonitor : public CThreadObject
{
public:
	CShellExecuteMonitor(SHELLEXECUTEDATA *pData, HWND hMsgRecv);
	~CShellExecuteMonitor();

	const SHELLEXECUTEDATA * GetShellExecuteInfo() const {
		return m_shellExecuteInfo;
	}

	DWORD GetExitCode() const {
		return m_exitCode;
	}

	static HANDLE ShellExe(LPCTSTR pszOp, LPCTSTR pszFileName);
protected:
	virtual UINT Run(LPARAM lp);

	SHELLEXECUTEDATA *m_shellExecuteInfo;
	HWND		 m_hWndRecv;
	DWORD		 m_exitCode;
};

