#include "Text_Generator.h"

#include <string.h>
#include <algorithm>
#include <cctype>

Text_Generator::Text_Generator()
{
	m_list_size = 0;
	throw std::string("Empty State for generator not allowed");
}

Text_Generator::Text_Generator(const char* str) //Recieves sentence
{
	m_list_size = 0;
	Add_Source(str);


}

Text_Generator::Text_Generator(std::ifstream& ifs) //Feed me WORDS so i can increase my knowledge <3
{


	if (ifs.good()) {


		

		std::string line;
		int i = 0;

		std::cout << "OOOHHHH DINNER! :)" << std::endl;
		

		while (ifs.good()) {

			std::cout << "Eating Line: " << ++i;
			

			std::getline(ifs, line);

			Add_Source(line.c_str());
	
			
			std::cout << '\r';

		}

		
		std::cout << std::endl << "I finished eating " << i << " lines! THANK YOU" << std::endl << std::endl;

	}
	else {

		throw std::string("BAD FILE!");
	}





}

void Text_Generator::Add_Source(const char * str) //Feed me WORDS so i can increase my knowledge <3
{

	
	std::string line = str; //Single line of words copied from a source
	std::string grabbed_word; //Single word grabbed from line

	Word * prev_word = nullptr; //Word object representing previous word grabbed 
	Word * found_word = nullptr; //Used to check if a word object exist in m_words
	Word * Spec_Char = nullptr; //Special characters get their own word object. 

	int next_pos = line.find(" "); //next position in line to scan (Delimiter is a space)
	int prev_pos = 0;

	if (!line.empty()) {  //If string is not empty
		
		//Before starting a loop we grab the first word in the line, check if it already exist in m_words list and then set that object to prev_word for upcoming loop 


		grabbed_word = CheckForSpecialChar(line.substr(0, next_pos)); //Grab first word from line
		
		found_word = Find_Word(grabbed_word); //Check if first word exist in m_words list

		if (found_word != nullptr) { //If Word object that matches first str_word exist then


			prev_word = found_word;  //set previous word object pointer to found_word object for upcoming loop

		}
		else { //if Word object doesn't exist that matches first str_word then 

			m_words.push_front(Word(grabbed_word.c_str())); //Create word object for str_word and push it to m_words list
			prev_word = &m_words.front(); //Set newly created word objec to prev_word for upcoming loop

		}



		//Now that we have data necessarily for looping (prev_word & next_pos)
		prev_pos = next_pos; //Set previous position to where last space was
		next_pos = line.find(" ", next_pos + 1); //Grab next space.

		
		while (next_pos != std::string::npos) {

			grabbed_word = CheckForSpecialChar(line.substr(prev_pos + 1, next_pos - 1)); //Grab word from line
			found_word = Find_Word(grabbed_word); //Check if first word exist in m_words list


			if (found_word != nullptr) { //If Word object that matches first str_word exist then

				*prev_word += *found_word; //Add found word object to prev_word's list of next_words.
				prev_word = found_word;  //set previous word object pointer to found_word object for upcoming loop

			}
			else { //if Word object doesn't exist that matches first str_word then 

				m_words.push_front(Word(grabbed_word.c_str())); //Create word object for str_word and push it to m_words list

				*prev_word += m_words.front(); //Add new word object to prev_word's list of next_words.

				prev_word = &m_words.front(); //Set newly created word objec to prev_word for upcoming loop

			}

			prev_pos = next_pos; //Set previous position to where last space was
			next_pos = line.find(" ", next_pos + 1); //Grab next space.

		}

		





	}










}

Word * Text_Generator::Find_Word(std::string word) 
{
	

	Word * tmp = nullptr;
	auto& found_word = std::find_if(m_words.begin(), m_words.end(), [&](Word elem) {return strcmpi(elem.getName().c_str(), word.c_str()) == 0; });


	if (found_word != std::end(m_words)) { //If matching word object is found then add it to previous word for future probability calculations

		tmp = &(*found_word);

	}


	return tmp;



}

std::string & Text_Generator::CheckForSpecialChar(std::string& str_word)
{

	for (int i = 0; i < str_word.length(); ++i) {

		if (!isalpha(str_word[i])) { //If a non-alphabetic letter is found then assume it is a special character then...

			str_word.erase(i); //Remove special character


		}


	}

	return str_word;
}





std::string Text_Generator::make_sentence()
{
	
	int length = rand() % 15 + 1; //Number of words in sentence (1-30)

	return m_words.front().make_sentence(length);

}
	


Text_Generator::~Text_Generator()
{
}
