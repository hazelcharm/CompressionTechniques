//============================================================================
// Name        : Trial3.cpp
// Author      : Sruthi Pasumarthy
// Version     :
// Copyright   : Your copyright notice
// Description : Run-Length Encoding
//============================================================================

#include <iostream>
#include <vector>

using namespace std;


class Compressed
{
	private:
		short int freq;
		string data;

	public:
		Compressed(short int f,string str): freq(f),data(str) { }

		string getData(){
			return data;
		}

		short int getFrequency(){
			return freq;
		}
};



vector<string> input = {"Test","Test","Test","Test","Test","Trial","Trial","Trial","Sample","Sample","Sample","Sample"};
short int fCounter = 0;
vector<Compressed> cObjs;
int size = input.size();
void runLength(int index,string prev, short int fCounter)
{
	if(index == size)
	{
		Compressed obj(fCounter,prev);
		cObjs.push_back(obj);
		return;
	}
	else
	{
		string current = input[index];
		if(current.compare(prev) != 0)
			{
				Compressed obj(fCounter,prev);
				cObjs.push_back(obj);
				fCounter = 1;
				prev = current;
			}
			else
			{
				fCounter++;
			}
			index++;
			runLength(index,prev,fCounter);
	}

}


int main() {
	//cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	//string str = "Test|Test|Test|Test|Test|Trial|Trial|Trial|Sample|Sample|Sample|Sample";
	//vector<string> input = {"Test","Test","Test","Test","Test","Trial","Trial","Trial","Sample","Sample","Sample","Sample"};
	//short int freqCounter = 0;
	//vector<Compressed> compressedObjs;
	string prev = input.front();

	/*for(auto i = input.begin(); i != input.end(); i++ )
	{
		string current = *i;
		if(current.compare(prev) != 0)
		{
			Compressed obj(freqCounter,prev);
			compressedObjs.push_back(obj);
			freqCounter = 1;
			prev = current;
		}
		else
		{
			++freqCounter;

		}
		if(next(i) == input.end())
		{
			Compressed obj(freqCounter,prev);
			compressedObjs.push_back(obj);
		}


	}

	if(compressedObjs.size() > 0)
	{
		cout << "Frequency\t" << "Data"<< endl;
	}

	for(Compressed c : compressedObjs){
		cout<< c.getFrequency() << "\t" << c.getData() << endl;
	}*/
	runLength(0,prev,0);

	for(Compressed c : cObjs){
		cout<< c.getFrequency() << "\t" << c.getData() << endl;
	}
	return 0;
}