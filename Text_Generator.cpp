#include "Text_Generator.h"

#include <string.h>
#include <algorithm>

Text_Generator::Text_Generator()
{

	throw std::string("Empty State for generator not allowed");
}

Text_Generator::Text_Generator(const char* str) //Recieves sentence
{

	Add_Source(str);


}

void Text_Generator::Add_Source(const char * str)
{

	std::string text = str;
	std::string tmp_word;
	int i = 0;

	std::vector<Word>::iterator it;  //research iterators more

	Word * prev_word = nullptr;

	int next_pos = text.find(" ");



	//read one word of the string at a time till you reach end of string

	if (text.find(" ", next_pos + 1) != std::string::npos) {



		m_words.push_back(Word(text.substr(0, next_pos).c_str()));

		it = m_words.begin();//research iterators more
		prev_word = &m_words[i++];//research iterators more

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
		auto& found_word = std::find_if(m_words.begin(), m_words.end(), [&](Word elem) {return elem.getName().compare(tmp_word) == 0; });


		if (found_word != std::end(m_words)) { //If matching word object is found then add it to previous word for future probability calculations

			m_words[i - 1] += *found_word; //Don't really get why I have to do it this way.... more research.
		}
		else { //else create a new word object and add it to previous word for future probability calculations
			
			
			m_words.push_back(Word(tmp_word.c_str()));
			m_words[i-1] += m_words.back();
			++i;

		}


	}
}

std::string & Text_Generator::make_sentence()
{
	
	int length = rand() % 30 + 1; //Number of words in sentence (0-30)
	Word* word = &m_words[rand() % m_words.size()];



	std::string sentence(word->getName());
	word = &word->getNextWord();
	



	for (int i = 0; i < length; ++i) {


		sentence += word->getName();
		word = &word->getNextWord();

		if (word == nullptr) {
			break;
		}

	}

	return sentence;

}
	


Text_Generator::~Text_Generator()
{
}
