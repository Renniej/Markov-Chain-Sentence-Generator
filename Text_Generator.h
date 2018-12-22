#ifndef TEXT_GENERATOR_H
#define TEXT_GENERATOR_H

#include <fstream>
#include <iostream>
#include <forward_list>
#include "Word.h"


class Text_Generator
{

	std::forward_list<Word> m_words;
	size_t m_list_size;


	void Add_Source(const std::string& line);


	Word *  Find_Word(const std::string word);

	std::string& CheckForSpecialChar(std::string& str_word);

	std::string delim;

	

public:
	

	std::string make_sentence();
	

	Text_Generator();
	Text_Generator(const char* str);
	Text_Generator(std::ifstream& ifs, const char * delimter);
	
	~Text_Generator();
};



#endif

