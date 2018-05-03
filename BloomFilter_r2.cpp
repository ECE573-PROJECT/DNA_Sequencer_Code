// BloomFilter.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <list>
#include "time.h"
#include <iterator>
#include <string>
#include <fstream>

using namespace std;
using byte = unsigned char;

class hasht {
	byte *arr;

public:

	void input(string str, int l)
	{
		int V = str.length() / l;
		arr = new byte[V];
		for (int j = 0; j < V; j++)
			arr[j] = 0;
		long weight = 0;
		for (int i = 0; i != str.length() - l; i++)
		{
			weight += str[i] + str[i + 1] + str[i + 2];
			weight = weight % l;
			arr[weight] = 1;
			weight = 0;
		}
		return;
	}

	string corpus() {
		string x;
		ifstream file;
		file.open("case1-corpus.txt");
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
		int count = 0, t = 0;
		for (int i = 0; i != str.length() - l; i++)
		{
			w += str[i] + str[i + 1] + str[i + 2];
			w = w % l;
			t++;
			if (arr[w] == 1)
			{
				count++;
			}

		}
		double x = (double)count / t;
		cout << " " << x * 100 << "% matched!" << endl;
	}

};

string myFiles[] = { "DNA_String_12.txt", "DNA_String_100.txt", "DNA_String_500.txt", "DNA_String_1000.txt",
"DNA_String_2000.txt", "DNA_String_3000.txt", "DNA_String_4000.txt", "DNA_String_5000.txt","DNA_String_6000.txt",
"DNA_String_7000.txt", "DNA_String_8000.txt", "DNA_String_9000.txt", "DNA_String_10000.txt", };

int main()
{
	float start, stop, timeUsed;
	hasht h;
	string s1, s2;
	s1 = h.corpus();
	
	cout << "Corpus String : " << s1 << endl;
	cout << "Pattern String : " << s2 << endl;
	int l;
	cout << "Please enter the length of matching sequence" << endl;
	cin >> l;
	
	int sizeArr = sizeof(myFiles) / sizeof(myFiles[0]);
	cout << sizeArr;

	for (int a = 0; a < sizeArr; a = a++)
	{
		s2 = h.pattern(myFiles[a]);
		//cout << "Corpus String : " << s1 << endl;
		//cout << "Pattern String : " << s2 << endl;
		start = clock();
		cout << '\n';
		h.input(s1, l);
		h.compare(s2, l);
		stop = clock();
		timeUsed = ((stop - start) / CLOCKS_PER_SEC) * 1000;
		cout << "DNA Size: " << s2.length() << '\n';
		cout << "Time Elapsed : " << timeUsed << " ms" << endl;
	}

	//From http://www.cplusplus.com/forum/beginner/1988/
	//This ensures that the console stays open until the user presses enter to exit
	std::cout << '\n' << "Press ENTER to continue...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cin.get();


	return 0;
}