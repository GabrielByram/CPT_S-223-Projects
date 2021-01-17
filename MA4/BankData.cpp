#include "BankData.hpp"

// getters

int BankData::getAcctNum() const
{
	return *(this->mpAcctNum);
}

double BankData::getSavingsAmount() const
{
	return *(this->mpSavingsAmount);
}

double BankData::getCheckingAmount() const
{
	return *(this->mpCheckingAmount);
}

// setters

void BankData::setAcctNum(const int& newAcctNum)
{
	this->mpAcctNum = new int;
	*(this->mpAcctNum) = newAcctNum;
}

void BankData::setSavingsAmount(const double& newSavingsAmount)
{
	this->mpSavingsAmount = new double;
	*(this->mpSavingsAmount) = newSavingsAmount;
}

void BankData::setCheckingAmount(const double& newCheckingAmount)
{
	this->mpCheckingAmount = new double;
	*(this->mpCheckingAmount) = newCheckingAmount;
}


// overloads << operator for use with bank account
std::ostream& operator << (std::ostream &out, const BankData &bank) {
	out << "Bank Account #" << bank.getAcctNum() << std::endl;
	return out;
}
