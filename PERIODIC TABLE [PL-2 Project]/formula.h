//***************************************************************
//Project Name:Formula Diary
//Institution Name: American International University-Bangladesh (AIUB)
//Student's Name:MD.Abdullah Al Maruf
//student's ID:14-26695-2
//Faculty Name:Dr.Saiful Azad
//****************************************************************


//***************************************************************
//                  HEADER FILE
//****************************************************************

#include<fstream>// for file
#include<string>
#include<iomanip> // for space create and print decimal number after point
#include<cstdlib> // colour,pause,exit
#include<iostream>
#include "windows.h" // sleep(),shellexcaute (open file)
using namespace std;


//***************************************************************
//                   CLASS
//****************************************************************

class formula
{
	int atomicnum; // for atomic number
	char name[30];// for atomic name
	char symbol[2];// for atomic symbol
	double mass;// for atomic mass
	double m_point;// for atomic melting point
	double v_point;// for atomic vapour point
	double	elec_mag;// for electro magmatic
	char oxd[50];// for Oxidization

	char grade[10];
public:
	void getdata();		// accept data from user
	void showdata();	// show data
	void show_tabular();// show data on table style
	int retatomicnum(); //returns atomic number
	char * retName();//returns atomic  name
	void write_formula();	//write the data
	void display_all();	//read all data
	void display_sp(int);	//accept atomic number and read data
	void display_sp(char n[]); //accept atomic name and read data
	void modify_formula(double);	//accept atomic number and update data
	void delete_formula(double);	//accept atomic number delete data
	void class_result();	//display all data
	void result();		//display result menu
	void intro();		//display welcome screen (introducing)
	void about();		//display about screen
	void help();		//open help file
	void urlabout();	//go to developer website
	void close();		//display exit screen
	void entry_menu();	//display ADMIN PANEL menu on screen
	void main_menu(); //display main  menu on screen

};
