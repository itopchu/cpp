#include "Contact.hpp"

// Constructors
Contact::Contact()
{
	_FirstName = "NAME";
	_LastName = "LASTNAME";
	_NickName = "NICK";
	_PhoneNumber = "0000000000";
	_DarkestSecret = "SECRET";
}

Contact::Contact(const Contact &copy)
{
	_FirstName = copy.getFirstName();
	_LastName = copy.getLastName();
	_NickName = copy.getNickName();
	_PhoneNumber = copy.getPhoneNumber();
	_DarkestSecret = copy.getDarkestSecret();
}

Contact::Contact(std::string FirstName, std::string LastName, std::string NickName, std::string PhoneNumber, std::string DarkestSecret)
{
	_FirstName = FirstName;
	_LastName = LastName;
	_NickName = NickName;
	_PhoneNumber = PhoneNumber;
	_DarkestSecret = DarkestSecret;
}


// Destructor
Contact::~Contact()
{
	
}

bool Contact::getInput(std::string &buf, int type, std::string &message)
{
	while (1)
	{
		std::cout << message;
		if (!std::getline(std::cin, buf))
		{
			if (std::cin.eof())
			{
				std::cout << "EOF received" << std::endl;
				return (false);
			}
		}
		if (buf.empty())
			std::cout << RED << "Empty input is not accepted" << DEFCOLOR << std::endl;
		else if (type == 0 && isCompare(buf, isalpha) == false)
			std::cout << RED << "Non alpha input is not accepted" << DEFCOLOR << std::endl;
		else if (type == 1 && isCompare(buf, isdigit) == false)
			std::cout << RED << "Non digit input is not accepted" << DEFCOLOR << std::endl;
		else
			break ;
	}
	return (true);
}

bool	Contact::isCompare(std::string str, int (*compare)(int))
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (compare(str[i])== 0)
			return (false);
	}
	return (true);
}

// Operators
Contact & Contact::operator=(const Contact &assign)
{
	_FirstName = assign.getFirstName();
	_LastName = assign.getLastName();
	_NickName = assign.getNickName();
	_PhoneNumber = assign.getPhoneNumber();
	_DarkestSecret = assign.getDarkestSecret();
	return *this;
}


// Getters / Setters
std::string Contact::getFirstName() const
{
	return _FirstName;
}

bool Contact::setFirstName()
{
	std::string message = BLUE;
	message += "First Name: ";
	message += DEFCOLOR;
	return (getInput(this->_FirstName, 0, message));
}

std::string Contact::getLastName() const
{
	return _LastName;
}
bool Contact::setLastName()
{
	std::string message = BLUE;
	message += "Last Name: ";
	message += DEFCOLOR;
	return (getInput(this->_LastName, 0, message));
}

std::string Contact::getNickName() const
{
	return _NickName;
}
bool Contact::setNickName()
{
	std::string message = BLUE;
	message += "Nick Name: ";
	message += DEFCOLOR;
	return (getInput(this->_NickName, 0, message));
}

std::string Contact::getPhoneNumber() const
{
	return _PhoneNumber;
}
bool Contact::setPhoneNumber()
{
	std::string message = BLUE;
	message += "Phone Number: ";
	message += DEFCOLOR;
	return (getInput(this->_PhoneNumber, 1, message));
}

std::string Contact::getDarkestSecret() const
{
	return _DarkestSecret;
}
bool Contact::setDarkestSecret()
{
	std::string message = BLUE;
	message += "Darkest Secret: ";
	message += DEFCOLOR;
	return (getInput(this->_DarkestSecret, 2, message));
}
