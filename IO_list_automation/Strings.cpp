#include "Strings.h"


Strings_all_str str;


void init_strings_LT()
{
	//General	
	str.General.language.s[LT_index] = L"LT";
	str.General.done_txt.s[LT_index] = L"Atlikta";
	str.General.cancel_txt.s[LT_index] = L"Atšaukta";
	str.General.design_txt.s[LT_index] = L"Projektavimas";
	str.General.signals_txt.s[LT_index] = L"Signalai";
	str.General.objects_txt.s[LT_index] = L"Objektai";
	str.General.ai_txt.s[LT_index] = L"Analogai";
	str.General.vlv_txt.s[LT_index] = L"Sklendes";
	str.General.hc_txt.s[LT_index] = L"Hidrocilindrai";
	str.General.fc_txt.s[LT_index] = L"Dažnio keitikliai";
	str.General.pid_txt.s[LT_index] = L"PID reguliatoriai";
	str.General.mot_txt.s[LT_index] = L"Varikliai";
	//Confirm	
	str.Confirm.design_overwrite.s[LT_index] = L"Ar tikrai norima perrašyti projektavimo duomenis?";
	str.Confirm.signal_overwrite.s[LT_index] = L"Ar tikrai norima perrašyti signalų duomenis?";
	str.Confirm.objects_overwrite.s[LT_index] = L"Ar tikrai norima perrašyti objektų duomenis?";
	str.Confirm.objects_type_overwrite.s[LT_index] = L"Ar tikrai norima perrašyti objektų tipo duomenis?";
	str.Confirm.signal_TAG_overwrite.s[LT_index] = L"Ar tikrai norima perrašyti signalo TAG?";
	//info	
	str.Info.button_press.s[LT_index] = L"Paspaustas mygtukas";
	str.Info.color_grid.s[LT_index] = L"Spalvojami lentelės duomenys";
	str.Info.compare_project.s[LT_index] = L"Tikrinama ar yra pakeitimų projekte";
	str.Info.dump_declare.s[LT_index] = L"Saugojami deklaravimo duomenys";
	str.Info.dump_instance.s[LT_index] = L"Saugojami instancijų duomenys";
	str.Info.erase_data.s[LT_index] = L"Išvalomi visi duomenys";
	str.Info.excel_read_data.s[LT_index] = L"Skaitomi duomenys iš excelio";
	str.Info.exit_aplication.s[LT_index] = L"Išeita iš programos paspaudus exit mygtuką";
	str.Info.extract_data.s[LT_index] = L"Duomenys išvalomi nuo nereikalingų eilučių";
	str.Info.extract_from_grid.s[LT_index] = L"Duomenys įrašomi į atmintį";
	str.Info.find_function.s[LT_index] = L"Ieškoma signalo funkcija";
	str.Info.find_objects.s[LT_index] = L"Ieškoma unikalių objektų tipų";
	str.Info.find_operatyv.s[LT_index] = L"Ieškoma operatyvinių pavadinimų objektuose";
	str.Info.find_uniques.s[LT_index] = L"Ieškoma unikalių objektų";
	str.Info.generate_IO_adress.s[LT_index] = L"Kuriami IO tagų adresai";
	str.Info.generate_IO_tags.s[LT_index] = L"Kuriami IO tagai";
	str.Info.get_adresses.s[LT_index] = L"Generuojami objektų adresai";
	str.Info.KKS_edit.s[LT_index] = L"Tvarkomi KKS duomenys";
	str.Info.learning.s[LT_index] = L"Išmokstama atpažinti duomenis";
	str.Info.lenght.s[LT_index] = L"Tikrinamas objektų pavadinimų ilgis";
	str.Info.load_data.s[LT_index] = L"Atstatomi duomenys";
	str.Info.multi_CPU.s[LT_index] = L"Projektas skeliamas į kelis CPU";
	str.Info.no_function.s[LT_index] = L"Buvo bandyta atidaryti, bet nėra tokios funkcijos";
	str.Info.overlap_adresses.s[LT_index] = L"Tikrinami adresų persidengimai";
	str.Info.paste_data.s[LT_index] = L"Įklijuojami duomenys";
	str.Info.put_adresses.s[LT_index] = L"Adresai dedami i lentelę";
	str.Info.put_to_grid.s[LT_index] = L"Duomenys įrašomi į lentelę";
	str.Info.save_data.s[LT_index] = L"Išsaugojami duomenys";
	str.Info.show_trend.s[LT_index] = L"Rodomas grafikas";
	str.Info.transfer_data.s[LT_index] = L"Perkeliami duomenys";
	//Progress	
	str.Progress.adress.s[LT_index] = L"Generuojami adresai";
	str.Progress.check_adress.s[LT_index] = L"Tikrinami adresai";
	str.Progress.declare.s[LT_index] = L"Deklaruojami objektai";
	str.Progress.dump_data.s[LT_index] = L"Saugomi duomenys";
	str.Progress.generate_IO.s[LT_index] = L"Kuriami IO";
	str.Progress.generate_IO_adress.s[LT_index] = L"Kuriami IO adresai";
	str.Progress.grid_color.s[LT_index] = L"Spalvojama lentelė";
	str.Progress.grid_put.s[LT_index] = L"Pildoma lentelė";
	str.Progress.grid_take.s[LT_index] = L"Perkeliama į atmintį";
	str.Progress.learning_data.s[LT_index] = L"Mokinamasi atpažinti";
	str.Progress.lenght.s[LT_index] = L"Tikrinamas ilgis";
	str.Progress.load.s[LT_index] = L"Atstatomi duomenys";
	str.Progress.multi_cpu.s[LT_index] = L"Kuriami keli CPU";
	str.Progress.operatyv.s[LT_index] = L"Ieškomi operatyviniai";
	str.Progress.overlap.s[LT_index] = L"Tikrinami persidengimai";
	str.Progress.paste.s[LT_index] = L"Įklijuojami duomenys";
	str.Progress.process_data.s[LT_index] = L"Apdorojami duomenys";
	str.Progress.read_data.s[LT_index] = L"Skaitomi duomenys";
	str.Progress.save.s[LT_index] = L"Saugojami duomenys";
	str.Progress.search_diference.s[LT_index] = L"Ieskomi pakeitimai";
	str.Progress.transfer_data.s[LT_index] = L"Perkeliami duomenys";
	str.Progress.trend_polynom.s[LT_index] = L"Skaičiuojamas polinomas";
	str.Progress.uniques_find.s[LT_index] = L"Ieškomi unikalus";
	str.Progress.uniques_object_type.s[LT_index] = L"Ieškomi objektu tipai";
	//Error	
	str.Error.bad_link.s[LT_index] = L"Blogai nurodytas link";
	str.Error.canceled_selection.s[LT_index] = L"Atšauktas failo pasirinkimas";
	str.Error.cant_open.s[LT_index] = L"Nepavyko atidaryti failo";
	str.Error.cfg_bad_parameter.s[LT_index] = L"Neegzistuojantis parametras";
	str.Error.cfg_bad_value.s[LT_index] = L"Bloga parametro reikšmė";
	str.Error.cfg_empty_parameter.s[LT_index] = L"Tuščias parametras eilutėje";
	str.Error.cfg_empty_value.s[LT_index] = L"Nėra reikšmės parametre";
	str.Error.cfg_parameter_programing_error.s[LT_index] = L"ups!!! Programos klaida, neįdėtas parametras, jį reikia pašalinti iš _cfg.txt arba įdėti į programą, prašom raportuoti šia problemą ir kaip ją atkartoti :)";
	str.Error.clickboard_no_data.s[LT_index] = L"Nėra duomenų perkėlimui";
	str.Error.clickboard_no_match.s[LT_index] = L"Neatitinka duomenų kiekis kurį įklijuojam su pasirinktu";
	str.Error.clickboard_overrange.s[LT_index] = L"Kopijuojami duomenys viršija įklijavimo sritį";
	str.Error.corrupted_file.s[LT_index] = L"Sugadintas duomenų failas";
	str.Error.corrupted_file_continue.s[LT_index] = L"Sugadintas duomenu failas, bet toliau bandoma importuoti";
	str.Error.excel_cant_open.s[LT_index] = L"Nepavyko atidaryti pasirinkto failo, tinkamas yra .xls";
	str.Error.excel_no_sheet.s[LT_index] = L"Nėra nei vieno darbalapio excelyje";
	str.Error.no_adress_object.s[LT_index] = L"Nėra adresų objektuose";
	str.Error.no_cfg_file.s[LT_index] = L"_cfg.txt --- Nepavyko atidaryti konfiguracinio failo";
	str.Error.no_data_edit.s[LT_index] = L"Nėra duomenų, kuriuos tvarkyti";
	str.Error.no_data_save.s[LT_index] = L"Nėra duomenu, kuriuos saugoti";
	str.Error.no_file_save.s[LT_index] = L"Nepavyko sukurti duomenų saugojimo failo";
	str.Error.no_function_for_this.s[LT_index] = L"Nereikalinga ši funkcija";
	str.Error.no_learn_file.s[LT_index] = L"Nėra mokinimo duomenų failo";
	str.Error.no_object_types_edit.s[LT_index] = L"Nėra tipų objektuose";
	str.Error.no_tag.s[LT_index] = L"Nėra tag šiam signalui";
	str.Error.show_trend.s[LT_index] = L"Nepavyko atidaryti grafiko";
	str.Error.string.s[LT_index] = L"Klaida";
	str.Error.test_fail.s[LT_index] = L"!!!!!!!!!!!!!TESTAS NEPAVYKO!!!!!!!!!!!";
	str.Error.unstable.s[LT_index] = L"ši programos versija nėra pilnai testuota, tad atsargiai naudotis !!!";
	str.Error.wrong_file.s[LT_index] = L"Pasirinktas ne toks failo tipas";
	str.Error.wrong_object_type.s[LT_index] = L"Neatpažintas objekto tipas";
	str.Error.Create_memory_map_obj.s[LT_index] = L"Could not create file mapping object";
	str.Error.Create_memory_map_view.s[LT_index] = L"Could not map view of file";
	str.Error.Open_memory_map_view.s[LT_index] = L"Could not open file mapping object";
}
void init_strings_EN()
{
	//General
	str.General.language.s[EN_index] = L"EN";
	str.General.done_txt.s[EN_index] = L"Done";
	str.General.cancel_txt.s[EN_index] = L"Canceled";
	str.General.design_txt.s[EN_index] = L"Design";
	str.General.signals_txt.s[EN_index] = L"Signals";
	str.General.objects_txt.s[EN_index] = L"Objects";
	str.General.ai_txt.s[EN_index] = L"Analogs";
	str.General.vlv_txt.s[EN_index] = L"Valves";
	str.General.hc_txt.s[EN_index] = L"Hidrocilinders";
	str.General.fc_txt.s[EN_index] = L"Frequency converters";
	str.General.pid_txt.s[EN_index] = L"PID regulators";
	str.General.mot_txt.s[EN_index] = L"Motors";
	//Confirm	
	str.Confirm.design_overwrite.s[EN_index] = L"Do you realy whant to overwrite design data?";
	str.Confirm.signal_overwrite.s[EN_index] = L"Do you realy whant to overwrite signals data?";
	str.Confirm.objects_overwrite.s[EN_index] = L"Do you realy whant to overwrite object data?";
	str.Confirm.objects_type_overwrite.s[EN_index] = L"Do you realy whant to overwrite object type data?";
	str.Confirm.signal_TAG_overwrite.s[EN_index] = L"Do you realy whant to overwrite signal TAG?";
	//info	
	str.Info.button_press.s[EN_index] = L"Button pressed";
	str.Info.color_grid.s[EN_index] = L"Coloring grid data";
	str.Info.compare_project.s[EN_index] = L"Testing if there is changes in project";
	str.Info.dump_declare.s[EN_index] = L"Dumping declare data";
	str.Info.dump_instance.s[EN_index] = L"Dumping instance data";
	str.Info.erase_data.s[EN_index] = L"Erasing all data";
	str.Info.excel_read_data.s[EN_index] = L"Reading data from excel";
	str.Info.exit_aplication.s[EN_index] = L"Exited pressing exit button";
	str.Info.extract_data.s[EN_index] = L"Data is extracted from unwanted data";
	str.Info.extract_from_grid.s[EN_index] = L"Data is writen to memory";
	str.Info.find_function.s[EN_index] = L"Searching for signal function";
	str.Info.find_objects.s[EN_index] = L"Searching unique objects types";
	str.Info.find_operatyv.s[EN_index] = L"Searching operative in objects";
	str.Info.find_uniques.s[EN_index] = L"Searching unique objects";
	str.Info.generate_IO_adress.s[EN_index] = L"Generating IO tag adresses";
	str.Info.generate_IO_tags.s[EN_index] = L"Generating IO tags";
	str.Info.get_adresses.s[EN_index] = L"Generating object adresses";
	str.Info.KKS_edit.s[EN_index] = L"Processing KKS data";
	str.Info.learning.s[EN_index] = L"Learning recognition data";
	str.Info.lenght.s[EN_index] = L"Checking object description lenght";
	str.Info.load_data.s[EN_index] = L"Loading data";
	str.Info.multi_CPU.s[EN_index] = L"Project divided to few CPU";
	str.Info.no_function.s[EN_index] = L"Tryed to open, but there is no function";
	str.Info.overlap_adresses.s[EN_index] = L"Checking adress overlap";
	str.Info.paste_data.s[EN_index] = L"Pasting data";
	str.Info.put_adresses.s[EN_index] = L"Adresses are put to table";
	str.Info.put_to_grid.s[EN_index] = L"Data is writen to grid";
	str.Info.save_data.s[EN_index] = L"Saving data";
	str.Info.show_trend.s[EN_index] = L"Showing trend";
	str.Info.transfer_data.s[EN_index] = L"Transfering data";
	//Progress	
	str.Progress.adress.s[EN_index] = L"Generating adreses";
	str.Progress.check_adress.s[EN_index] = L"Checking adresses";
	str.Progress.declare.s[EN_index] = L"Declaring objects";
	str.Progress.dump_data.s[EN_index] = L"Dumping data";
	str.Progress.generate_IO.s[EN_index] = L"Generating IO";
	str.Progress.generate_IO_adress.s[EN_index] = L"Generating IO adressing";
	str.Progress.grid_color.s[EN_index] = L"Coloring grid";
	str.Progress.grid_put.s[EN_index] = L"Puting data to grid";
	str.Progress.grid_take.s[EN_index] = L"Transfering to memory";
	str.Progress.learning_data.s[EN_index] = L"Learning recognition";
	str.Progress.lenght.s[EN_index] = L"Checking leght";
	str.Progress.load.s[EN_index] = L"Loading data";
	str.Progress.multi_cpu.s[EN_index] = L"Generating multi-CPU";
	str.Progress.operatyv.s[EN_index] = L"Searching operative";
	str.Progress.overlap.s[EN_index] = L"Checking overlap";
	str.Progress.paste.s[EN_index] = L"Pasting data";
	str.Progress.process_data.s[EN_index] = L"Processing data";
	str.Progress.read_data.s[EN_index] = L"Reading data";
	str.Progress.save.s[EN_index] = L"Saving data";
	str.Progress.search_diference.s[EN_index] = L"Searching diferences";
	str.Progress.transfer_data.s[EN_index] = L"Transfering data";
	str.Progress.trend_polynom.s[EN_index] = L"Polynom calculating";
	str.Progress.uniques_find.s[EN_index] = L"Searching uniques";
	str.Progress.uniques_object_type.s[EN_index] = L"Searching object types";
	//Error	
	str.Error.bad_link.s[EN_index] = L"Bad link";
	str.Error.canceled_selection.s[EN_index] = L"File selection canceled";
	str.Error.cant_open.s[EN_index] = L"Could not open file";
	str.Error.cfg_bad_parameter.s[EN_index] = L"Parameter do not exists";
	str.Error.cfg_bad_value.s[EN_index] = L"Bad parameter value";
	str.Error.cfg_empty_parameter.s[EN_index] = L"Empty parameter in line";
	str.Error.cfg_empty_value.s[EN_index] = L"No value in parameter";
	str.Error.cfg_parameter_programing_error.s[EN_index] = L"ups!!! Program error, this parameter isnot added to program, remove from _cfg.txt or add to program, please report this problem and how to recreate it :)";
	str.Error.clickboard_no_data.s[EN_index] = L"No data to paste";
	str.Error.clickboard_no_match.s[EN_index] = L"Data size dont match for pasting";
	str.Error.clickboard_overrange.s[EN_index] = L"Paste data is overrange compared to grid";
	str.Error.corrupted_file.s[EN_index] = L"Corrupted data file";
	str.Error.corrupted_file_continue.s[EN_index] = L"Corrupted data file, continuing to import";
	str.Error.excel_cant_open.s[EN_index] = L"Cant open chossen file, compatible only .xls files";
	str.Error.excel_no_sheet.s[EN_index] = L"There is no sheets in excel";
	str.Error.no_adress_object.s[EN_index] = L"No adresses in objects";
	str.Error.no_cfg_file.s[EN_index] = L"_cfg.txt --- Could not open configuration file";
	str.Error.no_data_edit.s[EN_index] = L"There is no data to edit";
	str.Error.no_data_save.s[EN_index] = L"There is no data to save";
	str.Error.no_file_save.s[EN_index] = L"Could not create data save file";
	str.Error.no_function_for_this.s[EN_index] = L"Not needed function";
	str.Error.no_learn_file.s[EN_index] = L"No learning data file";
	str.Error.no_object_types_edit.s[EN_index] = L"No object types";
	str.Error.no_tag.s[EN_index] = L"No tag for this signal";
	str.Error.show_trend.s[EN_index] = L"Failed to load plot data";
	str.Error.string.s[EN_index] = L"Error";
	str.Error.test_fail.s[EN_index] = L"!!!!!!!!!!!!!TEST FAILED!!!!!!!!!!!!!!!";
	str.Error.unstable.s[EN_index] = L"This program is not stable ant not fully tested, carefully use it !!!";
	str.Error.wrong_file.s[EN_index] = L"Wrong file type selected";
	str.Error.wrong_object_type.s[EN_index] = L"Unrecognised object type";
	str.Error.Create_memory_map_obj.s[EN_index] = L"Could not create file mapping object";
	str.Error.Create_memory_map_view.s[EN_index] = L"Could not map view of file";
	str.Error.Open_memory_map_view.s[EN_index] = L"Could not open file mapping object";
}

void init_strings_RU()
{
	
}

void init_strings_LV()
{
	
}

void init_strings()
{
	init_strings_LT();
	init_strings_EN();
	init_strings_LV();
	init_strings_RU();
}