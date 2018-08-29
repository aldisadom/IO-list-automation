#include "AAA_TEST_FORM.h"
#include "config.h"
#include "Global_Functions.h"


int testas()
{
	Global_get_data_listview(Objects_grid_index, objects.valid_entries, objects.number_collums, objects.column_name, objects.collumn_with);
	if (objects.valid_entries <= 1)
	{
		strcpy_s(err_txt, sizeof err_txt, err_no_data_edit[lang]);
		strcat_s(err_txt, sizeof err_txt, info_separator);
		strcat_s(err_txt, sizeof err_txt, objects_txt[lang]);
		err_write_show(err_txt);
		return 1;
	}

	strcpy_s(info_txt, sizeof info_txt, info_put_adresses[lang]);
	info_write(info_txt);




	Show_progress(prog_declare[lang], objects.valid_entries);
	
			
	set_progress_value(55);



	Hide_progress();


	strcpy_s(info_txt, sizeof info_txt, info_put_adresses[lang]);
	strcat_s(info_txt, sizeof info_txt, error_separator);
	strcat_s(info_txt, sizeof info_txt, done_txt[lang]);
	info_write(info_txt);


	return 0;
}