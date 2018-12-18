#include <iostream>
#include "Word.h"
#include <ctime>


int main(void) {
	srand(time(NULL));

	Word word1("Hello");
	Word word2("World!");

	word1 += word2;
	word1 += word1;
	word1 += word1;


	for (int i = 0; i < 10; ++i) {

		std::cout << word1.getNextWord().getName() << std::endl;
	}
	
	std::cout << std::endl;
	word1.printProbabilites(std::cout);


}