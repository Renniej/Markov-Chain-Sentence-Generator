#ifndef TEXT_GENERATOR_H
#define TEXT_GENERATOR_H

#include <fstream>
#include <iostream>
#include "Word.h"


class Text_Generator
{

	std::vector<Word> m_words;



public:
	void Add_Source(const char* str);

	std::string& make_sentence();


	Text_Generator();
	Text_Generator(const char* str);
	
	~Text_Generator();
};



#endif

