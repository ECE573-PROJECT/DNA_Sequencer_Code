// BruteForceJuhi.cpp : Defines the entry point for the console application.
//#include "stdafx.h"
#include <iostream>
#include <list>
#include "time.h"
#include <iterator>
#include <string>
#include <fstream>

using namespace std;

class hasht {
	list<string> *ht;

public:

	void input(string str, int l)
	{
		int V = str.length() / l;
		string stri;
		ht = new list<string>[V];
		long weight = 0;
		for (int i = 0; i != str.length() - l; i++)
		{
			weight += str[i] + str[i + 1] + str[i + 2];
			weight = weight % l;
			stri = str.substr(i, l);
			ht[weight].push_front(stri);
			weight = 0;
		}
		return;
	}

	string corpus() {
		string x;
		ifstream file;
		file.open("case3-corpus.txt");
		if (file.is_open())
		{
			file >> x;
		}
		else
			cout << "Cant open the file " << endl;
		return x;
	}

	string pattern(string dataFile) {
		string x;
		ifstream file;
		file.open(dataFile);
		if (file.is_open())
		{
			file >> x;
		}
		else
			cout << "Cant open the file " << endl;
		return x;
	}

	void compare(string str, int l)
	{
		long w = 0;
		string stri;
		int count = 0, t = 0;
		list<string>::iterator it;
		for (int i = 0; i != str.length() - l; i++)
		{
			w += str[i] + str[i + 1] + str[i + 2];
			w = w % l;
			t++;
			stri = str.substr(i, l);
			for (it = ht[w].begin(); it != ht[w].end(); it++)
			{
				if (*it == stri)
				{
					count++;
				}
			}
		}
		double x = (double)count / t;
		cout << " " << x * 100 << "% matched!" << endl;
	}

};

string myFiles[] = { "DNA_String_12.txt", "DNA_String_100.txt", "DNA_String_500.txt", "DNA_String_10000.txt",
"DNA_String_20000.txt", "DNA_String_30000.txt", "DNA_String_40000.txt", "DNA_String_50000.txt","DNA_String_60000.txt",
"DNA_String_70000.txt", "DNA_String_80000.txt", "DNA_String_90000.txt", "DNA_String_100000.txt", };

int main()
{
	float start, stop, timeUsed;
	hasht h;
	string s1, s2;
	s1 = h.corpus();

	int l;
	cout << "Please enter the length of matching sequence" << endl;
	cin >> l;

	ofstream outputFile;
	outputFile.open("Results_GoldmanMethod.txt");
	outputFile << "Sequence Length " << l << endl;

	int sizeArr = sizeof(myFiles) / sizeof(myFiles[0]);
	cout << sizeArr;
	for (int a = 0; a < sizeArr; a = a++)
	{
		s2 = h.pattern(myFiles[a]);
		//cout << "Corpus String : " << s1 << endl;
		//cout << "Pattern String : " << s2 << endl;
		start = clock();
		cout << '\n';
		outputFile<< '\n';

		h.input(s1, l);
		h.compare(s2, l);
		stop = clock();
		timeUsed = ((stop - start) / CLOCKS_PER_SEC) * 1000;
		cout << "DNA Size: " << s2.length() << '\n';
		cout << "Time Elapsed : " << timeUsed << " ms" << endl;
		outputFile << "DNA Size: " << s2.length() << endl;
		outputFile << "Time Elapsed : " << timeUsed << " ms" << endl;

	}

	outputFile.close();

	//From http://www.cplusplus.com/forum/beginner/1988/
	//This ensures that the console stays open until the user presses enter to exit
	std::cout << '\n' << "Press ENTER to continue...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cin.get();
	return 0;
}
