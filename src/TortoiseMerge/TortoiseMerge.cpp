// TortoiseMerge - a Diff/Patch program

// Copyright (C) 2004 - Stefan Kueng

// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//
#include "stdafx.h"
#include "TortoiseMerge.h"
#include "MainFrm.h"
#include "AboutDlg.h"
#include "CmdLineParser.h"
#include "version.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


BEGIN_MESSAGE_MAP(CTortoiseMergeApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
END_MESSAGE_MAP()


CTortoiseMergeApp::CTortoiseMergeApp()
{
	EnableHtmlHelp();
}

// The one and only CTortoiseMergeApp object
CTortoiseMergeApp theApp;
CCrashReport g_crasher("steveking@gmx.ch", "Crashreport for TortoiseMerge");

// CTortoiseMergeApp initialization
BOOL CTortoiseMergeApp::InitInstance()
{
	//set the resource dll for the required language
	CRegDWORD loc = CRegDWORD(_T("Software\\TortoiseMerge\\LanguageID"), 1033);
	long langId = loc;
	CString langDll;
	HINSTANCE hInst = NULL;
	do
	{
		langDll.Format(_T("Languages\\TortoiseMerge%d.dll"), langId);
		
		hInst = LoadLibrary(langDll);
		if (CUtils::GetVersionFromFile(langDll).Compare(_T(STRPRODUCTVER_INCVERSION))!=0)
		{
			FreeLibrary(hInst);
			hInst = NULL;
		}
		if (hInst != NULL)
			AfxSetResourceHandle(hInst);
		else
		{
			DWORD lid = SUBLANGID(langId);
			lid--;
			if (lid > 0)
			{
				langId = MAKELANGID(PRIMARYLANGID(langId), lid);
			}
			else
				langId = 0;
		}
	} while ((hInst == NULL) && (langId != 0));

	// InitCommonControls() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	InitCommonControls();

	CWinApp::InitInstance();

	CCmdLineParser parser = CCmdLineParser(this->m_lpCmdLine);

	if (parser.HasKey(_T("?")) || parser.HasKey(_T("help")))
	{
		CString sHelpText;
		sHelpText.LoadString(IDS_COMMANDLINEHELP);
		MessageBox(NULL, sHelpText, _T("TortoiseMerge"), MB_ICONINFORMATION);
		return FALSE;
	} // if (parser.HasKey(_T("?")) || parser.HasKey(_T("help"))) 

	// Initialize OLE libraries
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}
	AfxEnableControlContainer();
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	SetRegistryKey(_T("TortoiseMerge"));
	// To create the main window, this code creates a new frame window
	// object and then sets it as the application's main window object
	CMainFrame* pFrame = new CMainFrame;
	if (!pFrame)
		return FALSE;
	m_pMainWnd = pFrame;
	// create and load the frame with its resources
	pFrame->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, NULL,
		NULL);

	// Fill in the command line options
	pFrame->m_Data.m_sBaseFile = parser.GetVal(_T("base"));
	pFrame->m_Data.m_sTheirFile = parser.GetVal(_T("theirs"));
	pFrame->m_Data.m_sYourFile = parser.GetVal(_T("yours"));
	pFrame->m_Data.m_sMergedFile = parser.GetVal(_T("merged"));
	pFrame->m_Data.m_sPatchPath = parser.GetVal(_T("patchpath"));
	pFrame->m_Data.m_sDiffFile = parser.GetVal(_T("diff"));
	if (parser.HasKey(_T("oneway")))
        pFrame->m_bOneWay = TRUE;
	if (!pFrame->m_Data.m_sBaseFile.IsEmpty() && pFrame->m_Data.m_sYourFile.IsEmpty() && !pFrame->m_Data.m_sTheirFile.IsEmpty())
	{
		pFrame->m_Data.m_sYourFile = pFrame->m_Data.m_sTheirFile;
		pFrame->m_Data.m_sTheirFile.Empty();
	}

	if ((parser.HasKey(_T("patchpath")))&&(!parser.HasVal(_T("diff"))))
	{
		// A path was given for applying a patchfile, but
		// the patchfile itself was not.
		// So ask the user for that patchfile

		OPENFILENAME ofn;		// common dialog box structure
		TCHAR szFile[MAX_PATH];  // buffer for file name
		ZeroMemory(szFile, sizeof(szFile));
		// Initialize OPENFILENAME
		ZeroMemory(&ofn, sizeof(OPENFILENAME));
		//ofn.lStructSize = sizeof(OPENFILENAME);
		ofn.lStructSize = OPENFILENAME_SIZE_VERSION_400;		//to stay compatible with NT4
		ofn.hwndOwner = pFrame->m_hWnd;
		ofn.lpstrFile = szFile;
		ofn.nMaxFile = sizeof(szFile)/sizeof(TCHAR);
		CString temp;
		temp.LoadString(IDS_OPENDIFFFILETITLE);
		if (temp.IsEmpty())
			ofn.lpstrTitle = NULL;
		else
			ofn.lpstrTitle = temp;
		ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;

		// Display the Open dialog box. 
		CString tempfile;
		if (GetOpenFileName(&ofn)==FALSE)
		{
			return FALSE;
		}
		pFrame->m_Data.m_sDiffFile = ofn.lpstrFile;
	} // if ((parser.HasKey(_T("patchpath")))&&(!parser.HasVal(_T("diff")))) 

	// The one and only window has been initialized, so show and update it
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	if (pFrame->m_Data.m_sBaseFile.IsEmpty() && pFrame->m_Data.m_sPatchPath.IsEmpty())
	{
		pFrame->OnFileOpen();
	}
	return pFrame->LoadViews();
}

// CTortoiseMergeApp message handlers

void CTortoiseMergeApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}
