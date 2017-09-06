#include "StdAfx.h"
#include "Settings.h"

//ʹ�ù����ڴ淽ʽʹ������Ϣ���������뷨�����й���
#pragma data_seg(".sinstar3")
CSettingsGlobal	g_SettingsG;		//���뷨ȫ������
#pragma data_seg()

SETTINGSL		g_SettingsL;

BOOL WritePrivateProfileInt(
							LPCTSTR lpAppName,  // pointer to section name
							LPCTSTR lpKeyName,  // pointer to key name
							int nKeyValue,   // value to write
							LPCTSTR lpFileName  // pointer to initialization filename
							)
{
	return WritePrivateProfileString(lpAppName,lpKeyName,SStringT().Format(_T("%d"),nKeyValue),lpFileName);
}

CSettingsGlobal::CSettingsGlobal(void):nRefCount(0)
{
}

CSettingsGlobal::~CSettingsGlobal(void)
{
}

const TCHAR * KSession = _T("IME");

void CSettingsGlobal::Save(LPCTSTR pszIniFile)
{
	TCHAR szBuf[100]={0};
	WritePrivateProfileInt(KSession,_T("CompMode"),compMode,pszIniFile);
	WritePrivateProfileString(KSession,_T("PhonticLeft"),szPhonticLeft,pszIniFile);
	WritePrivateProfileString(KSession,_T("PhonticRight"),szPhonticRight,pszIniFile);
	WritePrivateProfileInt(KSession,_T("RateAdjust"),byRateAdjust,pszIniFile);
	WritePrivateProfileInt(KSession,_T("23CandKey"),b23CandKey,pszIniFile);

	WritePrivateProfileInt(KSession,_T("2CandVK"),by2CandVK,pszIniFile);
	WritePrivateProfileInt(KSession,_T("3CandVK"),by3CandVK,pszIniFile);
	WritePrivateProfileInt(KSession,_T("TurnPageUpVK"),byTurnPageUpVK,pszIniFile);
	WritePrivateProfileInt(KSession,_T("TurnPageDownVK"),byTurnPageDownVK,pszIniFile);

	WritePrivateProfileInt(KSession,_T("HotKey_Query"),byHotKeyQuery,pszIniFile);
	WritePrivateProfileInt(KSession,_T("HotKey_Switch_Mode"),byHotKeyMode,pszIniFile);
	WritePrivateProfileInt(KSession,_T("HotKey_Switch_En"),byHotKeyEn,pszIniFile);
	WritePrivateProfileInt(KSession,_T("HotKey_MakeWord"),byHotKeyMakeWord,pszIniFile);
	WritePrivateProfileInt(KSession,_T("HotKey_ShowRoot"),byHotKeyShowRoot,pszIniFile);
	WritePrivateProfileInt(KSession,_T("HotKey_HideStatus"),byHotKeyHideStatus,pszIniFile);

	WritePrivateProfileInt(KSession,_T("Associate"),byAstMode,pszIniFile);
	WritePrivateProfileInt(KSession,_T("SentAssociate"),bAstSent,pszIniFile);
	WritePrivateProfileInt(KSession,_T("SwitchKey"),bySwitchKey,pszIniFile);
	WritePrivateProfileInt(KSession,_T("TempSpellKey"),byTempSpellKey,pszIniFile);
	WritePrivateProfileInt(KSession,_T("Forecast"),byForecast,pszIniFile);
	WritePrivateProfileInt(KSession,_T("PageCands"),cPageCands,pszIniFile);
	WritePrivateProfileInt(KSession,_T("ShowTip"),bShowOpTip,pszIniFile);
	WritePrivateProfileInt(KSession,_T("AutoMatch"),bAutoMatch,pszIniFile);

	szBuf[0]=byLineKey[0];
	WritePrivateProfileString(KSession,_T("LineKey1"),szBuf,pszIniFile);
	szBuf[0]=byLineKey[1];
	WritePrivateProfileString(KSession,_T("LineKey2"),szBuf,pszIniFile);
	szBuf[0]=byLineKey[2];
	WritePrivateProfileString(KSession,_T("LineKey3"),szBuf,pszIniFile);
	szBuf[0]=byLineKey[3];
	WritePrivateProfileString(KSession,_T("LineKey4"),szBuf,pszIniFile);
	szBuf[0]=byLineKey[4];
	WritePrivateProfileString(KSession,_T("LineKey5"),szBuf,pszIniFile);
	szBuf[0]=byLineKey[5];
	WritePrivateProfileString(KSession,_T("LineKey6"),szBuf,pszIniFile);

	WritePrivateProfileInt(KSession,_T("ColorPhontic_Red"),byPntcRed,pszIniFile);
	WritePrivateProfileInt(KSession,_T("ColorPhontic_Green"),byPntcGreen,pszIniFile);
	WritePrivateProfileInt(KSession,_T("ColorPhontic_Blue"),byPntcBlue,pszIniFile);
	WritePrivateProfileInt(KSession,_T("TransStatusP"),byTransStatus,pszIniFile);
	WritePrivateProfileInt(KSession,_T("TransInputP"),byTransInput,pszIniFile);
	WritePrivateProfileInt(KSession,_T("GBKMODE"),nGbkMode,pszIniFile);
	WritePrivateProfileInt(KSession,_T("TTSInput"),bTTSInput,pszIniFile);
	WritePrivateProfileInt(KSession,_T("AutoInput"),bAutoInput,pszIniFile);
	WritePrivateProfileInt(KSession,_T("PYPhraseFirst"),bPYPhraseFirst,pszIniFile);
	WritePrivateProfileInt(KSession,_T("EnterClear"),bEnterClear,pszIniFile);
	WritePrivateProfileInt(KSession,_T("SoundAlert"),nSoundAlert,pszIniFile);
	WritePrivateProfileInt(KSession,_T("DisableFnKey"),bDisableFnKey,pszIniFile);
	WritePrivateProfileInt(KSession,_T("AutoDot"),bAutoDot,pszIniFile);
	WritePrivateProfileInt(KSession,_T("AutoPrompt"),bAutoPrompt,pszIniFile);
	WritePrivateProfileInt(KSession,_T("DisableDelWordCand"),bDisableDelWordCand,pszIniFile);
	WritePrivateProfileInt(KSession,_T("CandSelNoNum"),bCandSelNoNum,pszIniFile);
	WritePrivateProfileString(KSession,_T("WebHeader"),szWebHeader,pszIniFile);
	WritePrivateProfileString(KSession,_T("Plugin"),szPlugin,pszIniFile);
	WritePrivateProfileInt(KSession,_T("OnlySimpleCode"),bOnlySimpleCode,pszIniFile);

}

void CSettingsGlobal::Load(LPCTSTR pszIniFile)
{
	TCHAR szBuf[100];
	compMode = (COMPMODE)GetPrivateProfileInt(KSession,_T("CompMode"),IM_SHAPECODE,pszIniFile);
	compMode = IM_SHAPECODE;

	GetPrivateProfileString(KSession,_T("PhonticLeft"),_T("["),szPhonticLeft,50,pszIniFile);
	GetPrivateProfileString(KSession,_T("PhonticRight"),_T("]"),szPhonticRight,50,pszIniFile);
	byRateAdjust=GetPrivateProfileInt(KSession,_T("RateAdjust"),1,pszIniFile);
	b23CandKey=GetPrivateProfileInt(KSession,_T("23CandKey"),FALSE,pszIniFile);

	by2CandVK=GetPrivateProfileInt(KSession,_T("2CandVK"),VkKeyScan(';'),pszIniFile);
	by3CandVK=GetPrivateProfileInt(KSession,_T("3CandVK"),VkKeyScan('\''),pszIniFile);
	byTurnPageUpVK=GetPrivateProfileInt(KSession,_T("TurnPageUpVK"),VkKeyScan('-'),pszIniFile);
	byTurnPageDownVK=GetPrivateProfileInt(KSession,_T("TurnPageDownVK"),VkKeyScan('='),pszIniFile);

	byHotKeyQuery=GetPrivateProfileInt(KSession,_T("HotKey_Query"),VkKeyScan('/'),pszIniFile);
	byHotKeyMode=GetPrivateProfileInt(KSession,_T("HotKey_Switch_Mode"),VkKeyScan('q'),pszIniFile);	
	byHotKeyEn=GetPrivateProfileInt(KSession,_T("HotKey_Switch_En"),VkKeyScan('e'),pszIniFile);	
	byHotKeyMakeWord=GetPrivateProfileInt(KSession,_T("HotKey_MakeWord"),VkKeyScan('m'),pszIniFile);
	byHotKeyShowRoot=GetPrivateProfileInt(KSession,_T("HotKey_ShowRoot"),VkKeyScan('k'),pszIniFile);	
	byHotKeyHideStatus=GetPrivateProfileInt(KSession,_T("HotKey_HideStatus"),VkKeyScan('y'),pszIniFile);	


	byAstMode=GetPrivateProfileInt(KSession,_T("Associate"),AST_ENGLISH,pszIniFile);
	bAstSent=GetPrivateProfileInt(KSession,_T("SentAssociate"),1,pszIniFile);
	bySwitchKey=GetPrivateProfileInt(KSession,_T("SwitchKey"),0x36,pszIniFile);//��SHIFT
	byTempSpellKey=GetPrivateProfileInt(KSession,_T("TempSpellKey"),0xC1,pszIniFile);//��Ctrl
	GetPrivateProfileString(KSession,_T("LineKey1"),_T("g"),szBuf,2,pszIniFile);
	byLineKey[0]=szBuf[0];
	GetPrivateProfileString(KSession,_T("LineKey2"),_T("h"),szBuf,2,pszIniFile);
	byLineKey[1]=szBuf[0];
	GetPrivateProfileString(KSession,_T("LineKey3"),_T("t"),szBuf,2,pszIniFile);
	byLineKey[2]=szBuf[0];
	GetPrivateProfileString(KSession,_T("LineKey4"),_T("y"),szBuf,2,pszIniFile);
	byLineKey[3]=szBuf[0];
	GetPrivateProfileString(KSession,_T("LineKey5"),_T("n"),szBuf,2,pszIniFile);
	byLineKey[4]=szBuf[0];
	GetPrivateProfileString(KSession,_T("LineKey6"),_T("z"),szBuf,2,pszIniFile);
	byLineKey[5]=szBuf[0];
	byPntcRed=GetPrivateProfileInt(KSession,_T("ColorPhontic_Red"),0,pszIniFile);
	byPntcGreen=GetPrivateProfileInt(KSession,_T("ColorPhontic_Green"),0,pszIniFile);
	byPntcBlue=GetPrivateProfileInt(KSession,_T("ColorPhontic_Blue"),0,pszIniFile);
	byForecast=GetPrivateProfileInt(KSession,_T("Forecast"),MQC_FORECAST,pszIniFile);
	byTransStatus=GetPrivateProfileInt(KSession,_T("TransStatusP"),80,pszIniFile);
	if(byTransStatus<50) byTransStatus=50;
	if(byTransStatus>100) byTransStatus=100;
	byTransInput=GetPrivateProfileInt(KSession,_T("TransInputP"),80,pszIniFile);
	if(byTransInput<50) byTransInput=50;
	if(byTransInput>100) byTransInput=100;

	bShowOpTip=GetPrivateProfileInt(KSession,_T("ShowTip"),1,pszIniFile);
	bAutoMatch=GetPrivateProfileInt(KSession,_T("AutoMatch"),1,pszIniFile);
	nGbkMode=(GbkMode)GetPrivateProfileInt(KSession,_T("GBKMODE"),1,pszIniFile);
	bTTSInput=GetPrivateProfileInt(KSession,_T("TTSInput"),0,pszIniFile);
	bBlendUD=GetPrivateProfileInt(KSession,_T("BlendUD"),1,pszIniFile);
	bBlendSpWord=GetPrivateProfileInt(KSession,_T("BlendSpWord"),0,pszIniFile);
	bAutoInput=GetPrivateProfileInt(KSession,_T("AutoInput"),1,pszIniFile);

	bPYPhraseFirst=GetPrivateProfileInt(KSession,_T("PYPhraseFirst"),1,pszIniFile);
	bEnterClear=GetPrivateProfileInt(KSession,_T("EnterClear"),1,pszIniFile);
	nSoundAlert=GetPrivateProfileInt(KSession,_T("SoundAlert"),1,pszIniFile);

	bDisableFnKey=GetPrivateProfileInt(KSession,_T("DisableFnKey"),1,pszIniFile);
	bAutoDot=GetPrivateProfileInt(KSession,_T("AutoDot"),1,pszIniFile);
	bAutoPrompt=GetPrivateProfileInt(KSession,_T("AutoPrompt"),0,pszIniFile);

	bDisableDelWordCand=GetPrivateProfileInt(KSession,_T("DisableDelWordCand"),1,pszIniFile);
	bCandSelNoNum=GetPrivateProfileInt(KSession,_T("CandSelNoNum"),0,pszIniFile);

	GetPrivateProfileString(KSession,_T("WebHeader"),_T("www. http mail bbs. ftp:"),szWebHeader,100,pszIniFile);

	GetPrivateProfileString(KSession,_T("Plugin"),_T(""),szPlugin,100,pszIniFile);
	bOnlySimpleCode=GetPrivateProfileInt(KSession,_T("OnlySimpleCode"),0,pszIniFile);
}