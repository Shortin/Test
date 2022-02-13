#ifndef UNICODE
#define UNICODE
#endif
#pragma comment(lib, "netapi32.lib")

#include "pch.h" 
#include "UsersData.h"
#include <iostream>
#include <windows.h> 
#include<string>
#include <lm.h>
#include <algorithm>

int datausers(char* data)
{
    std::string str = data;
    std::wstring data1;
    std::wstring tmp;
    tmp.resize(str.size());
    std::transform(str.begin(), str.end(), tmp.begin(), btowc);
    tmp.swap(data1);

    LPUSER_INFO_0 pBuf = NULL;
    LPUSER_INFO_0 pTmpBuf;
    DWORD dwLevel = 0;
    DWORD dwPrefMaxLen = MAX_PREFERRED_LENGTH;
    DWORD dwEntriesRead = 0;
    DWORD dwTotalEntries = 0;
    DWORD dwResumeHandle = 0;
    DWORD dwTotalCount = 0;
    NET_API_STATUS nStatus;
    LPTSTR pszServerName = NULL;

    nStatus = NetUserEnum((LPCWSTR)pszServerName,
        dwLevel,
        FILTER_NORMAL_ACCOUNT, // global users
        (LPBYTE*)&pBuf,
        dwPrefMaxLen,
        &dwEntriesRead,
        &dwTotalEntries,
        &dwResumeHandle);
    if ((pTmpBuf = pBuf) != NULL)
    {
        for (int i = 0; (i < dwEntriesRead); i++)
        {

            if (pTmpBuf == NULL)
            {
                break;
            }
            if (data1 == pTmpBuf->usri0_name)
                return 1;
            pTmpBuf= 1+ pTmpBuf;
        }
    }
    if (pBuf != NULL)
    {
        NetApiBufferFree(pBuf);
        pBuf = NULL;
    }
    if (pBuf != NULL)
        NetApiBufferFree(pBuf);
    return 0;
}


