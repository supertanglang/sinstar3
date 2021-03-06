//stamp:09287ef5d7e807ee
/*<------------------------------------------------------------------------------------------------->*/
/*该文件由uiresbuilder生成，请不要手动修改*/
/*<------------------------------------------------------------------------------------------------->*/
#pragma once
#include <res.mgr/snamedvalue.h>
#define ROBJ_IN_CPP \
namespace SOUI \
{\
    const _R R;\
    const _UIRES UIRES;\
}
namespace SOUI
{
	class _UIRES{
		public:
		class _UIDEF{
			public:
			_UIDEF(){
				XML_INIT = _T("UIDEF:XML_INIT");
			}
			const TCHAR * XML_INIT;
		}UIDEF;
		class _LAYOUT{
			public:
			_LAYOUT(){
				XML_MAINWND = _T("LAYOUT:XML_MAINWND");
				dlg_donate = _T("LAYOUT:dlg_donate");
			}
			const TCHAR * XML_MAINWND;
			const TCHAR * dlg_donate;
		}LAYOUT;
		class _values{
			public:
			_values(){
				string = _T("values:string");
				color = _T("values:color");
				skin = _T("values:skin");
			}
			const TCHAR * string;
			const TCHAR * color;
			const TCHAR * skin;
		}values;
		class _IMG{
			public:
			_IMG(){
				png_logo = _T("IMG:png_logo");
			}
			const TCHAR * png_logo;
		}IMG;
		class _ICON{
			public:
			_ICON(){
				ICON_LOGO = _T("ICON:ICON_LOGO");
			}
			const TCHAR * ICON_LOGO;
		}ICON;
	};
	const SNamedID::NAMEDVALUE namedXmlID[]={
		{L"_name_start",65535},
		{L"btn_close",65536},
		{L"btn_donate",65544},
		{L"btn_install",65541},
		{L"btn_min",65537},
		{L"btn_uninstall",65543},
		{L"btn_update",65542},
		{L"chk_agree",65539},
		{L"edit_license",65538},
		{L"tab_pay_way",65545},
		{L"wnd_btn_container",65540}		};
	class _R{
	public:
		class _name{
		public:
		_name(){
			_name_start = namedXmlID[0].strName;
			btn_close = namedXmlID[1].strName;
			btn_donate = namedXmlID[2].strName;
			btn_install = namedXmlID[3].strName;
			btn_min = namedXmlID[4].strName;
			btn_uninstall = namedXmlID[5].strName;
			btn_update = namedXmlID[6].strName;
			chk_agree = namedXmlID[7].strName;
			edit_license = namedXmlID[8].strName;
			tab_pay_way = namedXmlID[9].strName;
			wnd_btn_container = namedXmlID[10].strName;
		}
		 const wchar_t * _name_start;
		 const wchar_t * btn_close;
		 const wchar_t * btn_donate;
		 const wchar_t * btn_install;
		 const wchar_t * btn_min;
		 const wchar_t * btn_uninstall;
		 const wchar_t * btn_update;
		 const wchar_t * chk_agree;
		 const wchar_t * edit_license;
		 const wchar_t * tab_pay_way;
		 const wchar_t * wnd_btn_container;
		}name;

		class _id{
		public:
		const static int _name_start	=	65535;
		const static int btn_close	=	65536;
		const static int btn_donate	=	65544;
		const static int btn_install	=	65541;
		const static int btn_min	=	65537;
		const static int btn_uninstall	=	65543;
		const static int btn_update	=	65542;
		const static int chk_agree	=	65539;
		const static int edit_license	=	65538;
		const static int tab_pay_way	=	65545;
		const static int wnd_btn_container	=	65540;
		}id;

		class _string{
		public:
		const static int donate	=	0;
		const static int title	=	1;
		const static int ver	=	2;
		}string;

		class _color{
		public:
		const static int blue	=	0;
		const static int gray	=	1;
		const static int green	=	2;
		const static int red	=	3;
		const static int white	=	4;
		}color;

	};

#ifdef R_IN_CPP
	 extern const _R R;
	 extern const _UIRES UIRES;
#else
	 extern const __declspec(selectany) _R & R = _R();
	 extern const __declspec(selectany) _UIRES & UIRES = _UIRES();
#endif//R_IN_CPP
}
