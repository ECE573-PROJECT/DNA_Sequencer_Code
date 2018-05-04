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

	void compare(string s1, string s2, int l)
	{
		double count = 0;
		double t = s1.length() - l + 1;
		bool flag = true;

		for (int i = 0; i< s1.length() - (l - 1); i++)
		{
			for (int j = 0; j < s2.length() - (l - 1); j++)
			{
				for (int k = 0; k < l; k++)
				{
					if (s1[i + k] == s2[j + k])
					{
						flag = 1;
						continue;
					}
					else
					{
						flag = 0;
						break;
					}
				}
				if (flag == 1)
					count++;
				flag = 0;

			}
		}

		//cout << "count = " << count << endl;
		//cout << "t = " << t << endl;
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
	brute h;
	string s1, s2;
	s1 = h.corpus();

	int l;
	cout << "Please enter the length of matching sequence" << endl;
	cin >> l;

	ofstream outputFile;
	outputFile.open("Results_BruteForce.txt");
	outputFile << "Sequence Length " << l << endl;

	//Run the Brute Force DNA matching for all DNA string files in the "myFiles" array
	int sizeArr = sizeof(myFiles) / sizeof(myFiles[0]);
	cout << sizeArr;
	for (int a = 0; a < sizeArr; a = a++)
	{
		s2 = h.pattern(myFiles[a]);
		//cout << "Corpus String : " << s1 << endl;
		//cout << "Pattern String : " << s2 << endl;

		start = clock();
		cout << '\n';
		outputFile << '\n';
		h.compare(s2, s1, l);
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