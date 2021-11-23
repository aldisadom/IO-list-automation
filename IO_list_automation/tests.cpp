#include "config.h"
#include "tests.h"
#include <fileapi.h>

#include <stdio.h>
#include <stdlib.h>
#include "MainWindow.h"
#include "Global_Functions.h"
#include <codecvt>
#include <locale>

struct Test_names_str
{	
	wstring Project_Design = L"Project-Design";
	wstring Project_Compare = L"Project-Compare";
	wstring Signals_Find_function = L"Signals-Find function";
	wstring Unique_Find_uniques = L"Uniques-Find uniques";
	wstring Uniques_Transfer_data_to_Signals = L"Uniques-Transfer data to Signals";
	wstring Declare_generate = L"Declare-generate";
	wstring Declare_adresses = L"Declare-adresses";
	wstring Instance_IO = L"Instance-IO";
	wstring Instance_Gen = L"Instance-Gen";
	wstring Instance_Scada_Gen = L"Scada-Gen";
};

Test_names_str Test_names;

void del_files_in_folder(wstring folder)
{
	WIN32_FIND_DATA ffd;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	wstring folder_in;

	folder.append(L"\\");
	folder_in = folder;
	folder.append(L"*");

	// Find the first file in the directory.

	hFind = FindFirstFile(folder.c_str(), &ffd);

	// List all the files in the directory with some info about them.
	wstring file_name;

	while (FindNextFile(hFind, &ffd) != 0)
	{
		file_name = folder_in;
		file_name.append(ffd.cFileName);
		remove(wstring_to_string(file_name).c_str());
	}
	FindClose(hFind);
}

void prep_test(wstring language, wstring test, wstring &test_name)
{
	test_name.append(language);
	test_name.append(L"_");
	test_name.append(test);

	wstring texts = L"*****Test";
	texts.append(error_separator);
	texts.append(test_name);
	texts.append(error_separator);
	texts.append(L"Started*****");
	info_write(texts);

	// clear all previous test data 

	TCHAR NPath[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, NPath);
	wstring del_path = NPath;
	del_path.append(L".\\Test data");

	del_files_in_folder(del_path);
}

int error_explane(int error_code, wstring &text)
{
	int save_nr=-1, dump_nr=-1;
	wstring add_text = L"";

	if ((error_code / 100000) < 1)
	{
		save_nr = (error_code / 10000) % 10;
		switch (save_nr)
		{
		case 0:	add_text = L".psave";
			break;
		case 1:	add_text = L".ssave";
			break;
		case 2:	add_text = L".osave";
			break;
		}
	}
	else
	{
		dump_nr = (error_code / 10000) % 10;
		switch (dump_nr)
		{
		case 0:	add_text = Dump_names.decl_AI;
			break;
		case 1:	add_text = Dump_names.decl_FC;
			break;
		case 2:	add_text = Dump_names.decl_HC;
			break;
		case 3:	add_text = Dump_names.decl_IO;
			break;
		case 4:	add_text = Dump_names.decl_Modules;
			break;
		case 5:	add_text = Dump_names.decl_MOT;
			break;
		case 6:	add_text = Dump_names.decl_PID;
			break;
		case 7:	add_text = Dump_names.decl_VLV;
			break;
		case 8:	add_text = Dump_names.inst_AI;
			break;
		case 9:	add_text = Dump_names.inst_FC;
			break;
		case 10:	add_text = Dump_names.inst_HC;
			break;
		case 11:	add_text = Dump_names.inst_MOT;
			break;
		case 12:	add_text = Dump_names.inst_PID;
			break;
		case 13:	add_text = Dump_names.inst_VLV;
			break;
		case 14:	add_text = Dump_names.scada_decl_AI;
			break;
		case 15:	add_text = Dump_names.scada_decl_FC;
			break;
		case 16:	add_text = Dump_names.scada_decl_HC;
			break;
		case 17:	add_text = Dump_names.scada_decl_MOT;
			break;
		case 18:	add_text = Dump_names.scada_decl_PID;
			break;
		case 19:	add_text = Dump_names.scada_decl_VLV;
			break;
		default: add_text = Dump_names.decl_AI;
			break;
		}
	}

	int line_nr = error_code  % 1000;
	int error_nr = (error_code % 10000)/1000;

	text = add_text;
	text.append(L"-");

	switch (error_nr)
	{
		case 1:	add_text = L"Missing ok test file";
			break;
		case 2:	add_text = L"Did not create test file";
			break;
		case 3:	add_text = L"Missmatch in line";
			break;
		case 4:	add_text = L"Test files lenght missmatch";
			break;
		default: add_text = Dump_names.decl_AI;
			break;
	}

	text.append(add_text);
	text.append(L"-");
	add_text = to_wstring(line_nr);
	text.append(add_text);

	return 0;
}

int Test_compare_files(wstring file_name_global)
{
	wstring file_name;
	wstring test_file_name;
	wstring dir_name = L".\\Test data\\";
	wstring extension = L".psave";

	for (int i = 0; i <= 2; i++)
	{
		switch (i)
		{
			case 0:	extension = L".psave";
				break;
			case 1:	extension = L".ssave";
				break;
			case 2:	extension = L".osave";
				break;
			default: extension = L".psave";
				break;
		}
		file_name = dir_name;
		file_name.append(L"CMP\\");
		file_name.append(file_name_global);
		file_name.append(extension);

		test_file_name = dir_name;
		test_file_name.append(L"_test");
		test_file_name.append(extension);

		//create file with UTF-8 encoding
		std::wifstream inFile(file_name);
		inFile.imbue(std::locale(inFile.getloc(), new std::codecvt_utf16<wchar_t, 0x10ffff, std::consume_header>));
		std::wifstream inTestFile(test_file_name);
		inTestFile.imbue(std::locale(inTestFile.getloc(), new std::codecvt_utf16<wchar_t, 0x10ffff, std::consume_header>));

		if ((!inFile) && (!inTestFile))
		{
			continue;
		}
		if ((!inFile) && (inTestFile))
		{
			inTestFile.close();
			return (i * 10 + 1) * 1000;
		}
		if ((inFile) && (!inTestFile))
		{
			inFile.close();
			return (i * 10 + 2) * 1000;
		}
		wstring inlines;
		wstring inTestlines;

		int rez1=0, rez2=0;
		int line = 0;
		while (std::getline(inFile, inlines) && std::getline(inTestFile, inTestlines))  // continue till end of file
		{
			line++;
			if (line != 3)	// line 3 is width of columns in save data, ignore compare them
			{
				if (inlines.empty())
				{
					inTestFile.close();
					inFile.close();
					return (i * 10 + 3) * 1000 + line;
				}
			}

			if (inlines.empty())
				rez1 = 0;
			else
				rez1 = 1;

			if (inTestlines.empty())
				rez2 = 0;
			else
				rez2 = 1;

			if((rez1 == 0) || (rez2 == 0))
				break;

		}
		if (((rez1 == 0) && (rez2 != 0)) || ((rez1 != 0) && (rez2 == 0)))
		{
			inTestFile.close();
			inFile.close();
			return (i * 10 + 4) * 1000;
		}
		inTestFile.close();
		inFile.close();
	}

	return 0;
}

int Test_compare_dump(wstring file_name_global)
{
	wstring file_name;
	wstring test_file_name;
	wstring dir_name = L".\\Test data\\";
	wstring extension = L".txt";

	for (int i = 0; i <= 19; i++)
	{
		switch (i)
		{
		case 0:	extension = Dump_names.decl_AI;
			break;
		case 1:	extension = Dump_names.decl_FC;
			break;
		case 2:	extension = Dump_names.decl_HC;
			break;
		case 3:	extension = Dump_names.decl_IO;
			break;
		case 4:	extension = Dump_names.decl_Modules;
			break;
		case 5:	extension = Dump_names.decl_MOT;
			break;
		case 6:	extension = Dump_names.decl_PID;
			break;
		case 7:	extension = Dump_names.decl_VLV;
			break;
		case 8:	extension = Dump_names.inst_AI;
			break;
		case 9:	extension = Dump_names.inst_FC;
			break;
		case 10:	extension = Dump_names.inst_HC;
			break;
		case 11:	extension = Dump_names.inst_MOT;
			break;
		case 12:	extension = Dump_names.inst_PID;
			break;
		case 13:	extension = Dump_names.inst_VLV;
			break;
		case 14:	extension = Dump_names.scada_decl_AI;
			break;
		case 15:	extension = Dump_names.scada_decl_FC;
			break;
		case 16:	extension = Dump_names.scada_decl_HC;
			break;
		case 17:	extension = Dump_names.scada_decl_MOT;
			break;
		case 18:	extension = Dump_names.scada_decl_PID;
			break;
		case 19:	extension = Dump_names.scada_decl_VLV;
			break;
		default: extension = Dump_names.decl_AI;
			break;
		}

		file_name = dir_name;
		file_name.append(L"CMP\\");
		file_name.append(L"dump_");
		file_name.append(file_name_global);
		file_name.append(L"_");
		file_name.append(extension);
		file_name.append(L".txt");

		test_file_name = dir_name;
		test_file_name.append(L"dump_");
		test_file_name.append(extension);
		test_file_name.append(L".txt");

		//create file with UTF-8 encoding
		std::wifstream inFile(file_name);
		inFile.imbue(std::locale(inFile.getloc(), new std::codecvt_utf16<wchar_t, 0x10ffff, std::consume_header>));
		std::wifstream inTestFile(test_file_name);
		inTestFile.imbue(std::locale(inTestFile.getloc(), new std::codecvt_utf16<wchar_t, 0x10ffff, std::consume_header>));

		if ((!inFile) && (!inTestFile))
		{
			continue;
		}
		if ((!inFile) && (inTestFile))
		{
			inTestFile.close();
			return (i * 10 + 1+900) * 1000;
		}
		if ((inFile) && (!inTestFile))
		{
			inFile.close();
			return (i * 10 + 2 + 900) * 1000;
		}

		wstring inlines;
		wstring inTestlines;

		int rez1 = 0, rez2 = 0;
		int line = 0;
		while (std::getline(inFile, inlines) && std::getline(inTestFile, inTestlines))  // continue till end of file
		{
			line++;
			
			if (inlines.empty())
				rez1 = 0;
			else
				rez1 = 1;

			if (inTestlines.empty())
				rez2 = 0;
			else
				rez2 = 1;

			if ((rez1 == 0) || (rez2 == 0))
				break;

		}
		if (((rez1 == 0) && (rez2 != 0)) || ((rez1 != 0) && (rez2 == 0)))
		{
			inTestFile.close();
			inFile.close();
			return (i * 10 + 4 + 900) * 1000;
		}
		inTestFile.close();
		inFile.close();
	}

	return 0;
}

int end_test(wstring test_name, bool dump_files)
{
	int ats;
	//compare test results
	if (dump_files == true)
	{
		ats = Test_compare_dump(test_name);
		if (ats == 0)
		{
			ats = Test_compare_files(test_name);
		}
	}
	else
		ats = Test_compare_files(test_name);

	wstring texts;

	if (ats != 0) // error occured
	{
		wstring error_text;
		error_explane(ats, error_text);

		texts = str.Error.test_fail.s[lang];
		texts.append(error_separator);
		texts.append(test_name);
		texts.append(error_separator);
		texts.append(error_text);
		texts.append(error_separator);
		texts.append(to_wstring(ats));

		err_write_show(texts);
		return 1;
	}
	texts = L"*****Test";
	texts.append(error_separator);
	texts.append(test_name);
	texts.append(error_separator);
	texts.append(L"Done*****");

	info_write(texts);

	return 0;
}

void Project_Design_test(wstring language, bool generate)
{
	wstring test = Test_names.Project_Design;

	wstring test_name;
	prep_test(language, test, test_name);


	//do test
	wstring test_file = L"Input_";
	test_file.append(language);

	Project_read_data(FALSE, test_file, project);
	Signals_get_data_design();

	wstring test_file_name = L"";
	if (generate == true)
	{
		test_file_name = L".\\Test data\\CMP\\";
		test_file_name.append(test_name);
	}
	else
		test_file_name = L".\\Test data\\CMP\\";
	//save test data
	Global_choose_save(Design_grid_index, false, test_file_name);
	Global_choose_save(Signals_grid_index, false, test_file_name);
//	Global_choose_save(Objects_grid_index, false, test_file_name);

	//compare test with function
	if (generate == false)
		end_test(test_name, true);
}

void Project_Design_compare(wstring language, bool generate)
{
	wstring test = Test_names.Project_Compare;
	wstring test_name;
	prep_test(language, test, test_name);

	//do test
	wstring test_file = L"Input_";
	test_file.append(language);
	Project_compare_data(test_file);

	wstring test_file_name = L"";
	if (generate == true)
	{
		test_file_name = L".\\Test data\\CMP\\";
		test_file_name.append(test_name);
	}
	else
		test_file_name = L".\\Test data\\_test";
	//save test data
	Global_choose_save(Design_grid_index, false, test_file_name);
	Global_choose_save(Signals_grid_index, false, test_file_name);
	//	Global_choose_save(Objects_grid_index, false, test_file_name);

	//compare test with function
	if (generate == false)
		end_test(test_name, true);
}

void Signals_Find_function_test(wstring language, bool generate)
{
	wstring test = Test_names.Signals_Find_function;
	wstring test_name;
	prep_test(language, test, test_name);

	//do test
	Signals_find_function();
	Signals_all_KKS_trim(true);

	wstring test_file_name = L"";
	if (generate == true)
	{
		test_file_name = L".\\Test data\\CMP\\";
		test_file_name.append(test_name);
	}
	else
		test_file_name = L".\\Test data\\_test";
	//save test data
	Global_choose_save(Design_grid_index, false, test_file_name);
	Global_choose_save(Signals_grid_index, false, test_file_name);
	//	Global_choose_save(Objects_grid_index, false, test_file_name);

	//compare test with function
	if (generate == false)
		end_test(test_name, true);
}


void Uniques_find_test(wstring language, bool generate)
{
	wstring test = Test_names.Unique_Find_uniques;
	wstring test_name;
	prep_test(language, test, test_name);
	//do test
	if (Objects_find_uniques() == 0)
	{
		if (Objects_find_objects() == 0)
		{
			if (Objects_find_operatyv() == 0)
			{

			}
		}		
	}

	wstring test_file_name = L"";
	if (generate == true)
	{
		test_file_name = L".\\Test data\\CMP\\";
		test_file_name.append(test_name);
	}
	else
		test_file_name = L".\\Test data\\_test";
	//save test data
	Global_choose_save(Design_grid_index, false, test_file_name);
	Global_choose_save(Signals_grid_index, false, test_file_name);
	Global_choose_save(Objects_grid_index, false, test_file_name);

	//compare test with function
	if (generate == false)
		end_test(test_name, true);
	
}

void Uniques_transfer_sig_test(wstring language, bool generate)
{
	wstring test = Test_names.Uniques_Transfer_data_to_Signals;
	wstring test_name;
	prep_test(language, test, test_name);

	//do test
	Objects_transfer_to_signals(true);

	wstring test_file_name = L"";
	if (generate == true)
	{
		test_file_name = L".\\Test data\\CMP\\";
		test_file_name.append(test_name);
	}
	else
		test_file_name = L".\\Test data\\_test";
	//save test data
	Global_choose_save(Design_grid_index, false, test_file_name);
	Global_choose_save(Signals_grid_index, false, test_file_name);
	Global_choose_save(Objects_grid_index, false, test_file_name);

	//compare test with function
	if (generate == false)
		end_test(test_name, true);

}

void Declare_generate_test(wstring language, bool generate)
{
	wstring test = Test_names.Declare_generate;
	wstring test_name = Global_get_CPU_name(parameters.CPU);
	test_name.append(L"_");
	test_name.append(test);

	test = test_name;
	prep_test(language, test, test_name);

	//do test

	Declare_addreses(true);

	wstring test_file_name = L"";
	if (generate == true)
	{
		test_file_name = L".\\Test data\\CMP\\";
		test_file_name.append(test_name);
	}
	else
		test_file_name = L".\\Test data\\_test";
	//save test data
//	Global_choose_save(Design_grid_index, false, test_file_name);
//	Global_choose_save(Signals_grid_index, false, test_file_name);
	Global_choose_save(Objects_grid_index, false, test_file_name);

	//compare test with function
	if (generate == false)
		end_test(test_name, true);
}

void Declare_adressing_test(wstring language, bool generate)
{
	wstring test = Test_names.Declare_adresses;

	wstring test_name = Global_get_CPU_name(parameters.CPU);
	test_name.append(L"_");
	test_name.append(test);
	test = test_name;

	prep_test(language, test, test_name);

	//do test
	if (generate == true)
		Declare_put_adres_grid(true, test_name);
	else
		Declare_put_adres_grid(true, L" ");


	wstring test_file_name = L"";
	if (generate == true)
	{
		test_file_name = L".\\Test data\\CMP\\";
		test_file_name.append(test_name);
	}
	else
		test_file_name = L".\\Test data\\_test";
	//save test data
	//	Global_choose_save(Design_grid_index, false, test_file_name);
	//	Global_choose_save(Signals_grid_index, false, test_file_name);
	Global_choose_save(Objects_grid_index, false, test_file_name);

	//compare test with function
	if (generate == false)
		end_test(test_name, true);
}

void Instance_IO_test(wstring language, bool generate)
{
	wstring test = Test_names.Instance_IO;

	wstring test_name = Global_get_CPU_name(parameters.CPU);
	test_name.append(L"_");
	test_name.append(test);

	test = test_name;

	prep_test(language, test, test_name);

	//do test

	if (IO_generate() == 0)
	{
		if (generate == true)
		{
			if (IO_show(true, test_name) == 0)
			{
			}
		}
		else
		{
			if (IO_show(true, L" ") == 0)
			{
			}
		}
	}

	wstring test_file_name = L"";
	if (generate == true)
	{
		test_file_name = L".\\Test data\\CMP\\";
		test_file_name.append(test_name);
	}
	else
		test_file_name = L".\\Test data\\_test";

	//save test data
//	Global_choose_save(Design_grid_index, false, test_file_name);
	Global_choose_save(Signals_grid_index, false, test_file_name);
//	Global_choose_save(Objects_grid_index, false, test_file_name);

	//compare test with function
	if (generate == false)
		end_test(test_name, true);
}

void Instance_Gen_test(wstring language,bool generate)
{
	wstring test = Test_names.Instance_Gen;
	wstring test_name = Global_get_CPU_name(parameters.CPU);
	test_name.append(L"_");
	test_name.append(test);

	test = test_name;

	prep_test(language, test, test_name);

	//do test
	if (generate == true)
		Instance_gen(true, test_name);
	else
		Instance_gen(true, L" ");

	wstring test_file_name = L"";
	if (generate == true)
	{
		test_file_name = L".\\Test data\\CMP\\";
		test_file_name.append(test_name);
	}
	else
		test_file_name = L".\\Test data\\_test";

	//save test data
//	Global_choose_save(Design_grid_index, false, test_file_name);
	Global_choose_save(Signals_grid_index, false, test_file_name);
//	Global_choose_save(Objects_grid_index, false, test_file_name);

	//compare test with function
	if (generate == false)
		end_test(test_name,true);
}

void Instance_scada_gen_test(wstring language, bool generate)
{
	wstring test = Test_names.Instance_Scada_Gen;
	wstring test_name = Global_get_CPU_name(parameters.CPU);
	test_name.append(L"+");
	test_name.append(Global_get_scada_name(parameters.SCADA));
	test_name.append(L"_");
	test_name.append(test);

	test = test_name;

	prep_test(language, test, test_name);


	//do test
	if (generate == true)
		Instance_scada_gen(true, test_name);
	else
		Instance_scada_gen(true, L" ");

	wstring test_file_name = L"";
	if (generate == true)
	{
		test_file_name = L".\\Test data\\CMP\\";
		test_file_name.append(test_name);
	}
	else
		test_file_name = L".\\Test data\\_test";

	//save test data
//	Global_choose_save(Design_grid_index, false, test_file_name);
//	Global_choose_save(Signals_grid_index, false, test_file_name);
	//	Global_choose_save(Objects_grid_index, false, test_file_name);

		//compare test with function
	if (generate == false)
		end_test(test_name, true);
}

void Test_All(bool generate)
{
	wstring language;	
	
	for (int i = 0; i <= 3; i++)
	{
		if (i == EN_index || i == LV_index || i == RU_index)
			continue;

		switch (i)
		{
		case 0: language = L"LT";
			break;
		case 1: language = L"EN";
			break;
		case 2: language = L"LV";
			break;
		case 3: language = L"RU";
			break;
		default:
			language = L"LT";
		}

		cfg_reads(&parameters, language);
		parameters.Language = i;

		wstring texts = L"*****Test";
		texts.append(error_separator);
		texts.append(language);
		texts.append(error_separator);
		texts.append(L"Started*****");
		info_write(texts);

		Global_delete_all_data(Design_grid_index);
		Global_delete_all_data(Signals_grid_index);
		Global_delete_all_data(Objects_grid_index);

		Global_put_data_listview(Design_grid_index, project.valid_entries, project.number_collums, project.column_name_EN, project.column_name_LT, project.collumn_with);
		Global_put_data_listview(Signals_grid_index, signals.valid_entries, signals.number_collums, signals.column_name_EN, signals.column_name_LT, signals.collumn_with);
		Global_put_data_listview(Objects_grid_index, objects.valid_entries, objects.number_collums, objects.column_name_EN, objects.column_name_LT, objects.collumn_with);



		Project_Design_test(language, generate);


		Signals_Find_function_test(language, generate);
		Uniques_find_test(language, generate);
		Uniques_transfer_sig_test(language, generate);
		Project_Design_compare(language, generate);
		
		for (int j = 0; j <= Max_cpu_nr; j++)
		{
			parameters.CPU = j;

			if (  j == Schneider_index)
				continue;		

			Declare_generate_test(language, generate);
			Declare_adressing_test(language, generate);
			Instance_IO_test(language, generate);
			Instance_Gen_test(language, generate);

			for (int z = 0; z <= Max_scada_nr; z++)
			{
				parameters.SCADA = z;

				if ( z == WinCC_index || j == ABB_800xA_index)
					continue;

				Instance_scada_gen_test(language, generate);
			}
		}
		texts = L"*****Test";
		texts.append(error_separator);
		texts.append(language);
		texts.append(error_separator);
		texts.append(L"Finished*****");
		info_write(texts);
	}

	cfg_reads(&parameters, L" ");


}


void Generate_Test_All()
{
	wstring texts = L"*****Test generation started***********";
	info_write(texts);

	TCHAR NPath[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, NPath);
	wstring del_path = NPath;
	del_path.append(L".\\Test data\\CMP");

	del_files_in_folder(del_path);

	Test_All(true);
	texts = L"*****Test generation finished***********";
	info_write(texts);
}