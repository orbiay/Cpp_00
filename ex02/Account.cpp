/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:53:10 by orbiay            #+#    #+#             */
/*   Updated: 2022/08/23 20:57:58 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include<iostream>

int	Account ::_nbAccounts = 0;
int	Account ::_totalAmount = 0;
int	Account ::_totalNbDeposits = 0;
int	Account ::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
	time_t current_time = time(0);
	tm *time = localtime(&current_time);
	
	std :: cout << "[" <<  time->tm_year + 1900 ;
	if (time->tm_mon < 10)
		std :: cout << "0";
	std :: cout << time->tm_mon + 1;
	if (time->tm_mday < 10)
		std :: cout << "0";
	std :: cout << time->tm_mday;
	std :: cout << "_";
	if (time->tm_hour < 10)
		std :: cout << "0";
	if (time->tm_hour < 10)
		std :: cout << "0";
	std :: cout << time->tm_hour << time->tm_min << time->tm_sec << "]  ";
}

Account :: ~Account( void )
{
	_displayTimestamp();
	std :: cout << "index:" << _accountIndex << ";";
	std :: cout << "amount:" << _amount << ";";
	std :: cout << "closed";
	std :: cout << "\n";
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_nbWithdrawals = 0;
	_nbDeposits = 0;
	_displayTimestamp();
	std :: cout << "index:" << _accountIndex << ";";
	std :: cout << "amount:" << _amount << ";";
	std :: cout << "created";
	std :: cout << "\n";
}

void Account:: displayAccountsInfos(void)
{
	_displayTimestamp();
	std :: cout <<"accounts:" << _nbAccounts <<" ;"<< "total:"<< _totalAmount
	<< " ;" << "deposits:" << _totalNbDeposits << " ;"<< "withdrawals:" << _totalNbWithdrawals;
	std :: cout << "\n";
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std :: cout << "index:" << _accountIndex << ";";
	std :: cout << "amount:" << _amount << ";";
	std :: cout << "deposits:" << _nbDeposits << ";";
	std :: cout << "whithdrawals:" << _nbWithdrawals << ";";
	std :: cout << "\n";
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	_totalAmount += deposit;
	_totalNbDeposits++;
	std :: cout << "index:" << _accountIndex << ";";
	std :: cout << "p_amount:" << _amount << ";";
	std :: cout << "deposits:" << deposit << ";";
	_amount = _amount + deposit;
	std :: cout << "amount:" << _amount << ";";
	_nbDeposits += 1;
	std :: cout << "nb_deposits:" << _nbDeposits << ";";
	std :: cout << "\n";
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	_totalNbWithdrawals++;
	std :: cout << "index:" << _accountIndex << ";";
	std :: cout << "p_amount:" << _amount << ";";
	if (_amount < withdrawal)
	{
		std :: cout << "whithdrawals: refused";
		_totalNbWithdrawals--;
		std:: cout <<"\n";
		return (false);
	}
	_totalAmount -= withdrawal;
	std :: cout << "whithdrawals:" << withdrawal << ";";
	_amount -= withdrawal;
	std :: cout << "amount:" << _amount << ";";
	_nbWithdrawals += 1;
	std :: cout << "nb_whithdrawals:" << _nbWithdrawals << ";";
	std :: cout << "\n";
	return (true);
}

