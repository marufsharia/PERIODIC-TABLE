#include "formula.h"
//***************************************************************
//    Input data
//****************************************************************


void formula::getdata()
{
	cout << "\nEnter The Atomic number: ";
	cin >> atomicnum;
	cout << "\n\nEnter The Name of element (Small letter): ";
	cin >> name;
	cout << "\n\nEnter The Name of symbol: ";
	cin >>symbol;
	cout << "\n\nEnter The Mass of element: ";
	cin >> mass;
	cout << "\nEnter The Melting point of element : ";
	cin >> m_point;
	cout << "\nEnter The Vapour point of element : ";
	cin >> v_point;
	cout << "\nEnter The Electromagnetic number of element : ";
	cin >> elec_mag;
	cout << "\nEnter The Oxidization of element (Ex: -1,1) : ";
	cin >> oxd;
	cout << "\nEnter The Type of element : ";
	cin >> grade;


}

//***************************************************************
//    	show data
//****************************************************************


void formula::showdata()
{
	cout << "\nThe Atomic number: " << atomicnum;
	cout << "\nThe Name of element: " << name;
	cout << "\nThe Name of symbol: " << symbol;
	cout << "\nThe Mass of element: " << mass;
	cout << "\nThe Melting point of element: " << m_point;
	cout << "\nThe Vapour point of element: " << v_point;
	cout << "\nThe Electromagnetic number of element: " << elec_mag;
	cout << "\nThe Oxidization of element: " << oxd;
	cout << "\nThe Type of element: " <<grade;
}

//***************************************************************
//    show table
//****************************************************************

void formula::show_tabular()
{
	cout << atomicnum << setw(8) << " " << name << setw(8) << " " << symbol << setw(8) << " " << mass << setw(8) << " " << m_point << setw(8) << " " << v_point << setw(8) << " " << elec_mag << setw(8)
		<< " " << oxd << setw(6) <<" " << grade << endl;
}

//***************************************************************
//    	return atomic number
//****************************************************************

int  formula::retatomicnum()
{
	return atomicnum;
}

//***************************************************************
//    	return  name
//****************************************************************

char * formula::retName()//returns the formula name
{
	return name;
}

//***************************************************************
//    	 write in file
//****************************************************************

void formula::write_formula()
{
	formula st;
	ofstream outFile;// file write..
	outFile.open("formula.dat", ios::binary | ios::app);
	st.getdata();
	outFile.write((char *)&st, sizeof(formula));
	outFile.close();
	cout << "\n\n Record Has Been Created \n";
	cin.ignore();
	system("color 2f");
	cout << endl;
	system("pause");
}

//***************************************************************
//    	Show all Data
//****************************************************************

void formula::display_all()
{
	formula st;
	ifstream inFile;// file read...
	inFile.open("formula.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		system("pause");
		return;
	}
	cout << "\n====================================";
	cout << "\n DISPLAY ALL ELEMENT";
	cout << "\n====================================\n";
	while (inFile.read((char *)&st, sizeof(formula)))
	{

		st.showdata();
		cout << "\n\n====================================\n";
	}
	inFile.close();
	system("color 2f");
	cout << endl;
	system("pause");
}

//***************************************************************
//    	 read specific atomic number
//****************************************************************

void formula::display_sp(int n)
{
	formula st;
	ifstream inFile;
	inFile.open("formula.dat", ios::binary);
	if (!inFile)
	{
		cout << "\nFile could not be open !! Press any Key...";
		system("pause");
		return;
	}

	int flag = 0;
	while (inFile.read((char *)&st, sizeof(formula)))
	{
		if (st.retatomicnum() == n)
		{
			st.showdata();
			flag = 1;
		}
	}
	inFile.close();
	if (flag == 0)
		cout << "\n\nRecord not exist";
	system("color 2f");
	cout << endl;
	system("pause");

}

//***************************************************************
//    	 read specific atomic name from file
//****************************************************************

void formula::display_sp(char n[])
{
	formula st;
	ifstream inFile;
	inFile.open("formula.dat", ios::binary);
	if (!inFile)
	{
		cout << "\nFile could not be open !! Press any Key...";
		system("pause");
		return;
	}

	int flag = 0;
	while (inFile.read((char *)&st, sizeof(formula)))
	{
		if (!strcmp(st.retName(), n))
		{
			st.showdata();
			flag = 1;
		}
	}
	inFile.close();
	if (flag == 0)
		cout << "\n\nRecord not exist";
	system("color 2f");
	cout << endl;
	system("pause");
}

//***************************************************************
//    	 modify data of file
//****************************************************************

void formula::modify_formula(double n)
{
	int found = 0;
	formula st;
	fstream File;
	File.open("formula.dat", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "\nFile could not be open !! Press any Key...";
		system("pause");
		return;
	}
	while (File.read((char *)&st, sizeof(formula)) && found == 0)
	{
		if (st.retatomicnum() == n)
		{
			st.showdata();
			cout << "\n\nPlease Enter The New Details of Element" << endl;
			st.getdata();
			int pos = sizeof(st);
			pos = pos*-1;
			File.seekp(pos, ios::cur);
			File.write((char *)&st, sizeof(formula));
			cout << "\n\n\t Record Updated";
			found = 1;
		}
	}
	File.close();
	if (found == 0)
		cout << "\n\n Record Not Found ";
	system("color 2f");
	cout << endl;
	system("pause");
}

//***************************************************************
//    	 delete data of file
//****************************************************************

void formula::delete_formula(double n)
{
	formula st;
	ifstream inFile;
	inFile.open("formula.dat", ios::binary);
	if (!inFile)
	{
		cout << "\nFile could not be open !! Press any Key...";
		system("pause");
		return;
	}
	ofstream outFile;
	outFile.open("Temp.dat", ios::out);
	inFile.seekg(0, ios::beg);
	while (inFile.read((char *)&st, sizeof(formula)))
	{
		if (st.retatomicnum() != n)
		{
			outFile.write((char *)&st, sizeof(formula));
		}
	}
	outFile.close();
	inFile.close();
	remove("formula.dat");
	rename("Temp.dat", "formula.dat");
	cout << "\n\n\tRecord Deleted ..";
	system("color 2f");
	cout << endl;
	system("pause");
}

//***************************************************************
//    	table sheet
//****************************************************************

void formula::class_result()
{
	formula st;
	ifstream inFile;
	inFile.open("formula.dat", ios::binary);
	if (!inFile)
	{
		cout << "\nFile could not be open !! Press any Key...";
		system("pause");
		return;
	}
	cout << "\n\t\t\t\t ====================================";
	cout << "\n\t\t\t\t DISPLAY ALL ELEMENT (TABLE STYLE)";
	cout << "\n\t\t\t\t ====================================\n";
	cout << "==================================================================================================================\n";
	cout << "R.No     Name     Symbol       Mass          M.pont             V.pont       Oxidig          Elec.Mag        Type" << endl;
	cout << "==================================================================================================================\n";
	while (inFile.read((char *)&st, sizeof(formula)))
	{
		st.show_tabular();
	}
	cout << endl;
	system("color 2f");
	system("pause");
	inFile.close();
}


//***************************************************************
//    	 splash Screen
//****************************************************************


void formula::intro()

{

	cout << "\n\n\t\t\t                    * *";
	cout << "\n\t\t\t                 *      *";
	cout << "\n\t\t\t              *            *";
	cout << "\n\t\t\t           *                  *";
	cout << "\n\t\t\t         *                      *";
	cout << "\n\t\t\t       *                           *";
	cout << "\n\t\t\t    *                                *";
	cout << "\n\t\t\t  *                                     *";
	cout << "\n\t\t\t*                                          *";
	cout << "\n\t\t\t=============================================\n";
	cout << "\t\t\t<>        FORMULA DAIRY (PERIODIC TABLE)   <>";
	cout << "\n\t\t\t=============================================\n";
	cout << "\n\t\t\t#                                          #";
	cout << "\n\t\t\t\t NAME: MARUF,ND.ABDULLAH AL ";
	cout << "\n\t\t\t#                                          #";
	cout << "\n\t\t\t#                                          #";
	cout << "\n\t\t\t\t ID: 1426695-2";
	cout << "\n\t\t\t#                                          #";
	cout << "\n\t\t\t#                                          #";
	cout << "\n\t\t\t\t FACULTY:Dr. SHAIFUL AZAD";
	cout << "\n\t\t\t#                                          #";
	cout << "\n\t\t\t=============================================";
	cout << "\n\t\t\t=============================================\n";
	cout << "\n\t\t\t             LOADING...             \n";
	cout << "\n\t\t \t\t";

	for (int i=0;i<5;i++){

		system("color 05");
		Sleep(500);
		system("color 02");
		Sleep(500);

		system("color 03");
		Sleep(500);

		system("color 04");
		Sleep(500);
		system("color 06");
		Sleep(500);
		system("color 2f");
		break;

	}
}

//***************************************************************
//    	 MAIN MENU
//****************************************************************
void formula::main_menu()
{
	char ch;
	cout.setf(ios::fixed | ios::showpoint);
	cout << setprecision(4); // outputs decimal after point (like : 1.0004)
	system("cls");
	intro();
	do
	{
		system("cls");
		cout << "\n\n\t\t\t<>                                         <>";
		cout << "\n\t\t\t=============================================\n";
		cout << "\t\t\t#                                           #";
		cout << "\n\t\t\t\t        MAIN MENU";
		cout << "\n\t\t\t#                                           #";
		cout << "\n\t\t\t=============================================\n";
		cout << "\t\t\t||                                         ||";
		cout << "\n\t\t\t||                                         ||";
		cout << "\n\t\t\t\t1 ) SEARCH MENU.";
		cout << "\n\t\t\t||                                         ||";
		cout << "\n\t\t\t||                                         ||";
		cout << "\n\t\t\t\t2 ) ADMIN PANEL";
		cout << "\n\t\t\t||                                         ||";
		cout << "\n\t\t\t||                                         ||";
		cout << "\n\t\t\t\t3 ) Help";
		cout << "\n\t\t\t||                                         ||";
		cout << "\n\t\t\t||                                         ||";
		cout << "\n\t\t\t\t4 ) About";
		cout << "\n\t\t\t||                                         ||";
		cout << "\n\t\t\t||                                         ||";
		cout << "\n\t\t\t\t5 ) Exit.";
		cout << "\n\t\t\t||                                         ||";
		cout << "\n\t\t\t||                                         ||";
		cout << "\n\t\t\t=============================================\n";
		cout << "\t\t\t<>                                         <>";
		cout << "\n\t\t\t\tChoose A Option (1-5): ";

		cin >> ch;
		system("cls");
		switch (ch)
		{
		case '1': result();
			break;
		case '2': entry_menu();
			break;
		case '3': help();
			break;
		case '4': about();
			break;
		case '5': close();
			break;
		default:cout << "\a";
		}
	} while (ch != '6');

}



//***************************************************************
//    	SEARCH MENU
//****************************************************************

void formula::result()
{
	char ch;
	char name[50];
	double num;
	system("color 60");
	cout << "\n\n\t\t\t<>                                         <>";
	cout << "\n\t\t\t=============================================\n";
	cout << "\t\t\t#                                           #";
	cout << "\n\t\t\t\t        SEARCH MENU";
	cout << "\n\t\t\t#                                           #";
	cout << "\n\t\t\t=============================================\n";
	cout << "\t\t\t||                                         ||";
	cout << "\n\t\t\t||                                         ||";
	cout << "\n\t\t\t\t1 ) Seach By Atomic Number.";
	cout << "\n\t\t\t||                                         ||";
	cout << "\n\t\t\t||                                         ||";
	cout << "\n\t\t\t\t2 ) Seach By Name";
	cout << "\n\t\t\t||                                         ||";
	cout << "\n\t\t\t||                                         ||";
	cout << "\n\t\t\t\t3 ) Show All Detail";
	cout << "\n\t\t\t||                                         ||";
	cout << "\n\t\t\t||                                         ||";
	cout << "\n\t\t\t\t4 ) Show All Detail (table)";
	cout << "\n\t\t\t||                                         ||";
	cout << "\n\t\t\t||                                         ||";
	cout << "\n\t\t\t\t5 ) Back to Main Menu.";
	cout << "\n\t\t\t||                                         ||";
	cout << "\n\t\t\t||                                         ||";
	cout << "\n\t\t\t=============================================\n";
	cout << "\t\t\t<>                                         <>";
	cout << "\n\t\t\t\tChoose A Option (1-5): ";

	cin >> ch;
	system("cls");
	switch (ch)
	{
	case '1':
		cout << "\n\t\t\t=============================================\n";
		cout << "\t\t\t<>             Enter Atomic Number             <>";
		cout << "\n\t\t\t=============================================\n";
		cout << "\n\t\t => ";
		cin >> num;

		display_sp(num);
		break;
	case '2':
		cout << "\n\t\t\t=============================================\n";
		cout << "\t\t\t<>             Enter Atomic Name             <>";
		cout << "\n\t\t\t=============================================\n";
		cout << "\n\t\t (Small letter)=>  ";
		cin >> name;
		display_sp(name);
		break;
	case '3':display_all();
		break;
	case '4':class_result();
		break;
	case '5':
		system("color 2f");
		break;
	default:cout << "\a";
		result();
	}
}



//***************************************************************
//    	ADMIN PANEL
//****************************************************************

void formula::entry_menu()
{
	char ch;

	double num;
	system("cls");

	system("color 60");
	cout << "\n\n\t\t\t<>                                         <>";
	cout << "\n\t\t\t=============================================\n";
	cout << "\t\t\t#                                           #";
	cout << "\n\t\t\t\t        ADMIN PANEL";
	cout << "\n\t\t\t#                                           #";
	cout << "\n\t\t\t=============================================\n";
	cout << "\t\t\t||                                         ||";
	cout << "\n\t\t\t||                                         ||";
	cout << "\n\t\t\t\t1 ) ADD DATA";
	cout << "\n\t\t\t||                                         ||";
	cout << "\n\t\t\t||                                         ||";
	cout << "\n\t\t\t\t2 ) MODIFY DATA";
	cout << "\n\t\t\t||                                         ||";
	cout << "\n\t\t\t||                                         ||";
	cout << "\n\t\t\t\t3 ) DELETE DATA";
	cout << "\n\t\t\t||                                         ||";
	cout << "\n\t\t\t||                                         ||";
	cout << "\n\t\t\t\t4 ) BACK TO MAIN MENU";
	cout << "\n\t\t\t||                                         ||";
	cout << "\n\t\t\t||                                         ||";
	cout << "\n\t\t\t=============================================\n";
	cout << "\t\t\t<>                                         <>";
	cout << "\n\t\t\t\tChoose A Option (1-4): ";

	cin >> ch;
	system("cls");
	switch (ch)
	{
	case '1':	write_formula();
		break;
	case '2':
		cout << "\n\t\t\t=============================================\n";
		cout << "\t\t\t<>             Enter Atomic Number             <>";
		cout << "\n\t\t\t=============================================\n";
		cout << "\n\t\t   ";
		cin >> num;
		modify_formula(num);
		break;
	case '3':
		cout << "\n\t\t\t=============================================\n";
		cout << "\t\t\t<>             Enter Atomic Number             <>";
		cout << "\n\t\t\t=============================================\n";
		cout << "\n\t\t   ";
		cin >> num;
		delete_formula(num);
		break;
	case '4':
		system("color 2f");
		break;
	default:	cout << "\a";
		entry_menu();
	}
}



//***************************************************************
//    	About Screen
//****************************************************************
void formula::about()

{

	char ch;
	system("color 57");
	cout << "\n\n\t\t\t=============================================\n";
	cout << "\t\t\t<>                  ABOUT            <>";
	cout << "\n\t\t\t=============================================\n";
	cout << "\n\t\t\t#                                          #";
	cout << "\n\t\t\t\t    Version: 1.0.1 ";
	cout << "\n\t\t\t#                                          #";
	cout << "\n\t\t\t#                                          #";
	cout << "\n\t\t\t\t Developer: MARUF SHARIA ";
	cout << "\n\t\t\t#                                          #";
	cout << "\n\t\t\t#                                          #";
	cout << "\n\t\t\t\t E-mail: marufsharia@gmail.com";
	cout << "\n\t\t\t#                                          #";
	cout << "\n\t\t\t#                                          #";
	cout << "\n\t\t\t\t   (1) to Visit Website";
	cout << "\n\t\t\t#                                          #";
	cout << "\n\t\t\t\t  Website:mstecsoft.blogspot.com";
	cout << "\n\t\t\t=============================================";
	cout << "\n\t\t\t\t   (2) to Back Main Menu";
	cout << "\n\t\t\t=============================================\n";
	cout << "\n\t\t \t\t";
	cin >> ch;
	system("cls");
	switch (ch)
	{
	case '1': urlabout();

		break;
	case '2':
		system("color 2f");
		break;
	default:cout << "\a";

		about();
	}
}
//***************************************************************
//    	Exit Screen
//****************************************************************

void formula::close()

{

	char ch;

	cout << "\n\t\t\t=============================================\n";
	cout << "\t\t\t<>                   Exit                 <>";
	cout << "\n\t\t\t=============================================\n";
	cout << "\n\t\t\t#                                          #";
	cout << "\n\t\t\t\t Do You Want To Exit?  ";
	cout << "\n\t\t\t#                                          #";
	cout << "\n\t\t\t#                                          #";
	cout << "\n\t\t\t\tYes(1)\t\t No(2)";
	cout << "\n\t\t\t#                                          #";
	cout << "\n\t\t\t=============================================";
	cout << "\n\t\t\t=============================================\n";
	cout << "\n\t\t \t\t";
	cin >> ch;
	system("cls");
	switch (ch)
	{
	case '1':
		exit(1);
		break;
	case '2':


		break;
	default:cout << "\a";
		close();


	}


}
//***************************************************************
//    	 developer website open
//****************************************************************

void formula::urlabout()

{
	string path = "http://www.mstecsoft.blogspot.com";

	ShellExecuteA(GetDesktopWindow(), ("open"), LPCSTR(path.c_str()), NULL, NULL, SW_SHOWNORMAL);


}

//***************************************************************
//    	help file open
//****************************************************************

void formula::help()

{
	string path = "help\\index.html";

	ShellExecuteA(GetDesktopWindow(), ("open"), LPCSTR(path.c_str()), NULL, NULL, SW_SHOWNORMAL);

}
