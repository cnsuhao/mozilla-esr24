/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 *
 * The contents of this file are subject to the Netscape Public License
 * Version 1.0 (the "NPL"); you may not use this file except in
 * compliance with the NPL.  You may obtain a copy of the NPL at
 * http://www.mozilla.org/NPL/
 *
 * Software distributed under the NPL is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the NPL
 * for the specific language governing rights and limitations under the
 * NPL.
 *
 * The Initial Developer of this code under the NPL is Netscape
 * Communications Corporation.  Portions created by Netscape are
 * Copyright (C) 1999 Netscape Communications Corporation.  All Rights
 * Reserved.
 */
#ifndef nsIStringCharsetDetector_h__
#define nsIStringCharsetDetector_h__

#include "nsISupports.h"
#include "nsString.h"
#include "nsDetectionConfident.h"

// {12BB8F15-2389-11d3-B3BF-00805F8A6670}
#define NS_ISTRINGCHARSETDETECTOR_IID \
{ 0x12bb8f15, 0x2389, 0x11d3, { 0xb3, 0xbf, 0x0, 0x80, 0x5f, 0x8a, 0x66, 0x70 } }
/*
  This interface is similar to nsICharsetDetector
  The difference is it is for line base detection instead of block based 
  detectection. 
 */


class nsIStringCharsetDetector : public nsISupports {
public:  

   NS_DEFINE_STATIC_IID_ACCESSOR(NS_ISTRINGCHARSETDETECTOR_IID)
  /*
     Perform the charset detection
    
     aBytesArray- the bytes
     aLen- the length of the bytes
     oCharset- the charset answer
     oConfident - the confidence of the answer
   */
  NS_IMETHOD DoIt(const char* aBytesArray, PRUint32 aLen, 
                    const char** oCharset, nsDetectionConfident &oConfident) = 0;
};
#endif /* nsIStringCharsetDetector_h__ */
