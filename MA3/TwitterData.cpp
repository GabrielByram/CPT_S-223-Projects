#include "TwitterData.hpp"

std::string TwitterData::getUserName() const
{
	return *(this->mpUserName);
}

std::string TwitterData::getActualName() const
{
	return *(this->mpActualName);
}

std::string TwitterData::getEmail() const
{
	return *(this->mpEmail);
}

std::string TwitterData::getCategory() const
{
	return *(this->mpCategory);
}

int TwitterData::getNumTweets() const
{
	return *(this->mpNumTweets);
}

void TwitterData::setUserName(const std::string& newUserName)
{
	this->mpUserName = new std::string;
	*(this->mpUserName) = newUserName;
}

void TwitterData::setActualName(const std::string& newActualName)
{
	this->mpActualName = new std::string;
	*(this->mpActualName) = newActualName;
}

void TwitterData::setEmail(const std::string& newEmail)
{
	this->mpEmail = new std::string;
	*(this->mpEmail) = newEmail;
}

void TwitterData::setCategory(const std::string& newCategory)
{
	this->mpCategory = new std::string;
	*(this->mpCategory) = newCategory;
}

void TwitterData::setNumTweets(const int& newNumTweets)
{
	this->mpNumTweets = new int;
	*(this->mpNumTweets) = newNumTweets;
}

void TwitterData::printTwitterData(void) {
	std::cout << this->mpUserName;
}