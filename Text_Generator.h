#ifndef TEXT_GENERATOR_H
#define TEXT_GENERATOR_H

#include <fstream>
#include <iostream>
#include <list>
#include "Word.h"


class Text_Generator
{

	std::list<Word> m_words;
	size_t m_list_size;


	void Add_Source(const char* str);


	Word *  Find_Word(std::string word);

	std::string& CheckForSpecialChar(std::string& str_word);



	

public:
	

	std::string make_sentence();
	

	Text_Generator();
	Text_Generator(const char* str);
	Text_Generator(std::ifstream& ifs);
	
	~Text_Generator();
};



#endif

