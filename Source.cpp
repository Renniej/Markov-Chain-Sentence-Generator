#include <iostream>
#include "Word.h"


int main(void) {


	Word word1("Hello");
	Word word2("World!");

	word1 += word2;
	word1 += word1;

	std::cout << word1.getNextWord() << std::endl;
	std::cout << word1.getNextWord() << std::endl;
	std::cout << word1.getNextWord() << std::endl;


}