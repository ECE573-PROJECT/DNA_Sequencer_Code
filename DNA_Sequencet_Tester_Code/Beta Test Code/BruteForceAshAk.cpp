/*
The code is based on the a class project at Rutgers University.

Project Title : DNA Sequencer Detector
Class : Data Structures and Algorithms
Course No : ECE573
Professor : Jha
Semester : Spring 2018
Written by Divyaprakash Dhurandhar and Anirudh Kulkarni
Debugged by Divyaprakash Dhurandhar and Anirudh Kulkarni
Tested by Divyaprakash Dhurandhar and Anirudh Kulkarni

Group Participants : Divyaprakash Dhurandhar, Tina Drew, Anirudh Kulkarni, and Juhi Tripathi

This code creates was use implement the brute force algorithm on DNA sequences
*/

// C program for Naive Pattern Searching algorithm
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<fstream>
#include<ctime>

using namespace std;
ifstream file;
double start, stop;

void search(char* pat, char* txt)
{
	int M = strlen(pat);
	int N = strlen(txt);

	/* A loop to slide pat[] one by one */
	for (int i = 0; i <= N - M; i++)
	{
		int j;
		/* For current index i, check for pattern match */
		for (j = 0; j < M; j++)
			if (txt[i + j] != pat[j])
				break;

		if (j == M) // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
			cout<<"Pattern found at index :"<< i<<"\n";
	}
}

/* Driver program to test above function */
int main()
{
	string mystr;
	cout<<"Enter DNA Sequence\n";
	cin >> mystr;
	const int n = mystr.length();
	char* pat = new char[n+1];
	strcpy(pat, mystr.c_str());
	char txt[] = "ACAAGATGCCATTGTCCCCCGGCCTCCTGCTGCTGCTGCTCTCCGGGGCCACGGCCACCGCTGCCCTGCCCCTGGAGGGTGGCCCCACCGGCCGAGACAGCGAGCATATGCAGGAAGCGGCAGGAATAAGGAAAAGCAGCCTCCTGACTTTCCTCGCTTGGTGGTTTGAGTGGACCTCCCAGGCCAGTGCCGGGCCCCTCATAGGAGAGGAAGCTCGGGAGGTGGCCAGGCGGCAGGAAGGCGCACCCCCCCAGCAATCCGCGCGCCGGGACAGAATGCCCTGCAGGAACTTCTTCTGGAAGACCTTCTCCTCCTGCAAATAAAACCTCACCCATGAATGCTCACGCAAGTTTAATTACAGACCTGAA";
	//char txt[] = "AABAACAADAABAAABAA";
	//char pat[] = "AABA";
	search(pat, txt);
	return 0;
}
#endif
