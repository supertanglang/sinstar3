#include "stdafx.h"
#include "SimpleWnd.h"

CSimpleWnd::CSimpleWnd(void)
{
	m_hWnd=0;
}

CSimpleWnd::~CSimpleWnd(void)
{
}

HWND CSimpleWnd::Create(HINSTANCE hInst)
{
	return ::CreateWindowEx(0,CLS_SIMPLEWND,NULL,WS_POPUP,0,0,0,0,HWND_MESSAGE,(HMENU)0,hInst,this);
}

BOOL CSimpleWnd::Destroy()
{
	return DestroyWindow(m_hWnd);
}

LRESULT CALLBACK CSimpleWnd::SimpleWndProc(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	CSimpleWnd* pWnd = NULL;
	if(uMsg==WM_CREATE)
	{
		pWnd=(CSimpleWnd*)((LPCREATESTRUCT)lParam)->lpCreateParams;
		pWnd->Attach(hWnd);
	}else
	{
		pWnd=(CSimpleWnd*)GetWindowLongPtr(hWnd,GWLP_USERDATA);
	}
	if(0 == pWnd)
	{
		return ::DefWindowProc(hWnd, uMsg, wParam, lParam);
	}

	return pWnd->WindowProc(uMsg, wParam, lParam);
}

LRESULT CSimpleWnd::WindowProc(UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	return ::DefWindowProc(m_hWnd,uMsg,wParam,lParam);
}



void CSimpleWnd::Attach(HWND hWnd)
{
	assert(GetWindowLongPtr(hWnd,GWLP_USERDATA)==0 && m_hWnd==NULL);
	SetWindowLongPtr(hWnd,GWLP_USERDATA,(LONG_PTR)this);
	m_hWnd=hWnd;
}

void CSimpleWnd::Detatch()
{
	assert(m_hWnd);
	SetWindowLongPtr(m_hWnd,GWLP_USERDATA,NULL);
	m_hWnd=0;
}

BOOL CSimpleWnd::RegisterWndClass(HINSTANCE hInstance)
{
	WNDCLASSEX wc;

	wc.cbSize         = sizeof(WNDCLASSEX);
	wc.style          = CS_IME;
	wc.lpfnWndProc    = SimpleWndProc;
	wc.cbClsExtra     = 0;
	wc.cbWndExtra     = 0;
	wc.hInstance      = (HINSTANCE)hInstance;
	wc.hCursor        = LoadCursor( NULL, IDC_ARROW );
	wc.hIcon          = NULL;
	wc.lpszMenuName   = (LPTSTR)NULL;
	wc.lpszClassName  = CLS_SIMPLEWND;
	wc.hbrBackground  = NULL;
	wc.hIconSm        = NULL;

	return RegisterClassEx(&wc );
}

void CSimpleWnd::UnregisterWndClass(HINSTANCE hInstance)
{
	UnregisterClass(CLS_SIMPLEWND,hInstance);
}
