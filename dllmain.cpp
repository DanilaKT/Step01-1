// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"
#include <aced.h>
#include <rxregsvc.h>

void initApp();
void unloadApp();
void helloWorld();

extern "C" AcRx::AppRetCode
acrxEntryPoint(AcRx::AppMsgCode msg, void* pkt)
{

    switch (msg)
    {


    case AcRx::kInitAppMsg:
        acrxDynamicLinker->unlockApplication(pkt);
        acrxRegisterAppMDIAware(pkt);
        initApp();
        break;
    case AcRx::kUnloadAppMsg:
        unloadApp();
        break;
    default:
        break;
    }

    return AcRx::kRetOK;

}

void initApp()
{

    acedRegCmds->addCommand(L"HELLOWORLD_COMMANDS", L"Hello", L"Bonjour", ACRX_CMD_TRANSPARENT, helloWorld);

}

void unloadApp()
{
    acedRegCmds->removeGroup(L"HELLOWORLD_COMMANDS");
}

void helloWorld()
{
    acutPrintf(L"\nHello World!");
}
