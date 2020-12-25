#pragma once
#include "File_Helper.h"
#include "President.h"
#include <ctime>

const unsigned short person_count = 6;


class Person
{

private:
	President* president_address;
	unsigned short* count;


	std::string name;
	std::string surname;
	unsigned short age;
	std::string speciality;
	char vote_date_time[26];

	std::string president_name;

	std::string Get_president_name() const
	{
		return president_name;
	}

public:

	Person() :president_address(nullptr), count(nullptr), name(""), surname(""), age(0), speciality(""), vote_date_time("")
	{}

	Person(const std::string& name, const std::string& surname, const short& age, const std::string& speciality)
	{
		Set_name(name);
		Set_surname(surname);
		Set_age(age);
		Set_speciality(speciality);
	}

	void Set_name(const std::string& name)
	{
		if (name.empty())
			throw std::string("Name is Empty!");

		this->name = name;
	}
	std::string Get_name() const
	{
		return name;
	}

	void Set_surname(const std::string& surname)
	{
		if (surname.empty())
			throw std::string("Surname is Empty!");

		this->surname = surname;
	}
	std::string Get_surname() const
	{
		return surname;
	}

	void Set_age(const short& age)
	{
		if (age < 18)
			throw std::string("Your age is smaller than 18!");

		this->age = age;
	}	
	unsigned short Get_age() const
	{
		return age;
	}

	void Set_speciality(const std::string& speciality)
	{
		if (speciality.empty())
			throw std::string("Speciality is Empty!");

		this->speciality = speciality;
	}
	std::string Get_speciality() const
	{
		return speciality;
	}

	void Set_vote_date_time(const std::string& date)
	{
		for (unsigned short i = 0; i < date.length(); i++)
		{
			vote_date_time[i] = date[i];
		}		
	}

	const char* Get_vote_date_time() const
	{
		return vote_date_time;
	}

	void Send_vote_for(President* const& president_address)
	{
		this->president_address = president_address;
		count = new unsigned short(1U);
		time_t now = time(NULL);
		ctime_s(vote_date_time, 26 * sizeof(char), &now);
	}

	unsigned short Get_vote_count() const
	{
		return *count;
	}

	President* Get_president() const
	{
		return president_address;
	}

	void Set_president_name(const std::string& president_name)
	{
		this->president_name = president_name;
	}

	std::string Voted_president_name() const
	{
		return Get_president()->Get_name();
	}

	void Set_all_information_to_file()
	{
		std::string text;
		text.append(Get_name() + '\n');
		text.append(Get_surname() + '\n');
		text.append(std::to_string(Get_age()) + '\n');
		text.append(Get_speciality() + '\n');
		text.append(static_cast<std::string>(vote_date_time));
		text.append(Voted_president_name() + "\n\n");

		FileHelper::Write_file(text);
	}

	Person(const Person& person)
	{
		Set_name(person.name);
		Set_surname(person.surname);
		Set_age(person.age);
		Set_speciality(person.speciality);

		if (person.president_address != nullptr)
		{
			this->president_address = person.president_address;
			this->count = person.count;
			(*count)++;
		}
	}

	Person& operator = (const Person& person)
	{
		if (this->president_address == person.president_address)
		{
			delete count;
			this->count = person.count;
			(*count)++;

			return *this;
		}

		else if (count != nullptr)
		{
			(*count)--;
			if (*count == 0)
			{
				delete president_address;
				delete count;
			}
		}

		if (person.count != nullptr)
		{
			count = person.count;
			this->president_address = person.president_address;
			(*count)++;
		}

		return *this;
	}

	void Show() const
	{
		std::cout << "Person Name: " << Get_name() << '\n';
		std::cout << "Person Surname: " << Get_surname() << '\n';
		std::cout << "Person Age: " << Get_age() << '\n';
		std::cout << "Person Speciality: " << Get_speciality() << '\n';
		std::cout << "Person Vote Time: " << Get_vote_date_time() << '\n';
		std::cout << "Chosen President: " << Get_president_name() << "\n\n";
	}

	~Person()
	{
		if (count != nullptr)
		{
			(*count)--;
			if (*count == 0)
			{
				delete president_address;
				delete count;
			}
		}
	}
};

Person* Read_file()
{
	std::ifstream fin(FileHelper::file_name, std::ios_base::in);
	
	Person* person = new Person[person_count]{};

	if (fin.is_open())
	{
		for (unsigned short i = 0; i < person_count; i++)
		{
			std::string buffer{};
			int age{};

			fin >> buffer;
			person[i].Set_name(buffer);
			buffer.empty();

			fin >> buffer;
			person[i].Set_surname(buffer);
			buffer.empty();

			fin >> age;
			person[i].Set_age(age);

			fin >> buffer;
			buffer.empty();

			std::getline(fin, buffer);
			person[i].Set_speciality(buffer);
			buffer.empty();

			std::getline(fin, buffer);
			person[i].Set_vote_date_time(buffer);
			buffer.empty();

			std::getline(fin, buffer);
			person[i].Set_president_name(buffer);
			buffer.empty();
		}

		fin.close();
	}

	return person;

}