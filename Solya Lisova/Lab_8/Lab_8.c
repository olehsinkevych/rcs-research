#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> 
//#include "stdafx.h"
#include <conio.h>
#include <Windows.h>



int main(int argc, char* argv[])
{
	printf("Device Configuration Of System\n\n");
	MEMORYSTATUS MemoryStatus;
	GlobalMemoryStatus(&MemoryStatus);
	printf("\nMemory Information:\n");
	printf("Physical memory in use: %d%%\n", MemoryStatus.dwMemoryLoad);
	printf("Total size of physical memory: %u\n", MemoryStatus.dwTotalPhys);
	printf("Available size of physical memory: %u\n", MemoryStatus.dwAvailPhys);
	printf("Total size of page file: %u\n", MemoryStatus.dwTotalPageFile);
	printf("Available size of page file: %u\n", MemoryStatus.dwAvailPageFile);
	printf("Total user virtual memory size: %u\n", MemoryStatus.dwTotalVirtual);
	printf("Available user virtual memory size: %u\n", MemoryStatus.dwAvailVirtual);
	//printf("\tDisplay devices:\n");
	/*DISPLAY_DEVICE DisplayDevice;
	DisplayDevice.cb = sizeof(DisplayDevice);
	for (UINT iIndex = 0; EnumDisplayDevices(NULL, iIndex, &DisplayDevice, 0); iIndex++)
	{
		*((char*)& DisplayDevice.StateFlags) = 0;
		printf("%s\n", DisplayDevice.DeviceString);
	}*/
	printf("\nKeyboard type:\n");
	switch (GetKeyboardType(0))
	{
	case 1:printf("IBM PC/XT or compatible (83-key) keyboard\n"); break;
	case 2:printf("Olivetti ICO (102 key) keyboard\n"); break;
	case 3:printf("IBM PC/AT (84 key) or similar\n"); break;
	case 4:printf("IBM enhanced (101 or 102 keys) keyboard\n"); break;
	case 5:printf("NOKIA 1050 or similar\n"); break;
	case 6:printf("NOKIA 9140 or similar\n"); break;
	case 7:printf("Japanese keyboard\n"); break;
	}
	HKEY BootKey;
	unsigned char Buffer[100];
	DWORD BufferSize = 100;
	ZeroMemory(Buffer, 100);
	/*if (!RegOpenKeyEx(HKEY_LOCAL_MACHINE, (LPCWSTR)"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\WOW\\boot.description", 0, KEY_QUERY_VALUE, &BootKey))
	{
		if (!RegQueryValueEx(BootKey, (LPCWSTR)"mouse.drv", NULL, NULL, Buffer, &BufferSize))
		{
			printf("\nMouse type:\n");
			printf("%s\n", Buffer);
		}
	}*/
	/*ZeroMemory(Buffer, 100);
	BufferSize = 100;*/
	/*if (!RegQueryValueEx(BootKey, (LPCWSTR)"display.drv", NULL, NULL, Buffer, &BufferSize))
	{
		printf("\nDisplay type:\n");
		printf("%s\n", Buffer);
	}*/
	/*ZeroMemory(Buffer, 100);
	BufferSize = 100;*/
	if (!RegOpenKeyEx(HKEY_LOCAL_MACHINE, (LPCWSTR)"HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", 0, KEY_QUERY_VALUE, &BootKey))
	{
		if (!RegQueryValueEx(BootKey, (LPCWSTR)"ProcessorNameString", NULL, NULL, Buffer, &BufferSize))
		{
			printf("\nProcessorName:\n");
			printf("%s\n", Buffer);
		}
	}

	printf("Press any key to exit\n");
	system("pause");
	return 0;

}