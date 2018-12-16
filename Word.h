#ifndef WORD_H
#define WORD_H

#include <string>
#include <vector>
#include <utility>

class Word // Word = State that your in
{
	std::string m_name;

	//Next States index

	std::vector<std::pair<Word*, int>> m_next_states_index; //Index for all possible next_states and amount of times they appear
	size_t m_total;

public:

	int Check_word_index(std::string& str) ;
	Word& operator+=( Word& new_word);

	std::string getNextWord() const;
	std::string getName() const;

	

	Word();
	Word(const char *); //possible move???
	~Word();
};

#endif