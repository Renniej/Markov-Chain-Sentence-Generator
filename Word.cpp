#include <random>
#include <algorithm>
#include <cstdlib>

#include "Word.h"






int Word::Check_word_index(std::string & str)   //Check if str is an word that already exist in this object's index.
{
	
	 auto find = find_if(m_next_states_index.begin(), m_next_states_index.end(), [&](std::pair<Word*, int> elem) {return str.compare(elem.first->getName()) == 0; }); //Attempt to find word in object's index
	 //if not found then find_if will return m_next_states.end()

	 return find != std::end(m_next_states_index) ? find - m_next_states_index.begin() : -1; //if found then return it's postion else return -1
	 
}

Word& Word::operator+=( Word& new_word)
{

	std::string name = new_word.getName();
	int found = Check_word_index(name);

	if ( found == -1) { //If the word does not exist in the 

		m_next_states_index.push_back(std::make_pair(&new_word, 1));
		
	}
	else { //if it does then add 1 to it's counter
	
		++m_next_states_index[found].second;

	}
	
	++m_total;

	return *this;
}



Word& Word::getNextWord() const
{


	Word* found = nullptr;
	int chance;
	int selected_word;
	
	if (m_total != 0) {
		do {

			chance = rand() % m_total + 1;
			selected_word = rand() % m_next_states_index.size();



			if (m_next_states_index[selected_word].second <= chance) {
				found = m_next_states_index[selected_word].first;
			}


		} while (found == nullptr);

	}
	return *found;


}






std::string Word::getName() const
{
	return m_name;
}

std::ostream & Word::printProbabilites(std::ostream& os) const
{
	

	for (const auto& i : m_next_states_index) {

		os << i.first->getName() << " Chances: " << i.second << "/" << m_total << std::endl;
		

	}

	return os;



}



Word::Word()
{


	throw std::string("initate default constructor not allowed!");

}

Word::Word(const char * word)
{

	m_name = word;
	m_total = 0;
}


Word::~Word()
{
}
