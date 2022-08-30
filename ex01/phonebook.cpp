/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:18:50 by orbiay            #+#    #+#             */
/*   Updated: 2022/08/21 16:19:35 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "contact.hpp"

std :: string again(std :: string Q)
{
	std :: string str = "";
	while (str.empty())
	{
		std :: cout << Q;
		getline(std :: cin,str);
	}
	return (str);
}
contact add (void)
{
	contact cont;
	std :: string str;
	/////////////FIRST NAME/////////////////
	std :: cout << "Enter Your First Name : " << std::ends;
	std::getline(std::cin, cont.firstname);
	if (cont.firstname.empty())
		cont.firstname = again("Enter Your First Name : ");
	/////////////LAST NAME//////////////////
	std :: cout << "Enter Your Last Name : ";
	std::getline(std::cin, cont.lastname);
	if (cont.lastname.empty())
		cont.lastname = again("Enter Your Last Name : ");
	////////////NICK NAME///////////////////
	std :: cout << "Enter Your Nick Name : ";
	std::getline(std::cin, cont.nickname);
	if (cont.nickname.empty())
		cont.nickname = again("Enter Your Nick Name : ");
	///////////PHONE NUMBER/////////////////
	std :: cout << "Enter Your Phone Number : ";
	std::getline(std::cin, cont.phonenumber);
	if (cont.phonenumber.empty())
		cont.phonenumber = again("Enter Your Phone Number : ");
	////////////DARKEST SECRET///////////////
	std :: cout << "Enter Your Darkest Secret : ";
	std::getline(std::cin, cont.darkestsecret);
	if (cont.darkestsecret.empty())
		cont.darkestsecret = again("Enter Your Darkest Secret : ");
	return cont;
}

void information(PhoneBook person , int i)
{
	std :: cout << std::setw(10) << i ;
	if (person.contacts[i].firstname.size() > 10)
		std :: cout << " | "  << std::setw(10) << person.contacts[i].firstname.substr(0,9) << ".";
	else
		std :: cout << " | "  << std::setw(10) << person.contacts[i].firstname;
	if (person.contacts[i].lastname.size() > 10)
		std :: cout << " | "  << std::setw(10) << person.contacts[i].lastname.substr(0,9) << ".";
	else
		std :: cout << " | "  << std::setw(10) << person.contacts[i].lastname;
	if (person.contacts[i].nickname.size() > 10)
		std :: cout << " | "  << std::setw(10) << person.contacts[i].nickname.substr(0,9) << ".";
	else
		std :: cout << " | "  << std::setw(10) << person.contacts[i].nickname;
	if (person.contacts[i].phonenumber.size() > 10)
		std :: cout << " | "  << std::setw(10) << person.contacts[i].phonenumber.substr(0,9) << ".";
	else
		std :: cout << " | "  << std::setw(10) << person.contacts[i].phonenumber;
	if (person.contacts[i].darkestsecret.size() > 10)
		std :: cout << " | "  << std::setw(10) << person.contacts[i].darkestsecret.substr(0,9) << ".";
	else
		std :: cout << " | "  << std::setw(10) << person.contacts[i].darkestsecret;
}

void search(PhoneBook person)
{
	std :: string  str;
	int i = 0;
	while (i < 8)
	{
		if (person.contacts[i].firstname.empty())
			break;
		information(person,i);
		std :: cout << "\n";
		i++;
	}
	std :: cout << "what's the contact number you want to show it : ";
	getline (std::cin,str);
	if (str.empty())
		return;
	if (atoi(str.c_str()) >= i)
		std :: cout << "Sorry We Don't Have Any Information About This Contact ." << std :: endl;
	else
	{
		std :: cout << i <<">>>>>>>"  << atoi(str.c_str()) <<std :: endl;
		std :: cout << str << " | " << std::setw(10) << person.contacts[atoi(str.c_str())].firstname << std::setw(10) 
		<< person.contacts[atoi(str.c_str())].lastname << std::setw(10) << person.contacts[atoi(str.c_str())].nickname << "\n";
	}
}

int main ()
{
	int i = 0;
	PhoneBook person;
	std::string  cmd;
	while (1)
	{
		std::cout << "what's your command : ";
		std::getline(std::cin, cmd); ;
		if (cmd == "ADD")
			person.contacts[i++] = add();
		else if (cmd == "SEARCH")
			search(person);
		else if (cmd == "EXIT")
			exit(EXIT_SUCCESS);
		if ( i == 8)
			i = 0;
	}
}