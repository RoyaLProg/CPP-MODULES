#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <locale>

int Account::_nbAccounts = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
int	Account::_totalAmount = 0;

Account::Account(int initial_deposit){
	_totalAmount += initial_deposit;
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	this->_amount = initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" 
				<< "amount:" << initial_deposit << ";" 
				<< "created" << std::endl;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
}

Account::~Account(void)
{
	_nbAccounts--;
	_totalAmount -= this->_amount;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
				<< "amount:" << this->_amount << ";"
				<< "closed" << std::endl;
}

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"
			<< "total:" << getTotalAmount() << ";" 
			<< "deposits:" << getNbDeposits() << ";" 
			<< "withdrawals" << getNbDeposits() << std::endl;
}

void	Account::_displayTimestamp(void)
{
	struct tm *tm;
	time_t x = 0;
	std::locale loc;
	const std::time_put<char>& tmput = std::use_facet <std::time_put<char> > (loc);

	x = std::time(NULL);
	tm = std::localtime(&x);
	std::string pattern ("[%Y%m%d_%H%M%S] ");
  	tmput.put (std::cout, std::cout, ' ', tm, pattern.data(), pattern.data()+pattern.length());
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			<< "amount:" << this->_amount << ";" 
			<< "deposits:" << this->_nbDeposits << ";" 
			<< "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			<< "p_amount:" << this->_amount << ";"
			<< "deposit:" << deposit << ";"
			<< "amount:" << this->_amount + deposit << ";"
			<< "nb_deposits" << this->_nbDeposits + 1 << std::endl;
	this->_amount += deposit;
	_totalAmount += deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int	p_amount = this->_amount;

	_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";"
				<< "p_amout:" << p_amount << ";";
	if (p_amount - withdrawal < 0)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << "withdrawal:" << withdrawal <<  ";"
			<< "amount:" << this->_amount << ";"
			<< "nb_deposits:" << this->_nbDeposits << std::endl; 
	return (true);
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}
