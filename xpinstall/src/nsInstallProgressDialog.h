/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/*
 * The contents of this file are subject to the Netscape Public License
 * Version 1.0 (the "License"); you may not use this file except in
 * compliance with the License.  You may obtain a copy of the License at
 * http://www.mozilla.org/NPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is Mozilla Communicator client code, 
 * released March 31, 1998. 
 *
 * The Initial Developer of the Original Code is Netscape Communications 
 * Corporation.  Portions created by Netscape are 
 * Copyright (C) 1998 Netscape Communications Corporation.  All Rights
 * Reserved.
 *
 * Contributors:
 *     Douglas Turner <dougt@netscape.com>
 */
#ifndef __nsInstallProgressDialog_h__
#define __nsInstallProgressDialog_h__

#include "nscore.h"
#include "nsIXPINotifier.h"
#include "nsIXPIProgressDlg.h"
#include "nsISupports.h"
#include "nsISupportsUtils.h"

#include "nsCOMPtr.h"

#include "nsIWebShell.h"
#include "nsIWebShellWindow.h"
#include "nsIXULWindowCallbacks.h"    

#include "nsIDocument.h"
#include "nsIDOMXULDocument.h"


class nsInstallProgressDialog : public nsIXPINotifier,
                                public nsIXULWindowCallbacks, 
                                public nsIXPIProgressDlg
{
    public: 

        nsInstallProgressDialog(nsIXULWindowCallbacks* aManager);
        virtual ~nsInstallProgressDialog();
        
        NS_DECL_ISUPPORTS

        // implement nsIXPINotifier  
        NS_IMETHOD BeforeJavascriptEvaluation(const PRUnichar *URL);
        NS_IMETHOD AfterJavascriptEvaluation(const PRUnichar *URL);
        NS_IMETHOD InstallStarted(const PRUnichar *URL, const PRUnichar* UIPackageName);
        NS_IMETHOD ItemScheduled(const PRUnichar *message);
        NS_IMETHOD FinalizeProgress(const PRUnichar *message, PRInt32 itemNum, PRInt32 totNum);
        NS_IMETHOD FinalStatus(const PRUnichar* URL, PRInt32 status);
        NS_IMETHOD LogComment(const PRUnichar* comment);

        // implement nsIXPIProgressDlg
        NS_IMETHOD Open();
        NS_IMETHOD Close();
        NS_IMETHOD SetTitle(const PRUnichar * aTitle);
        NS_IMETHOD SetHeading(const PRUnichar * aHeading);
        NS_IMETHOD SetActionText(const PRUnichar * aActionText);
        NS_IMETHOD SetProgress(PRInt32 aValue, PRInt32 aMax);
        NS_IMETHOD GetCancelStatus(PRBool *_retval);

        // Declare implementations of nsIXULWindowCallbacks interface functions.
        NS_IMETHOD ConstructBeforeJavaScript(nsIWebShell *aWebShell);
        NS_IMETHOD ConstructAfterJavaScript(nsIWebShell *aWebShell);

    protected:
        nsresult setDlgAttribute(const char *id, const char *name, const nsString &value);
        nsresult getDlgAttribute(const char *id, const char *name, nsString &value);

    private:
        nsIXULWindowCallbacks*       mManager;
        nsCOMPtr<nsIDOMXULDocument>  mDocument;		// why is this owned?
        nsCOMPtr<nsIWebShellWindow>  mWindow;			// why is this owned?
};
#endif
