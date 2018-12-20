#include "Text_Generator.h"

#include <string.h>
#include <algorithm>

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

		while (ifs.good()) {

			std::getline(ifs, line);

			std::cout << "Eating Line: " << line << std::endl;

			Add_Source(line.c_str());

			std::cout << "YUM, that line was delicious :)" << std::endl << std::endl;

		}




	}
	else {

		throw std::string("BAD FILE!");
	}





}

void Text_Generator::Add_Source(const char * str) //Feed me WORDS so i can increase my knowledge <3
{

	std::string text = str;
	std::string tmp_word;


	std::vector<Word>::iterator it;  //research iterators more

	Word * prev_word = nullptr;

	int next_pos = text.find(" ");



	//read one word of the string at a time till you reach end of string

	if (text.find(" ", next_pos + 1) != std::string::npos) {



		m_words.push_front(Word(text.substr(0, next_pos).c_str()));
		++m_list_size;
		
		prev_word = &m_words.front();

	}


	while (text.find(" ", next_pos + 1) != std::string::npos) {


		if (text.find(' ', next_pos + 1) != std::string::npos) { //If another space exist after this space then grab the text between those spaces

			tmp_word = text.substr(next_pos + 1, text.find(" ", next_pos+1) - next_pos-1);
			next_pos = text.find(" ", next_pos + 1);

		}
		else { //else assume you are at the end of the line and grab word between current space and end of text 
			tmp_word = text.substr(next_pos);
		}


		//Look for a word object that matches tmp_word
		
		auto& found_word = std::find_if(m_words.begin(), m_words.end(), [&](Word elem) {return strcmpi(elem.getName().c_str(), tmp_word.c_str()) == 0; });


		if (found_word != std::end(m_words)) { //If matching word object is found then add it to previous word for future probability calculations

			*prev_word += *found_word; //Don't really get why I have to do it this way.... more research.
			prev_word = &(*found_word);
		}
		else { //else create a new word object and add it to previous word for future probability calculations
			
			
			m_words.push_front(Word(tmp_word.c_str()));
			++m_list_size;
			prev_word = &m_words.front();

		}


	}
}

std::string Text_Generator::make_sentence()
{
	
	int length = rand() % 30 + 1; //Number of words in sentence (1-30)

	return m_words.front().make_sentence(length);

}
	


Text_Generator::~Text_Generator()
{
}
