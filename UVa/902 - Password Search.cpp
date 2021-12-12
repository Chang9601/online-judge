#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(int argc, char *argv[])
{
	int N;
	string text;

	while(cin >> N >> text)
	{
		int i, text_len, max_freq;
		map<string, int> freq;
		string substr, ans;	

		text_len = text.size();
		max_freq = -1;
		for(i = 0; i + N <= text_len; i++)
		{
			substr.assign(text, i, N);
			freq[substr]++;
			if(max_freq < freq[substr])
			{
				max_freq = freq[substr];
				ans = substr;
			}
		}

		printf("%s\n", ans.c_str());
	}
	return 0;
}
