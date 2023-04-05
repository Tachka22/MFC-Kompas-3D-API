
// MFCAppKompas.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMFCAppKompasApp:
// Сведения о реализации этого класса: MFCAppKompas.cpp
//

class CMFCAppKompasApp : public CWinApp
{
public:
	CMFCAppKompasApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CMFCAppKompasApp theApp;
