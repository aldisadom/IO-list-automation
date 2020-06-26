#include "config.h"
#include "tests.h"

#include <stdio.h>
#include <stdlib.h>
#include "MainWindow.h"
#include "Global_Functions.h"

void prep_test(char* language, char* test, char* test_name, int size_test_name)
{
//	char test_name[255];
	int a = sizeof test_name;

	strcpy_s(test_name, size_test_name, language);
	strcat_s(test_name, size_test_name, "_");
	strcat_s(test_name, size_test_name, test);

	strcpy_s(info_txt, sizeof info_txt, "*****Test");
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, test_name);
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, "Started*****");
	info_write(info_txt);

	// clear all previous test data 
	remove(".\\Test data\\_test.psave");
	remove(".\\Test data\\_test.ssave");
	remove(".\\Test data\\_test.osave");

	remove(".\\Test data\\_test_dump_AI.txt");
	remove(".\\Test data\\_test_dump_HC.txt");
	remove(".\\Test data\\_test_dump_MOT.txt");
	remove(".\\Test data\\_test_dump_VLV.txt");
	remove(".\\Test data\\_test_dump_FC.txt");
	remove(".\\Test data\\_test_dump_PID.txt");
	remove(".\\Test data\\_test_dump_SCADA.txt");

	remove(".\\Test data\\_test_dump_IO.txt");
	remove(".\\Test data\\_test_dump_Modules.txt");

}

int error_explane(int error_code, char* text, int size_text)
{
	int save_nr=-1, dump_nr=-1;
	char add_text[100] = "";

	if ((error_code / 100000) < 1)
	{
		save_nr = (error_code / 10000) % 10;
		switch (save_nr)
		{
		case 0:	strcpy_s(add_text, sizeof add_text, ".psave");
			break;
		case 1:	strcpy_s(add_text, sizeof add_text, ".ssave");
			break;
		case 2:	strcpy_s(add_text, sizeof add_text, ".osave");
			break;
		}
	}
	else
	{
		dump_nr = (error_code / 10000) % 10;
		switch (dump_nr)
		{
		case 0:	strcpy_s(add_text, sizeof add_text, "Dump_AI");
			break;
		case 1:	strcpy_s(add_text, sizeof add_text, "Dump_FC");
			break;
		case 2:	strcpy_s(add_text, sizeof add_text, "Dump_HC");
			break;
		case 3:	strcpy_s(add_text, sizeof add_text, "Dump_MOT");
			break;
		case 4:	strcpy_s(add_text, sizeof add_text, "Dump_PID");
			break;
		case 5:	strcpy_s(add_text, sizeof add_text, "Dump_VLV");
			break;
		case 6:	strcpy_s(add_text, sizeof add_text, "Dump_SCADA");
			break;
		case 7:	strcpy_s(add_text, sizeof add_text, "Dump_IO");
			break;
		case 8:	strcpy_s(add_text, sizeof add_text, "Dump_Module");
			break;
		}
	}

	int line_nr = error_code  % 1000;
	int error_nr = (error_code % 10000)/1000;

	strcpy_s(text, size_text, add_text);
	strcat_s(text, size_text, "-");

	strcpy_s(add_text, sizeof add_text, "");

	switch (error_nr)
	{
		case 1:	strcpy_s(add_text, sizeof add_text, "Missing ok test file");
			break;
		case 2:	strcpy_s(add_text, sizeof add_text, "Did not create test file"); 
			break;
		case 3:	strcpy_s(add_text, sizeof add_text, "Missmatch in line"); 
			break;
		case 4:	strcpy_s(add_text, sizeof add_text, "Test files lenght missmatch");
			break;
	}

	strcat_s(text, size_text, add_text);
	strcat_s(text, size_text, "-");
	
	
	_itoa_s(line_nr, add_text, 10);
	strcat_s(text, size_text, add_text);

	return 0;
}

int Test_compare_files(string file_name_global)
{
	FILE* inFile;
	FILE* inTestFile;
	string file_name;
	string test_file_name;
	string dir_name = ".\\Test data\\";
	string extension = ".psave";

	for (int i = 0; i <= 2; i++)
	{
		switch (i)
		{
			case 0:	extension = ".psave";
				break;
			case 1:	extension = ".ssave";
				break;
			case 2:	extension = ".osave";
				break;
			default: extension = ".psave";
				break;
		}
		file_name = dir_name;
		file_name.append(file_name_global);
		file_name.append(extension);

		test_file_name = dir_name;
		test_file_name.append("_test");
		test_file_name.append(extension);

		//create file with UTF-8 encoding
		fopen_s(&inFile, file_name.c_str(), "r+,ccs=UTF-8");
		fopen_s(&inTestFile, test_file_name.c_str(), "r+,ccs=UTF-8");

		if ((inFile == NULL) && (inTestFile == NULL))
		{
			continue;
		}
		if ((inFile == NULL) && (inTestFile != NULL))
		{
			fclose(inTestFile);
			return (i * 10 + 1) * 1000;
		}
		if ((inFile != NULL) && (inTestFile == NULL))
		{
			fclose(inFile);
			return (i * 10 + 2) * 1000;
		}

		wchar_t x[1024];
		wchar_t *next_token1 = NULL;

		wchar_t test_x[1024];
		wchar_t *test_next_token1 = NULL;


		fgetws(x, sizeof x, inFile);
		fgetws(test_x, sizeof test_x, inTestFile);
		int rez1=0, rez2=0;
		int line = 0;
		while (x != NULL && test_x != NULL)  // continue till end of file
		{
			line++;
			if (line != 3)	// line 3 is width of columns in save data, ignore compare them
			{
				if (wcsstr(x, test_x) == NULL)
				{
					fclose(inTestFile);
					fclose(inFile);
					return (i * 10 + 3) * 1000 + line;
				}
			}

			if (fgetws(x, sizeof x, inFile)==NULL)
				rez1 = 0;
			else
				rez1 = 1;

			if (fgetws(test_x, sizeof test_x, inTestFile) == NULL)
				rez2 = 0;
			else
				rez2 = 1;

			if((rez1 == 0) || (rez2 == 0))
				break;

		}
		if (((rez1 == 0) && (rez2 != 0)) || ((rez1 != 0) && (rez2 == 0)))
		{
			fclose(inTestFile);
			fclose(inFile);
			return (i * 10 + 4) * 1000;
		}
		fclose(inTestFile);
		fclose(inFile);
	}

	return 0;
}

int Test_compare_dump(string file_name_global)
{
	FILE* inFile;
	FILE* inTestFile;
	string file_name;
	string test_file_name;
	string dir_name = ".\\Test data\\";
	string extension = ".txt";

	for (int i = 0; i <= 8; i++)
	{
		switch (i)
		{
		case 0:	extension = "AI";
			break;
		case 1:	extension = "FC";
			break;
		case 2:	extension = "HC";
			break;
		case 3:	extension = "MOT";
			break;
		case 4:	extension = "PID";
			break;
		case 5:	extension = "VLV";
			break;
		case 6:	extension = "SCADA";
			break;
		case 7:	extension = "IO";
			break;
		case 8:	extension = "Module";
			break;
		default: extension = "AI";
			break;
		}

		file_name = dir_name;
		file_name.append(file_name_global);
		file_name.append("_");
		file_name.append(extension);
		file_name.append(".txt");

		test_file_name = dir_name;
		test_file_name.append("_test_dump_");
		test_file_name.append(extension);
		test_file_name.append(".txt");

		//create file with UTF-8 encoding
		fopen_s(&inFile, file_name.c_str(), "r+,ccs=UTF-8");
		fopen_s(&inTestFile, test_file_name.c_str(), "r+,ccs=UTF-8");

		if ((inFile == NULL) && (inTestFile == NULL))
		{
			continue;
		}
		if ((inFile == NULL) && (inTestFile != NULL))
		{
			fclose(inTestFile);
			return (i * 10 + 1+900) * 1000;
		}
		if ((inFile != NULL) && (inTestFile == NULL))
		{
			fclose(inFile);
			return (i * 10 + 2 + 900) * 1000;
		}

		wchar_t x[1024];
		wchar_t *next_token1 = NULL;

		wchar_t test_x[1024];
		wchar_t *test_next_token1 = NULL;


		fgetws(x, sizeof x, inFile);
		fgetws(test_x, sizeof test_x, inTestFile);
		int rez1 = 0, rez2 = 0;
		int line = 0;
		while (x != NULL && test_x != NULL)  // continue till end of file
		{
			line++;
			if (line != 3)	// line 3 is width of columns in save data, ignore compare them
			{
				if (wcsstr(x, test_x) == NULL)
				{
					fclose(inTestFile);
					fclose(inFile);
					return (i * 10 + 3 + 900) * 1000 + line;
				}
			}

			if (fgetws(x, sizeof x, inFile) == NULL)
				rez1 = 0;
			else
				rez1 = 1;

			if (fgetws(test_x, sizeof test_x, inTestFile) == NULL)
				rez2 = 0;
			else
				rez2 = 1;

			if ((rez1 == 0) || (rez2 == 0))
				break;

		}
		if (((rez1 == 0) && (rez2 != 0)) || ((rez1 != 0) && (rez2 == 0)))
		{
			fclose(inTestFile);
			fclose(inFile);
			return (i * 10 + 4 + 900) * 1000;
		}
		fclose(inTestFile);
		fclose(inFile);
	}

	return 0;
}

int end_test(char* test_name, bool dump_files)
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


	if (ats != 0) // error occured
	{
		char error_text[512];
		error_explane(ats, error_text,sizeof error_text);
		char c[10];
		_itoa_s(ats, c, 10);
		strcpy_s(err_txt, sizeof err_txt, err_test_fail[lang]);
		strcat_s(err_txt, sizeof err_txt, error_separator);
		strcat_s(err_txt, sizeof err_txt, test_name);
		strcat_s(err_txt, sizeof err_txt, error_separator);
		strcat_s(err_txt, sizeof err_txt, error_text);
		strcat_s(err_txt, sizeof err_txt, error_separator);
		strcat_s(err_txt, sizeof err_txt, c);
		err_write_show(err_txt);
		return 1;
	}

	strcpy_s(info_txt, sizeof info_txt, "*****Test");
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, test_name);
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, "Done*****");
	info_write(info_txt);

	return 0;
}

void Project_Design_test(char* language)
{
	char test[255] = "Project-Design";

	char test_name[255];
	prep_test(language, test, test_name, sizeof test_name);


	//do test
	char test_file[20] = "Input_";
	strcat_s(test_file, sizeof test_file, language);

	Project_read_data(FALSE, test_file, project);
	Signals_get_data_design();

	//save test data
	Global_choose_save(Design_grid_index, false, ".\\Test data\\_test");
	Global_choose_save(Signals_grid_index, false, ".\\Test data\\_test");
//	Global_choose_save(Objects_grid_index, false, ".\\Test data\\_test");

//compare test with function
	end_test(test_name, false);
}

void Project_Design_compare(char* language)
{
	char test[255] = "Project-Compare";

	char test_name[255];
	prep_test(language, test, test_name, sizeof test_name);

	//do test
	char test_file[20] = "Input_";
	strcat_s(test_file, sizeof test_file, language);
	Project_compare_data(test_file);

	//save test data
	Global_choose_save(Design_grid_index, false, ".\\Test data\\_test");
	Global_choose_save(Signals_grid_index, false, ".\\Test data\\_test");
	//	Global_choose_save(Objects_grid_index, false, ".\\Test data\\_test");

	//compare test with function
	end_test(test_name, false);
}

void Signals_Find_function_test(char* language)
{
	char test[255] = "Signals-Find function";

	char test_name[255];
	prep_test(language, test, test_name, sizeof test_name);

	//do test
	Signals_find_function();
	Signals_all_KKS_trim(true);

	//save test data
	Global_choose_save(Design_grid_index, false, ".\\Test data\\_test");
	Global_choose_save(Signals_grid_index, false, ".\\Test data\\_test");
	//	Global_choose_save(Objects_grid_index, false, ".\\Test data\\_test");

	//compare test with function
	end_test(test_name, false);
}


void Uniques_find_test(char* language)
{
	char test[255] = "Uniques-Find uniques";

	char test_name[255];
	prep_test(language, test, test_name, sizeof test_name);

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

	//save test data
	Global_choose_save(Design_grid_index, false, ".\\Test data\\_test");
	Global_choose_save(Signals_grid_index, false, ".\\Test data\\_test");
	Global_choose_save(Objects_grid_index, false, ".\\Test data\\_test");

	//compare test with function
	end_test(test_name, false);
	
}

void Uniques_transfer_sig_test(char* language)
{
	char test[255] = "Uniques-Transfer data to Signals";

	char test_name[255];
	prep_test(language, test, test_name, sizeof test_name);

	//do test

	Objects_transfer_to_signals(true);

	//save test data
	Global_choose_save(Design_grid_index, false, ".\\Test data\\_test");
	Global_choose_save(Signals_grid_index, false, ".\\Test data\\_test");
	Global_choose_save(Objects_grid_index, false, ".\\Test data\\_test");

	//compare test with function
	end_test(test_name, false);

}

void Declare_generate_test(char* language, int CPU_index)
{
	char test[255] = "Declare_generate";
	char test_name[255];
	strcpy_s(test_name, sizeof test_name, Global_get_CPU_name(CPU_index));
	strcat_s(test_name, sizeof test_name, "_");
	strcat_s(test_name, sizeof test_name, test);

	strcpy_s(test, sizeof test, test_name);

	prep_test(language, test, test_name, sizeof test_name);

	//do test

	Declare_addreses();


	//save test data
//	Global_choose_save(Design_grid_index, false, ".\\Test data\\_test");
//	Global_choose_save(Signals_grid_index, false, ".\\Test data\\_test");
	Global_choose_save(Objects_grid_index, false, ".\\Test data\\_test");

	//compare test with function
	end_test(test_name, false);
}

void Declare_adressing_test(char* language, int CPU_index)
{
	char test[255] = "Declare_adresses";
	char test_name[255];
	strcpy_s(test_name, sizeof test_name, Global_get_CPU_name(CPU_index));
	strcat_s(test_name, sizeof test_name, "_");
	strcat_s(test_name, sizeof test_name, test);

	strcpy_s(test, sizeof test, test_name);

	prep_test(language, test, test_name, sizeof test_name);

	//do test

	Declare_put_adres_grid(true);


	//save test data
	//	Global_choose_save(Design_grid_index, false, ".\\Test data\\_test");
	//	Global_choose_save(Signals_grid_index, false, ".\\Test data\\_test");
	Global_choose_save(Objects_grid_index, false, ".\\Test data\\_test");

	//compare test with function
	end_test(test_name, true);
}

void Instance_IO_test(char* language, int CPU_index)
{
	char test[255] = "Instance_IO";
	char test_name[255];
	strcpy_s(test_name, sizeof test_name, Global_get_CPU_name(CPU_index));
	strcat_s(test_name, sizeof test_name, "_");
	strcat_s(test_name, sizeof test_name, test);

	strcpy_s(test, sizeof test, test_name);

	prep_test(language, test, test_name, sizeof test_name);

	//do test

	if (IO_generate() == 0)
	{
		if (IO_show(true) == 0)
		{

		}
	}


	//save test data
//	Global_choose_save(Design_grid_index, false, ".\\Test data\\_test");
	Global_choose_save(Signals_grid_index, false, ".\\Test data\\_test");
//	Global_choose_save(Objects_grid_index, false, ".\\Test data\\_test");

	//compare test with function
	end_test(test_name, true);
}

void Instance_Gen_test(char* language, int CPU_index)
{
	char test[255] = "Instance_Gen";
	char test_name[255];
	strcpy_s(test_name, sizeof test_name, Global_get_CPU_name(CPU_index));
	strcat_s(test_name, sizeof test_name, "_");
	strcat_s(test_name, sizeof test_name, test);

	strcpy_s(test, sizeof test, test_name);

	prep_test(language, test, test_name, sizeof test_name);

	//do test

	Instance_gen(true, CPU_index);


	//save test data
//	Global_choose_save(Design_grid_index, false, ".\\Test data\\_test");
	Global_choose_save(Signals_grid_index, false, ".\\Test data\\_test");
//	Global_choose_save(Objects_grid_index, false, ".\\Test data\\_test");

	//compare test with function
	end_test(test_name, true);
}

void Test_All()
{
	char language[5];


	
	for (int i = 0; i <= 2; i++)
	{
		if (i == 1 || i == 2)
			continue;

		switch (i)
		{
		case 0: strcpy_s(language, sizeof language, "LT");
			break;
		case 1: strcpy_s(language, sizeof language, "EN");
			break;
		case 2: strcpy_s(language, sizeof language, "RU");
			break;
		default:
			strcpy_s(language, sizeof language, "LT");
		}

		strcpy_s(info_txt, sizeof info_txt, "*****Test");
		strcat_s(info_txt, sizeof info_txt, error_separator);
		strcat_s(info_txt, sizeof info_txt, language);
		strcat_s(info_txt, sizeof info_txt, error_separator);
		strcat_s(info_txt, sizeof info_txt, "Started*****");
		info_write(info_txt);



		Global_delete_all_data(Design_grid_index);
		Global_delete_all_data(Signals_grid_index);
		Global_delete_all_data(Objects_grid_index);

		Global_put_data_listview(Design_grid_index, project.valid_entries, project.number_collums, project.column_name, project.collumn_with);
		Global_put_data_listview(Signals_grid_index, signals.valid_entries, signals.number_collums, signals.column_name, signals.collumn_with);
		Global_put_data_listview(Objects_grid_index, objects.valid_entries, objects.number_collums, objects.column_name, objects.collumn_with);



		Project_Design_test(language);
		Signals_Find_function_test(language);
		Uniques_find_test(language);
		Uniques_transfer_sig_test(language);
		Project_Design_compare(language);

		for (int j = 0; j <=3 ; j++)
		{
			if (j == 0 || j == 1 || j == 2)
				continue;

			Declare_generate_test(language, j);
			Declare_adressing_test(language, j);
			Instance_IO_test(language, j);
			Instance_Gen_test(language, j);
		}
		


		strcpy_s(info_txt, sizeof info_txt, "*****Test");
		strcat_s(info_txt, sizeof info_txt, error_separator);
		strcat_s(info_txt, sizeof info_txt, language);
		strcat_s(info_txt, sizeof info_txt, error_separator);
		strcat_s(info_txt, sizeof info_txt, "Finished*****");
		info_write(info_txt);
	}



}