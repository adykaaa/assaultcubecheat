﻿// ReadingWritingMemoryCheat.cpp : Defines the entry point for the console application.
//All the memory addresses are from CheatEngine

#include "stdafx.h"
#include<iostream>
#include<Windows.h>

using namespace std;


int main()
{
	DWORD jatekosBase = 0;
	int golyoSzam = 50;
	int hpSzam = 1000;
	DWORD LocalPlayer = 0x509B74; 
	DWORD health = 0xF8; 


	HWND hwnd = FindWindowA(NULL, "AssaultCube");
	if (hwnd == NULL)
	{
		cout << "Nem talalom a megadott ablakot" << endl;
		Sleep(1500);
		exit(-1);
	}
	else
	{
		DWORD processID;
		GetWindowThreadProcessId(hwnd, &processID);
		HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);
		ReadProcessMemory(handle, (LPVOID)(LocalPlayer), &jatekosBase, sizeof(DWORD), 0);

		if (processID == NULL)
		{
			cout << "Nem talalom a megadott folyamatot" << endl;
		}
		else
		{
			while (1) {
				if (GetAsyncKeyState(VK_F1))
				{
					cout << "F1 megnyomasa utan loszer 50-re allitva" << endl;
					WriteProcessMemory(handle, (LPVOID)0x0285A440, &golyoSzam, sizeof(golyoSzam), 0);
					
				}
				if (GetAsyncKeyState(VK_F2))
				{
					hpSzam += 1000;
					Sleep(150);
					cout << "F2 megnyomasa utan HP 1000-re allitva" << endl;
					WriteProcessMemory(handle, (LPVOID)(jatekosBase + health), &hpSzam, sizeof(hpSzam), 0);
					
				}

			}
		}

		return 0;
	}
	
}
