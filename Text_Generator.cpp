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

Text_Generator::Text_Generator(std::ifstream& ifs, const char * delimter) : delim(delimter) //Feed me WORDS so i can increase my knowledge <3
{

	std::string line;
	int i = 0;
	m_list_size = 0;
	

	if (ifs.good()) {


		

		

		std::cout << "Reading File! :)" << '\n';
		

		while (ifs.good()) {

			std::cout << "Eating Line: " << ++i;
			

			std::getline(ifs, line);

			Add_Source(line);
	
			
			std::cout << '\r';

		}

		
		std::cout << '\n' << "I finished eating " << i << " lines! THANK YOU" << '\n' << '\n';

	}
	else {

		throw std::string("BAD FILE!");
	}





}

void Text_Generator::Add_Source(const std::string& line ) //Feed me WORDS so i can increase my knowledge <3
{

	
	 //Single line of words copied from a source
	std::string grabbed_word; //Single word grabbed from line

	Word * prev_word = nullptr; //Word object representing previous word grabbed 
	Word * found_word = nullptr; //Used to check if a word object exist in m_words

	
	

	//int next_pos = line.find(delim); //next position in line to scan (Delimiter is a space)
	auto get_next_pos = [&](int n_pos) {return line.find(delim, line.find(delim, n_pos + 1) + 1); };

	int next_pos = line.find(delim, line.find(delim) + 1); //next position in line to scan (Looks for 2 delimters)
	int prev_pos = 0;

	



	if (!line.empty()) {  //If string is not empty
		
		//Before starting a loop we grab the first word in the line, check if it already exist in m_words list and then set that object to prev_word for upcoming loop 


		grabbed_word = CheckForSpecialChar(line.substr(0, next_pos)); //Grab first word from line
		
		found_word = Find_Word(grabbed_word); //Check if first word exist in m_words list

		if (found_word != nullptr) { //If Word object that matches first str_word exist then


			prev_word = found_word;  //set previous word object pointer to found_word object for upcoming loop

		}
		else { //if Word object doesn't exist that matches first str_word then 

			m_words.emplace_front(std::move(Word(std::move(grabbed_word)))); //Create word object for str_word and push it to m_words list
			++m_list_size;

			prev_word = &m_words.front(); //Set newly created word objec to prev_word for upcoming loop

		}



		//Now that we have data necessarily for looping (prev_word & next_pos)
		prev_pos = next_pos; //Set previous position to where last space was
		
		next_pos = get_next_pos(next_pos); //Grab next space.

		
		while (next_pos != std::string::npos) {
			
			grabbed_word = CheckForSpecialChar(line.substr(prev_pos+1, next_pos - prev_pos - 1)); //Grab word from line
			found_word = Find_Word(grabbed_word); //Check if first word exist in m_words list


			if (found_word != nullptr) { //If Word object that matches first str_word exist then

				*prev_word += *found_word; //Add found word object to prev_word's list of next_words.
				prev_word = found_word;  //set previous word object pointer to found_word object for upcoming loop

			}
			else { //if Word object doesn't exist that matches first str_word then 


				m_words.emplace_front(std::move(Word(std::move(grabbed_word)))); //Create word object for str_word and push it to m_words list
				++m_list_size;

				*prev_word += m_words.front(); //Add new word object to prev_word's list of next_words.

				prev_word = &m_words.front(); //Set newly created word objec to prev_word for upcoming loop

			}

			prev_pos = next_pos; //Set previous position to where last space was
		//next_pos = line.find(delim, next_pos + 1); //Grab next space.
			next_pos = get_next_pos(next_pos);
		

		}

		





	}










}

Word * Text_Generator::Find_Word(const std::string word)
{
	

	Word * tmp = nullptr;
	auto& found_word = std::find_if(m_words.begin(), m_words.end(), [&](Word elem) {return elem.getName().compare(word) == 0; }); //Check if word exist in found word


	if (found_word != std::end(m_words)) { //If matching word object is found then add it to previous word for future probability calculations

		tmp = &(*found_word);

	}


	return tmp;



}

std::string & Text_Generator::CheckForSpecialChar(std::string& str_word)
{

	for (int i = 0; i < str_word.length(); ++i) {

		if (!isalpha(str_word[i]) && str_word[i] != ' ') { //If a non-alphabetic letter is found then assume it is a special character then...

			str_word.erase(str_word.begin()+i); //Remove special character


		}


	}

	return str_word;
}





std::string Text_Generator::make_sentence()
{
	
	int length = rand() % 7 + 5; //Number of words in sentence 
	int word_index = rand() % (m_list_size - 1);
	std::forward_list<Word>::iterator itr = m_words.begin();

	std::advance(itr, rand() % m_list_size);

	return (*itr).make_sentence(length);

}
	


Text_Generator::~Text_Generator()
{
}
