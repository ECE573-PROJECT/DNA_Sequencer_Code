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

This file runs a set the Goldman Algorithm to check for DNA match patterns in strings.
*/

// NewProject.cpp : Defines the entry point for the console application.

//#include "stdafx.h"
#include <iostream>
#include <list>
#include "time.h"
#include <iterator>
#include <string>
#include <fstream>

using namespace std;

class hasht {
	int sets;
	list<string> *ht;
	int V;

public:

	void input(string str, int l)
	{
		V = str.length() / l;
		string stri;
		ht = new list<string>[V];
		long weight = 0;
		for (int i = 0; i <= str.length() - l; i++)
		{
			for (int k = 0; k<l; k++)
				weight += str[i + k];
			weight = weight % V;
			stri = str.substr(i, l);
			ht[weight].push_front(stri);
			weight = 0;
		}
		return;
	}

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

	int compare(string str, int l)
	{
		long w = 0;
		string stri;
		int sets = 0;
		int count = 0;
		list<string>::iterator it;
		for (int i = 0; i <= str.length() - l; i++)
		{
			for (int k = 0; k<l; k++)
				w += str[i + k];
			w = w % V;
			stri = str.substr(i, l);
			for (it = ht[w].begin(); it != ht[w].end(); it++)
			{
				sets++;
				if (*it == stri)
				{
					count++;
				}
			}
			w = 0;
		}
		//cout << "Total number of sets " <<sets <<endl;
		cout << "Total " << count << " locations matched!" << endl;
		return count;
	}


};

string myFilesPat[] = { "DNA_String_12.txt", "DNA_String_50.txt", "DNA_String_100.txt",
"DNA_String_200.txt" ,"DNA_String_500.txt" , "DNA_String_700.txt" , "DNA_String_1000.txt" ,
"DNA_String_2000.txt", "DNA_String_3000.txt", "DNA_String_4000.txt", "DNA_String_5000.txt",
"DNA_String_6000.txt", "DNA_String_7000.txt", "DNA_String_8000.txt", "DNA_String_9000.txt",
"DNA_String_10000.txt" };

string myFilesCorp[] = { "DNA_String_12_corpus.txt", "DNA_String_50_corpus.txt", "DNA_String_100_corpus.txt",
"DNA_String_200_corpus.txt" ,"DNA_String_500_corpus.txt" , "DNA_String_700_corpus.txt" , "DNA_String_1000_corpus.txt" ,
"DNA_String_2000_corpus.txt", "DNA_String_3000_corpus.txt", "DNA_String_4000_corpus.txt", "DNA_String_5000_corpus.txt",
"DNA_String_6000_corpus.txt", "DNA_String_7000_corpus.txt", "DNA_String_8000_corpus.txt", "DNA_String_9000_corpus.txt",
"DNA_String_10000_corpus.txt" };

int main()
{
	int matches;
	float start, stop, timeUsed;
	hasht h;
	string s1, s2;

	//cout << "Corpus String : " << s1 << endl;
	//cout << "Pattern String : " << s2 << endl;
	int l;
	cout << "Please enter the length of matching sequence" << endl;
	cin >> l;

	ofstream outputFile;
	outputFile.open("Results_GoldmanMethod.txt");
	outputFile << "Sequence Length " << l << endl;

	int sizeArr = sizeof(myFilesPat) / sizeof(myFilesPat[0]);
	cout << sizeArr;
	for (int a = 0; a < sizeArr; a = a++)
	{
		s1 = h.corpus(myFilesCorp[a]);
		s2 = h.pattern(myFilesPat[a]);
		h.input(s1, l);

		cout << '\n';
		outputFile << '\n';

		start = clock();
		matches = h.compare(s2, l);

		stop = clock();
		timeUsed = ((stop - start) / CLOCKS_PER_SEC);
		cout << "DNA Size: " << s2.length() << '\n';
		cout << "Time Elapsed : " << timeUsed << " sec" << endl;
		outputFile << "DNA Size: " << s2.length() << endl;
		outputFile << "# of Matches: " << matches << endl;
		outputFile << "Time Elapsed : " << timeUsed << " sec" << endl;
	}

	outputFile.close();
	//From http://www.cplusplus.com/forum/beginner/1988/
	//This ensures that the console stays open until the user presses enter to exit
	std::cout << '\n' << "Press ENTER to continue...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cin.get();

	return 0;
}
