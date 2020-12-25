#pragma once
#include <fstream>
#include <sstream>

class FileHelper
{

public:
	const static std::string file_name;

	static void Write_file(const std::string& text)
	{
		std::ofstream fout(file_name, std::ios_base::app);

		if (fout.is_open())
		{
			fout << text;
			fout.close();
		}
	}
};