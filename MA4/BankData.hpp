#ifndef BANK_DATA_H
#define BANK_DATA_H

#include <iostream>

class BankData
{
public:
	// Are the Big Five necessary?
	// How will this data work with the std::map?

	int getAcctNum() const; // we do want to return a copy of the int, not the pointer
	double getSavingsAmount() const; // we do want to return a copy of the double, not the pointer
	double getCheckingAmount() const; // we do want to return a copy of the double, not the pointer

	void setAcctNum(const int& newAcctNum);
	void setSavingsAmount(const double& newSavingsAmount);
	void setCheckingAmount(const double& newCheckingAmount); 

	friend std::ostream& operator << (std::ostream &out, const BankData &bank);

private:
	int* mpAcctNum;
	double* mpSavingsAmount, * mpCheckingAmount;
};

#endif

