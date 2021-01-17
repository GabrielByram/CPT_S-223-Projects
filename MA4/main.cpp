/*
Gabriel Byram
November 9, 2020
MA4

*     (4 pts) Assuming that the underlying hash table created cannot be resized, and that the hash function is poor, what is the worst-case Big-O for inserting key-value pairs based on a key? List any other assumptions that you make.

It would be O(n) because worst-case scenario it would have to go through each element in the hash table to find a suitable location to insert

*     (4 pts) Let’s say that the underlying hash table uses linear probing, what is the worst-case Big-O for retrieving data based on a key? List any assumptions that you make.

O(n) because in the worst-case the element had to be inserted in the only open location left that is the farthest from the place it was supposed to be inserted into. This
means that to retrieve it we must go through the entire hash table.

*     (4 pts) Let’s say the underlying hash table uses chaining, what is the worst-case Big-O for deleting key-value pairs based on a key? List any assumptions that you make.

O(n) because it's possible the key-value pair we want to delete is at the end of a list on a location that all the other values in the hash table were inserted into.

*     (4 pts) What is the worst-case Big-O for iterating through the entire unordered map? List any assumptions that you make.

O(n) because it must go through each element

*     (4 pts) Based on your conclusions of the tasks that were performed in this assignment, when and why should we use an unordered map?

We should use unordered maps when the data we need to store needs to be accessed quickly but doesn't need to be stored in order. This is because unordered maps have
very fast average time complexity but they do not store things in order, as demonstrated by printing out each account with their corresponding bucket

*     (10 pts) Is an std::unordered_map a robust choice for storing, removing, and searching bank accounts? Explain.

Yes, because it is a data structure that can hold significant amounts of information while also boasting an efficient average time complexity (although this does
depend on the hash function being designed efficiently). For bank accounts specifically, they do not necessary need to be stored in a specific order, which means
that the disadvantage of loss of organization does not affect storing bank accounts. Overall, unorganized maps are not always good data structures to use if a specific
order is required for your data, but for bank accounts, which do not need to be stored in a particular order, they are a good choice.

*/

#include <unordered_map>
#include "BankData.hpp"
#include <fstream>

int main(int argc, char* argv[])
{
	// we need a unordered map to store our key and mapped values
	// std::unordered_map<keyType, ValueType>; What should the key be? What about the value?
	std::unordered_map<int, BankData> bankHash;

	// open file
	std::ifstream iFile;
	iFile.open("BankAccounts.csv");

	// read first line of data in to get rid of it
	char tempLine[200];
	iFile.getline(tempLine, 200);

	// variables to store string variables
	std::string bankNumStr = "", savAccStr = "", checkAccStr = "";
    std::string delimiter = ",";
    size_t pos = 0;

	for (int i = 0; i < 10; i++) {
		BankData newBank;

		iFile.getline(tempLine, 100);
		std::string bankInfo(tempLine); // create std:string
		pos = bankInfo.find(delimiter);
		bankNumStr = bankInfo.substr(0, pos); // store info
		bankInfo.erase(0, pos + delimiter.length()); // increment to next word in read line

		pos = bankInfo.find(delimiter); // repeat process for savings
		savAccStr = bankInfo.substr(0, pos);
		bankInfo.erase(0, pos + delimiter.length());

		pos = bankInfo.find(delimiter); // repeat process for checking
		checkAccStr = bankInfo.substr(0, pos);
		bankInfo.erase(0, pos + delimiter.length());

		// store info into bank account
		int bankNum = std::stoi(bankNumStr);
		newBank.setAcctNum(bankNum);
		double savAcc = stod(savAccStr);
		newBank.setSavingsAmount(savAcc);
		double checkAcc = stod(checkAccStr);
		newBank.setCheckingAmount(checkAcc);

		std::cout << "Account " << i << ": " << newBank.getAcctNum() << " " << newBank.getCheckingAmount() << " " << newBank.getSavingsAmount() << std::endl; // print account info

		bankHash[newBank.getAcctNum()] = newBank; // insert into hash table

		std::cout << "Account number " << i+1 << " inserted into bucket #" << bankHash.bucket(newBank.getAcctNum()) << std::endl << std::endl; // print bucket numbers
	}

	// print amount of buckets
	std::cout << "Number of buckets: " << bankHash.bucket_count() << std::endl;
	// print max size
	std::cout << "Max number of buckets in the container: " << bankHash.max_bucket_count() << std::endl << std::endl;

	// iterate through and print each key-value pair
	for (auto it = bankHash.begin(); it != bankHash.end(); it++) {
		std::cout << it->first << ", " << it->second;
	}

	std::cout << "\n";

	// delete 11111111 account
	bankHash.erase(11111111);

	// print hash table again
	for (auto it = bankHash.begin(); it != bankHash.end(); it++) {
		std::cout << it->first << ", " << it->second;
	}

	// print number of buckets again
	std::cout << "Number of buckets: " << bankHash.bucket_count() << std::endl;

	return 0;
}