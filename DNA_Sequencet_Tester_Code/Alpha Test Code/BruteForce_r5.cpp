/*
The code is based on the a class project at Rutgers University.

Project Title : DNA Sequencer Detector
Class : Data Structures and Algorithms
Course No : ECE573
Professor : Jha
Semester : Spring 2018
Written by Juhi Tripathi and Tina Drew
Debugged by Tina Drew
Tested by Tina Drew

Group Participants : Divyaprakash Dhurandhar, Tina Drew, Anirudh Kulkarni, and Juhi Tripathi

This file runs a set the Brute Force Algorithm to check for DNA match patterns in strings.
*/

// BruteForceJuhi.cpp : Defines the entry point for the console application.
//#include "stdafx.h"
#include <iostream>
#include <list>
#include "time.h"
#include <iterator>
#include <string>
#include <fstream>

using namespace std;

class brute {
	list<string> *ht;

public:

	string corpus(string datafile) {
		string x;
		ifstream file;
		file.open(datafile);
		if (file.is_open())
		{
			file >> x;
		}
		else
			cout << "Cant open the file " << endl;
		return x;
	}

	string pattern(string datafile) {
		string x;
		ifstream file;
		file.open(datafile);
		if (file.is_open())
		{
			file >> x;
		}
		else
			cout << "Cant open the file " << endl;
		return x;
	}

	double compare(string s1, string s2, int l)
	{
		double count = 0;
		bool flag = false;
		for (int i = 0; i< s1.length() - l + 1; i++)
		{
			for (int j = 0; j < s2.length() - l + 1; j++)
			{
				for (int k = 0; k < l; k++)
				{
					if (s1[i + k] == s2[j + k])
					{
						flag = true;
						continue;
					}
					else
					{
						flag = false;
						break;
					}

				}
				if (flag)
					count++;
				flag = false;

			}
		}

		cout << "Total " << count << " locations matched!" << endl;
		return count;
	}

};

//Used determine the Pattern file used for each loop
string myFilesPat[] = { "DNA_String_12.txt", "DNA_String_50.txt", "DNA_String_100.txt",
"DNA_String_200.txt" ,"DNA_String_500.txt" , "DNA_String_700.txt" , "DNA_String_1000.txt" ,
"DNA_String_2000.txt", "DNA_String_3000.txt", "DNA_String_4000.txt", "DNA_String_5000.txt",
"DNA_String_6000.txt", "DNA_String_7000.txt", "DNA_String_8000.txt", "DNA_String_9000.txt",
"DNA_String_10000.txt" };

//Used determine the corpus file used for each loop
string myFilesCorp[] = { "DNA_String_12_corpus.txt", "DNA_String_50_corpus.txt", "DNA_String_100_corpus.txt",
"DNA_String_200_corpus.txt" ,"DNA_String_500_corpus.txt" , "DNA_String_700_corpus.txt" , "DNA_String_1000_corpus.txt" ,
"DNA_String_2000_corpus.txt", "DNA_String_3000_corpus.txt", "DNA_String_4000_corpus.txt", "DNA_String_5000_corpus.txt",
"DNA_String_6000_corpus.txt", "DNA_String_7000_corpus.txt", "DNA_String_8000_corpus.txt", "DNA_String_9000_corpus.txt",
"DNA_String_10000_corpus.txt" };

int main()
{
	float start, stop, timeUsed;
	double count;
	brute h;
	string s1, s2;

	int l;
	cout << "Please enter the length of matching sequence" << endl;
	cin >> l;

	ofstream outputFile;
	outputFile.open("Results_BruteForce.txt");
	outputFile << "Sequence Length " << l << endl;

	int sizeArr = sizeof(myFilesPat) / sizeof(myFilesPat[0]);
	cout << sizeArr;

	for (int a = 0; a < sizeArr; a = a++)
	{
		s1 = h.corpus(myFilesCorp[a]);
		s2 = h.pattern(myFilesPat[a]);
		//cout << "Corpus String : " << s1 << endl;
		//cout << "Pattern String : " << s2 << endl;

		cout << '\n';
		outputFile << '\n';
		start = clock();
		count = h.compare(s2, s1, l);

		stop = clock();
		timeUsed = ((stop - start) / CLOCKS_PER_SEC);
		cout << "DNA Size: " << s2.length() << '\n';
		cout << "Time Elapsed : " << timeUsed << " sec" << endl;
		outputFile << "DNA Size: " << s2.length() << endl;
		outputFile << "# of Matches found: " << count << endl;
		outputFile << "Time Elapsed : " << timeUsed << " sec" << endl;
	}

	//Ensures that the window stays open until the use exits the program
	outputFile.close();
	//From http://www.cplusplus.com/forum/beginner/1988/
	//This ensures that the console stays open until the user presses enter to exit
	std::cout << '\n' << "Press ENTER to continue...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cin.get();
	return 0;

}