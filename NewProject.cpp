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
	int V;

public:

	void input(string str,int l) 
	{
		V = str.length() / l;
		string stri;
		ht = new list<string>[V];
		long weight = 0;
		for (int i = 0; i <= str.length()-l; i++)
		{
			for(int k=0;k<l;k++)
				weight += str[i+k];
			weight = weight%V;
			stri = str.substr(i,l);
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

	string pattern() {
		string x;
		ifstream file;
		file.open("case3-pattern.txt");
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
		int count = 0;
		list<string>::iterator it;
		for (int i = 0; i <= str.length()-l; i++)
		{
			for(int k=0;k<l;k++)
				w += str[i+k];
			w = w%V;
			stri = str.substr(i, l);
			for (it = ht[w].begin(); it != ht[w].end(); it++)
			{
				if (*it == stri)
				{
					count++;
				}
			}
			w = 0;
		}
		cout << "Total " << count << " locations matched!" << endl;
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

