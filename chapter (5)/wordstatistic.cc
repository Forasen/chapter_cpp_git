/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

struct Record
{
	std::string word;
	int freq;
};

class WordStatistic
{
public:
	void read_file(const std::string &filename);

	void write_file(const std::string &filename);

private:
	std::vector<Record> dict_;
};

void WordStatistic::read_file(const std::string &filename)
{
	std::ifstream ifs(filename.c_str());
	if(!ifs.good())
	{
		std::cout << "ifstream error" << std::endl;
		return;
	}

	std::string line;
	while(getline(ifs, line))
	{
		std::cout << "@@" << line << std::endl;
		std::stringstream ss(line);
		std::string word;
		while(ss >> word)
		{
			std::cout << "##" << word << std::endl;

			std::vector<Record>::iterator it;
			for(it = dict_.begin(); it != dict_.end(); ++it)
			{
				if(word == (it->word))
				{
					++(it->freq);
					break;
				}
			}

			if(it == dict_.end())
			{
				Record tmp;
				tmp.word = word;
				tmp.freq = 1;
				dict_.push_back(tmp);
			}
		}
	}
	ifs.close();
}

void WordStatistic::write_file(const std::string & filename)
{
	std::ofstream ofs(filename.c_str());
	if(!ofs.good())
	{
		std::cout << "ofstream error" << std::endl;
		return ;
	}
	
	std::vector<Record>::iterator it;
	for(it = dict_.begin(); it != dict_.end(); ++it)
	{
		ofs << it->word << " " << it->freq << std::endl;
	}

	ofs.close();
}

int main(void)
{
	std::string infilename = "/home/luo/test/bible.txt";
	std::string outfilename = "dict.dat";
	WordStatistic ws;
	ws.read_file(infilename);
	ws.write_file(outfilename);

	return 0;
}
