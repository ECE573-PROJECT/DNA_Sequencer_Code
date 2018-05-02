//DNA Sequence Tester 
//This program was created just to test the C++ functionality. 

//List libraries that need to be included
#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <chrono>


using namespace std;


//The class below is used to implement the Brute force algorithm for 
//Search two DNA strings for matching patterns
class DnaBruteForce
{
public:
	vector<char> s1;
	vector<char> s2;
	vector<char> s3;
	vector<int> patternMatchInd;

public:
	void setStrings(vector<char>x, vector<char>y)
	{
		s1 = {}; 
		s2 = {};
		s1 = x;
		s2 = y;
	}

	//Get set of values to searh for in the vector
	//k is the size of the set
public:
	vector<char> getSet(vector<char> vect, int pointer, int k)
	{
		//s3 = {};
		vector<char> myDnaString;
		for (int i = 1; i <= k; i++)
			myDnaString.push_back(vect[pointer + i - 1]);

		return myDnaString;
	}

private:
	void printStuff(char printI)
	{
		if (printI == 'Y' || printI == 'y')
		{
			cout << '\n' << "Pattern Set:";
			for (vector<char>::iterator it = s3.begin(); it != s3.end(); ++it)
				cout << ' ' << *it;

			//Outputs data to screen
			int x = patternMatchInd.size();
			if (x > 0)
			{
				cout << '\n' << "Pattern Location: ";
				for (vector<int>::iterator it = patternMatchInd.begin(); it != patternMatchInd.end(); ++it)
					cout << ' ' << *it;
			}
			else
			{
				cout << '\n' << "Pattern not found ";
			}
		}
	}


	//Searches s2 for pattern matches
public:
	vector<char> searchSet(char prt)
	{

		cout << '\n';
		int pointer = 0;
		int y = s1.size();
		int z = s2.size();
		int kMax = min(y, z) - 2;
		
		//cout << kMax << '\n';
		for (int k = 2; k <= kMax; k = k++)
		{
			if (prt == 'Y' || prt == 'y')
				cout <<'\n'; 
		
			for (int i = 0; i < y - k; i = i++)
			{
				s3 = {};
				patternMatchInd = {};
				s3 = getSet(s1, i, k);
		
				for (int j = 0; j < z -k- 1; j = j++)
				{
					//cout <<j <<'\n'; 
					if (s3 == getSet(s2, j, k))
						patternMatchInd.push_back(j);
				}


				printStuff(prt);
			}
		}

		return s3;
	}

};


//Generates random array based on DNA data symbols
vector<char> genDnaString(int N)
{
	char symbols[] = { 'a', 'c', 'g', 't' };
	vector<char> myvector;

	//http://www.cplusplus.com/reference/vector/vector/begin/
	for (int i = 1; i <= N; i++)
		myvector.push_back(symbols[rand() % 4]);

	return myvector;
}


//Outputs array of characters to screen in array format
void printArray(char arr[])
{
	int size = sizeof(arr);
	cout << '[';
	for (int a = 0; a < size + 1; a = a + 1)
		cout << arr[a] << ' ';
	cout << ']';
}

void printVector(vector<char> myvector)
{
	//code from
	//http://www.cplusplus.com/reference/vector/vector/begin/
	cout << "myvector contains:";
	for (vector<char>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		cout << ' ' << *it;
	cout << '\n';
}

void printVectorFloat(vector<float> myvector)
{
	//code from
	//http://www.cplusplus.com/reference/vector/vector/begin/
	cout << "myvector contains:";
	for (vector<float>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		cout << ' ' << *it;
	cout << '\n';
}

/*Writes vector contents to a text file
void vectorFileWrite(vector<char> vect)
{
	//From https://stackoverflow.com/questions/6406356/how-to-write-vector-values-to-a-file
	ofstream output_file("./example.txt");
	ostream_iterator<string> output_iterator(output_file, "\n");
	copy(vect.begin(), vect.end(), output_iterator);
}*/


vector<char> s1_DNA = { 'a', 'c', 'g', 't', 't', 'c' };
vector<char> s2_DNA = { 'a', 'c', 'c', 'g', 't', 'a', 'c', 'c', 'a', 'c' };
vector<float> timeBrute = {};
int sizeArr;
float start;


//Main function. This operates the main portion of the program
int main()
{
	DnaBruteForce brute;
	//Sets the data string values for s1 and s2 for the 
	brute.s1 = genDnaString(20);
	
	cout << "Would you like to print the data to the screen? Enter Y for yes or N for no: ";
	char prt;
	cin.get(prt);

	int g = 3; 
	int arrN [] = { 100, 200, 500};
	float timeUsed;

	for (int a = 0; a < g; a++)
	{
		brute.s2 = genDnaString(arrN[a]);
		start = clock();
		brute.searchSet(prt);
		timeUsed = (clock() - start) / CLOCKS_PER_SEC;
		timeBrute.push_back(timeUsed);
		cout << arrN[a] << ' ' << timeUsed << '\n';
		//cout << (clock() - start) / CLOCKS_PER_SEC << '\n';
	}

	cout <<'\n'<< "Array of N Values: ";
	for (int a = 0; a < g; a++)
		cout << arrN[a]<<' ';
	cout << '\n';
	printVectorFloat(timeBrute);
	//From http://www.cplusplus.com/forum/beginner/1988/
	//This ensures that the console stays open until the user presses enter to exit
	std::cout << '\n' << "Press ENTER to continue...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cin.get();
	return 0;
}

