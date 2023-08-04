/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 08:19:32 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/04 16:38:31 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

// Private Constructor
Account::Account( void ) : _accountIndex(0), _amount(0), _nbDeposits(0), _nbWithdrawals(0) {
	return ;
}

// Public Constructor
Account::Account( int initial_deposit ) : _amount(initial_deposit) {
	this->_accountIndex = Account::getNbAccounts();
	Account::_nbAccounts += 1;
	Account::_totalAmount += initial_deposit;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
	return ;
}

// Public Destructor
Account::~Account( void ) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
	return ;
}


// Getters
int	Account::getNbAccounts( void ) {
	return Account::_nbAccounts;
}

int	Account::getTotalAmount( void ) {
	return Account::_totalAmount;
}

int	Account::getNbDeposits( void ) {
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
	return Account::_totalNbWithdrawals;
}


// Displayers
void	Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
	return ;
}

void	Account::displayStatus( void ) const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
	return ;
}

int	Account::checkAmount( void ) const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << std::flush;
	return this->_amount;
}

void	Account::_displayTimestamp( void ) {
	std::time_t	currentTime = std::time(0);
	std::tm*	timeInfo = std::localtime(&currentTime);
	std::cout << "[";
	std::cout << std::setfill('0') << std::setw(4) << timeInfo->tm_year + 1900;
	std::cout << std::setfill('0') << std::setw(2) << timeInfo->tm_mon + 1;
	std::cout << std::setfill('0') << std::setw(2) << timeInfo->tm_mday;
	std::cout << "_";
	std::cout << std::setfill('0') << std::setw(2) << timeInfo->tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << timeInfo->tm_min;
	std::cout << std::setfill('0') << std::setw(2) << timeInfo->tm_sec % 60;
	std::cout << "] " << std::flush;
	//std::cout << "[19920104_091532] " << std::flush;
	return ;
}

// Utils
void	Account::makeDeposit( int deposit ) {
	long int	finalAmount;

	finalAmount = this->checkAmount() + deposit;
	this->_amount = finalAmount;
	this->_nbDeposits += 1;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += 1;
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits;
	std::cout << std::endl;
	return ;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	long int	finalAmount;

	finalAmount = this->checkAmount() - withdrawal;
	if (finalAmount < 0) {
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}
	this->_amount = finalAmount;
	this->_nbWithdrawals += 1;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals += 1;
	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
	return true;
}

// Static initialization
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
