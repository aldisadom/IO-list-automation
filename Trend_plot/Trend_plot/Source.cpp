#include "matplotlibcpp.h"
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include<iostream>

#include<fstream>
#include<sstream>
#include <string>
#include <filesystem>
#include <wchar.h>
#include <codecvt>

#include <windows.h>
#include <conio.h>
#include <tchar.h>
#pragma comment(lib, "user32.lib")

#define separator (L"☣")
#define Py_USING_UNICODE

namespace plt = matplotlibcpp;
using namespace std;

HANDLE hMapFile_out;
LPCTSTR pBuf_out;

HANDLE hMapFile_in;
LPCTSTR pBuf_in;
#define info_separator L" - "
int lang = 0;

struct Strings_str
{
	wstring s[4] = { L"", L"",L"",L"", };
};

struct Strings_error_str
{

	Strings_str Create_memory_map_obj;
	Strings_str Create_memory_map_view;
	Strings_str Open_memory_map_view;
};

struct Strings_all_str
{
	Strings_error_str Error;
};

Strings_all_str str;

void err_write_show(wstring texts)
{

}

int create_shared_memmory(wstring name, DWORD buff_size)
{
	wstring texts;

	hMapFile_out = CreateFileMapping(
		INVALID_HANDLE_VALUE,    // use paging file
		NULL,                    // default security
		PAGE_READWRITE,          // read/write access
		0,                       // maximum object size (high-order DWORD)
		buff_size,                // maximum object size (low-order DWORD)
		name.c_str());                 // name of mapping object

	if (hMapFile_out == NULL)
	{
		texts = str.Error.Create_memory_map_obj.s[lang];
		texts.append(info_separator);
		texts.append(name);
		err_write_show(texts);
		return 1;
	}
	pBuf_out = (LPTSTR)MapViewOfFile(hMapFile_out,   // handle to map object
		FILE_MAP_ALL_ACCESS, // read/write permission
		0,
		0,
		buff_size);

	if (pBuf_out == NULL)
	{
		texts = str.Error.Create_memory_map_view.s[lang];
		texts.append(info_separator);
		texts.append(name);
		err_write_show(texts);

		CloseHandle(hMapFile_out);
		return 1;
	}

//	LPWSTR szMsg = L"asdfghjkl 123456789";
//	CopyMemory((PVOID)pBuf_out, szMsg, (_tcslen(szMsg) * sizeof(TCHAR)));

	return 0;
}

int read_shared_memory(wstring name, DWORD buff_size)
{
	wstring texts;

	hMapFile_in = OpenFileMapping(
		FILE_MAP_ALL_ACCESS,   // read/write access
		FALSE,                 // do not inherit the name
		name.c_str());               // name of mapping object

	if (hMapFile_in == NULL)
	{
		texts = str.Error.Open_memory_map_view.s[lang];
		texts.append(info_separator);
		texts.append(name);
		err_write_show(texts);
		return 1;
	}

	pBuf_in = (LPTSTR)MapViewOfFile(hMapFile_in, // handle to map object
		FILE_MAP_ALL_ACCESS,  // read/write permission
		0,
		0,
		buff_size);

	if (pBuf_in == NULL)
	{
		texts = str.Error.Create_memory_map_view.s[lang];
		texts.append(info_separator);
		texts.append(name);
		err_write_show(texts);

		CloseHandle(hMapFile_in);

		return 1;
	}

	return 0;
}

void clear_shared_memmory()
{
	UnmapViewOfFile(pBuf_in);
	CloseHandle(hMapFile_in);

	UnmapViewOfFile(pBuf_out);
	CloseHandle(hMapFile_out);
}

int main() 
{
	int n = 0;
	vector<double> time(n), x1(n), y1(n), x2(n), y2(n);
	bool n1_plot = false, n2_plot = false, n3_plot = false, n4_plot = false, n5_plot = false;
	double n1, n2, n3,n4,n5;


	wstring file_name;
	wstring cell_text;

	file_name = L"_plot.txt";

	std::wstring lines;
	std::wifstream file_in(file_name);

	file_in.imbue(std::locale(file_in.getloc(), new std::codecvt_utf16<wchar_t, 0x10ffff, std::consume_header>));

	//create file with UTF-8 encoding
	if (!file_in)
	{
		return 1;
	}

	int iCol = 0;
	int index = 0;
	
	int separator_loc = 0;

	while (std::getline(file_in, lines))
	{
		iCol = 0;

		separator_loc = lines.find(separator);

		if (separator_loc < 0)
		{
			iCol = 0;
			break;
		}

		while (!lines.empty() && lines.compare(L"\n") != 0 && lines.compare(L"\r\n") != 0 && lines.compare(L"\r") != 0)
		{
			cell_text = lines.substr(0, separator_loc);
			lines = lines.substr(separator_loc + 1);
			separator_loc = lines.find(separator);

			
			switch (iCol)
			{
			case 0:	n1 = stod (cell_text);
					n1_plot = true;
				break;
			case 1: n2 = stod(cell_text);
					n2_plot = true;
				break;
			case 2: n3= stod(cell_text);
					n3_plot = true;
				break;
			case 3: n4 = stod(cell_text);
					n4_plot = true;
				break;
			case 5: n5 = stod(cell_text);
					n5_plot = true;
				break;
			}
			
			if (separator_loc < 0)
				break;
			iCol++;
		}

		index++;
		time.resize(index);
		x1.resize(index);
		y1.resize(index);
		x2.resize(index);
		y2.resize(index);


		time[index-1] = n1;
		x1[index-1] = n2;
		y1[index-1] = n3;
		x2[index-1] = n4;
		y2[index-1] = n5;
		
	}
	file_in.close();

	read_shared_memory(L"IO-automationas_out", 255);
	Py_Initialize();

	plt::figure(); // declare a new figure (optional if only one is used)

	if (n1_plot == false)
	{
		return 1;
	}

	if (n2_plot == true)
		plt::plot(time, x1, { {"label", "x1"} });
	if (n3_plot == true)
	plt::plot(time, y1, { {"label", "y1"} }); 
	if (n4_plot == true)
		plt::plot(time, x2, { {"label", "x2"} }); 
	if (n5_plot == true)
		plt::plot(time, y2, { {"label", "y2"} });

//	plt::xlim(0, 1000 * 1000);    // x-axis interval: [0, 1e6]
	plt::title("Standard usage"); // set a title
	plt::legend();                // enable the legend

	plt::show();

	clear_shared_memmory();
	return 0;
}