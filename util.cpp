#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
  //create a set of words to be returned and an empty string holder
  set<string> returnedWords;
  string words = "";

  //checks to make sure the word length is greater than 2 letters
  if (rawWords.size() < 2)
  {
    //no possible keywords, returns an empty string set
    return returnedWords;
  }

  //iterates through the string and breaks up the words with substring
  //placing them into the set
  for (unsigned int i = 0; i < rawWords.size(); i++)
  {
    if (isalpha(rawWords[i]))
    {
      //if it's a word, add it into the string holder
      word = word + rawWords[i];
    }
    else 
    {
      //reached the end 
      //checks to see if our current word can be added
      if(word.size() >= 2)
      {
        //can only be added if the word is greater or equal than
        //two letters
        returnedWords.insert(word);
      }
      word = "";
    }
  }
  return returnedWords;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
