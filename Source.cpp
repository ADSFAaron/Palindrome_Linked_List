#include <iostream>
#include <list>
#include <string>
#include <sstream>
using namespace std;

bool palindrone(list<int>& in)
{
	list<int>::iterator it = in.begin();
	list<int>::iterator it_end = in.end();
	--it_end;

	// Run from start list and end list
	while (it != it_end)
	{
		if (*it != *it_end)
		{
			return false;
		}

		++it;

		// Determine the size is even, should have difference break condition
		if (in.size() % 2 == 0)
		{
			if (it == it_end)
			{
				break;
			}
		}
		--it_end;
	}

	return true;

}

int main()
{
	list<int> input;
	list<int>::iterator it;
	string in;
	getline(cin, in);
	stringstream ss(in);

	// Input pattern
	while (getline(ss, in, '-'))
	{
		// split '>' char
		if (in[0] == '>')
		{
			for (int i = 0; i < in.size() - 1; ++i)
			{
				in[i] = in[i + 1];
			}

			in.pop_back();
		}

		input.push_back(stoi(in));
	}

	bool result = palindrone(input);

	//for (it = input.begin(); it != input.end(); ++it)
	//{
	//	cout << *it << endl;
	//}

	if (result)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	system("pause");
}