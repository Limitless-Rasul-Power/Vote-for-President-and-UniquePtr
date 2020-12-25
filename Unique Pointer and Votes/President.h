#pragma once
#include <iostream>
class President
{

private:
	std::string name;
	std::string country;
	unsigned short work_practice;

public:

	President(const std::string& name, const std::string& country, const short work_practice)
	{
		Set_name(name);
		Set_country(country);
		Set_work_practice(work_practice);
	}


	void Set_name(const std::string& name)
	{
		if (name.empty())
			throw "Name is Empty!";

		this->name = name;
	}

	std::string Get_name() const
	{
		return name;
	}

	void Set_country(const std::string& country)
	{
		if (country.empty())
			throw "Country is Empty!";

		this->country = country;
	}

	std::string Get_country() const
	{
		return country;
	}

	void Set_work_practice(const short& work_practice)
	{
		if (work_practice <= 0)
			throw "Work Practice must be more than 0!";

		this->work_practice = work_practice;
	}

	unsigned short Get_work_practice() const
	{
		return work_practice;
	}

	void Show() const
	{
		std::cout << "President Name: " << Get_name() << '\n';
		std::cout << "President Country: " << Get_country() << '\n';
		std::cout << "President Work Practice: " << Get_work_practice() << "\n\n";
	}

};