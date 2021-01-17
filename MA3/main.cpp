/*
Name: Gabriel Byram
Class: CptS 223
Assignment: MA3
Date: October 14, 2020

*     (2 pts) What piece of data read from the file did you use for the key and why?

I used the username because the username is generally what is used in software to identify users,
so it made sense to use it to identify profiles through using it as a key for our map.

*     (2 pts) Assuming that the map is using a red-black tree, what is the worst-case Big-O for inserting key-value pairs based on a key?

O(log N)

*     (2 pts) Assuming that the map is using a red-black tree, what is the worst-case Big-O for retrieving data based on a key?

O(log N)

*     (2 pts) Assuming that the map is using a red-black tree, what is the worst-case Big-O for deleting key-value pairs based on a key?

O(log N)

*     (2 pts) Assuming that the map is using a red-black tree, what is the worst-case Big-O for iterating through the entire map?

O(N)

*     (5 pts) Based on the specific algorithm that you used to find and remove a key-value pair based on a value, what is the worst-case Big-O?

O(N), because I iterate through the entire map


*     (5 pts) Based on your conclusions of the tasks that were performed in this assignment, when and why should we use a map?

Inserting, retrieving, and deleting all have low time complexities. This makes maps an ideal
data structure for tasks that require many repitions of adding data, finding data, and deleting data.
Maps are also useful whenever the data values we have each correspond to certain values, which we can use as keys.
This means we should use a map for indexes or references, or any time we need to quickly access data that has corresponding
key values, because map allows us to find data with corresponding key values very quickly.


*     (10 pts) Assuming that the “MostViewedCategory” data in the file represents the kind of Tweets that a particular user views frequently.
		Is a map an ideal data structure to use to retrieve this information, especially if we want to use the info for advertising?
		If not, what data structure would you use instead?

No, a map is not ideal because ideally we would have information on a few different favorite categories a user has, so we can advertize a great amount of products.
A map can only hold one variable per key, so it could only hold information on one of the favorite categories. Instead, we should use a linked list. Another
advantage of the linked list is that we can insert the most viewed categories into the front of the linked list, with each place out in the linked list
being a slightly less viewed tweet category, meaning that we see and can access the most important data first.

However, it also depends on how the data is structred in the map. If the data in a map is structured so that each key corresponds to a different category,
instead of one for each person, then maps could also do a good job. However, I still believe a list would do a better job because it could be sorted
by having the most important category at the start.
*/

#include <map>
#include "TwitterData.hpp"
#include <fstream>

int main(int argc, char* argv[])
{
	// we need a map to store our key-value pairs
	// std::map<keyType, ValueType>; What should the key be? What about the value?

	// open file
	std::ifstream iFile;
	iFile.open("TwitterAccounts.csv");

	// read first line of data in to get rid of it
	char tempLine[200];
	iFile.getline(tempLine, 200);

	// variables to store string variables
	std::string uName, actualName, email, numTweets, category;
    std::string delimiter = ",";
    size_t pos = 0;

	// create map
	std::map<std::string, TwitterData> twitMap;

	// read in data from file and place into map
	for (int i = 0; i < 5; i++) {
		iFile.getline(tempLine, 200);
		std::string twitInfo(tempLine); // create std::string from char[]		
		pos = twitInfo.find(delimiter);
		uName = twitInfo.substr(0, pos); // get username
		// get rid of twitInfo up to first "
		twitInfo.erase(0, pos + delimiter.length() + 1);

		pos = twitInfo.find(delimiter);
		actualName = twitInfo.substr(0, pos); // get actual name
		twitInfo.erase(0, pos + delimiter.length());
		pos = twitInfo.find(delimiter);
		actualName = twitInfo.substr(0, pos) + " " + actualName; // put first and last names together
		twitInfo.erase(0, pos + delimiter.length());

		pos = twitInfo.find(delimiter);
		email = twitInfo.substr(0, pos); // get email
		twitInfo.erase(0, pos + delimiter.length());

		pos = twitInfo.find(delimiter);
		numTweets = twitInfo.substr(0, pos); // get tweet numbers
		twitInfo.erase(0, pos + delimiter.length());

		pos = twitInfo.find('"');
		category = twitInfo.substr(0, pos); // get category
		twitInfo.erase(0, pos + delimiter.length());

		TwitterData tempData;
		tempData.setUserName(uName);
		tempData.setActualName(actualName);
		tempData.setEmail(email);
		int numTweetsInt = stoi(numTweets);
		tempData.setNumTweets(numTweetsInt);
		tempData.setCategory(category);

		twitMap.insert(std::pair<std::string, TwitterData>(uName, tempData));
	}

	// print the first time
	std::cout << "First time printing: \n";
	for (std::map<std::string, TwitterData>::iterator it = twitMap.begin(); it != twitMap.end(); it++) {
		std::cout << "Username: " << it->first << std::endl;
		std::cout << "Real Name: " << it->second.getActualName() << std::endl;
		std::cout << "Email: " << it->second.getEmail() << std::endl;
		std::cout << "Number of Tweets: " << it->second.getNumTweets() << std::endl;
		std::cout << "Favorite Category: " << it->second.getCategory() << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;

	// remove savage1
	twitMap.erase("savage1");

	// print again
	std::cout << "Second time printing: \n";
	for (std::map<std::string, TwitterData>::iterator it = twitMap.begin(); it != twitMap.end(); it++) {
		std::cout << "Username: " << it->first << std::endl;
		std::cout << "Real Name: " << it->second.getActualName() << std::endl;
		std::cout << "Email: " << it->second.getEmail() << std::endl;
		std::cout << "Number of Tweets: " << it->second.getNumTweets() << std::endl;
		std::cout << "Favorite Category: " << it->second.getCategory() << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;

	// remove key with Rick Smith
for (std::map<std::string, TwitterData>::iterator it = twitMap.begin(); it != twitMap.end(); it++) {
	if (it->second.getActualName() == "Rick Smith") {
		twitMap.erase(it);
		break;
	}
}

	// print again
	std::cout << "Third time printing: \n";
	for (std::map<std::string, TwitterData>::iterator it = twitMap.begin(); it != twitMap.end(); it++) {
		std::cout << "Username: " << it->first << std::endl;
		std::cout << "Real Name: " << it->second.getActualName() << std::endl;
		std::cout << "Email: " << it->second.getEmail() << std::endl;
		std::cout << "Number of Tweets: " << it->second.getNumTweets() << std::endl;
		std::cout << "Favorite Category: " << it->second.getCategory() << std::endl;
		std::cout << std::endl;
	}

	return 0;
}