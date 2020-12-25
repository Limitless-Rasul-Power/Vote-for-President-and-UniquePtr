#pragma once
#include "Person.h"
#include "Unique_Ptr.h"

void Start()
{
	/*UniquePtr<Person> person_1(new Person("Test", "Testoglu", 1, "Exam"));//works
	UniquePtr<Person> person_2(person_1);//compile error
	UniquePtr<Person> person_3;//works
	person_3 = person_1;//compile error*/



	President* p_1 = new President("John F.Kennedy", "United States of America", 20U);
	President* p_2 = new President("Ronald Reagan", "United States of America", 10U);
	President* p_3 = new President("Barack Obama", "United States of America", 15U);
	President* p_4 = new President("Donald Trump", "United States of America", 5U);

	Person per_1("Mike", "Tyson", 57, "World Best Boxer");
	Person per_2("Kylie", "Tyson", 57, "Information Technology");
	Person per_3("Doanl", "Tyson", 57, "Software Programmer");
	Person per_4("George", "Tyson", 57, "Math Teacher");
	Person per_5("Wahington", "Tyson", 57, "Coach Manager");
	Person per_6("Taylor", "Tyson", 57, "Artist of the Week");


	per_1.Send_vote_for(p_1);
	std::cout << "President Count: " << per_1.Get_vote_count() << '\n';
	per_2.Send_vote_for(p_1);
	per_2 = per_1;
	std::cout << "President Count: " << per_2.Get_vote_count() << '\n';

	per_3.Send_vote_for(p_1);
	per_3 = per_2;
	std::cout << "President Count: " << per_3.Get_vote_count() << "\n\n";


	per_4.Send_vote_for(p_2);
	std::cout << "President Count: " << per_4.Get_vote_count() << '\n';
	per_5.Send_vote_for(p_2);
	per_5 = per_4;
	std::cout << "President Count: " << per_5.Get_vote_count() << "\n\n";

	per_6.Send_vote_for(p_3);
	std::cout << "President Count: " << per_6.Get_vote_count() << "\n\n";


	per_1.Set_all_information_to_file();
	per_2.Set_all_information_to_file();
	per_3.Set_all_information_to_file();
	per_4.Set_all_information_to_file();
	per_5.Set_all_information_to_file();
	per_6.Set_all_information_to_file();


	try
	{
		Person* person = Read_file();
		for (unsigned short i = 0; i < person_count; i++)
		{
			person[i].Show();
		}
		delete[] person;
	}
	catch (const std::string& error)
	{
		std::cout << "Error: " << error << '\n';
	}
}