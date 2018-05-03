// BruteForceJuhi.cpp : Defines the entry point for the console application.


#include "stdafx.h"
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
		file.open("case1-corpus");
		if (file.is_open())
		{
			file >> x;
		}
		else
			cout << "Cant open the file " << endl;
		return x;
	}

	string pattern() {
		string x;
		ifstream file;
		file.open("case1-pattern");
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
		double t = s1.length()-l+1;
		bool flag = true;

		for (int i = 0; i< s1.length()-(l-1); i++)
		{
			for (int j = 0; j < s2.length()-(l-1); j++)
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
				if (flag==1)
					count++;
				flag = 0;

			}
		}

		cout << "count = " << count << endl;
		cout << "t = " << t << endl;
		double x = (double)count / t;
		cout << " " << x * 100 << "% matched!" << endl;
	}

};


int main()
{
	clock_t start, stop;
	brute h;
	string s1, s2;
	s1 = h.corpus();
	s2 = h.pattern();
	cout << "Corpus String : " << s1 << endl;
	cout << "Pattern String : " << s2 << endl;
	int l;
	cout << "Please enter the length of matching sequence" << endl;
	cin >> l;
	start = clock();
	h.compare(s2, s1, l);
	stop = clock();
	cout << "Time Elapsed : " << (double)(stop - start)*1000.0 / CLOCKS_PER_SEC << endl;
	return 0;

}

