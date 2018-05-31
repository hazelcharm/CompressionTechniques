//============================================================================
// Name        : RunLengthEncoding.cpp
// Author      : Srilakshmi Sruthi Pasumarthy
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

	string prev = input.front();
	runLength(0,prev,0);

	for(Compressed c : cObjs){
		cout<< c.getFrequency() << "\t" << c.getData() << endl;
	}
	return 0;
}
