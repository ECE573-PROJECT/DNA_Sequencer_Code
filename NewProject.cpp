// NewProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include "time.h"
#include <iterator>
#include <string>
#include <fstream>

using namespace std;

class hasht{
	list<string> *ht;

public:

	void input(string str,int l) 
	{
		int V = str.length() / l;
		string stri;
		ht = new list<string>[V];
		long weight = 0;
		for (int i = 0; i != str.length()-l; i++)
		{
			weight += str[i] + str[i + 1] + str[i + 2];
			weight = weight%l;
			stri = str.substr(i,l);
			ht[weight].push_front(stri);
			weight = 0;
		}
		return;
	}

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

	void compare(string str, int l)
	{
		long w=0;
		string stri;
		int count = 0,t=0;
		list<string>::iterator it;
		for (int i = 0; i != str.length()-l; i++)
		{
			w += str[i] + str[i + 1] + str[i + 2];
			w = w%l;
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
		cout << " " << x*100  <<"% matched!"<< endl;
}

};


int main()
{
	clock_t start, stop;
	hasht h;
	string s1, s2;
	s1 = h.corpus();
	s2 = h.pattern();
	cout << "Corpus String : " << s1 << endl;
	cout << "Pattern String : " << s2 << endl;
	int l;
	cout << "Please enter the length of matching sequence"<<endl;
	cin >> l;
	h.input(s1,l);
	start = clock();
	h.compare(s2,l);
	stop = clock();
	cout << "Time Elapsed : " << (double)(stop - start)*1000.0 / CLOCKS_PER_SEC << endl;
	return 0;
}

