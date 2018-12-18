#ifndef WORD_H
#define WORD_H

#include <string>
#include <vector>
#include <deque>
#include <utility>
#include <iostream>

class Word // Word = State that your in
{
	std::string m_name;

	//Next States index

	std::deque<std::pair<Word*, int>> m_next_states_index; //Index for all possible next_states and amount of times they appear
	int m_total; //total words linked to this word (used to calculate probability

public:

	int Check_word_index(std::string& str) ;

	Word& operator+=( Word& new_word);

	Word& getNextWord() const;
	std::string getName() const;

	std::ostream& printProbabilites(std::ostream& os) const;
	

	Word();
	Word(const char *); //possible move???
	~Word();
};

#endif