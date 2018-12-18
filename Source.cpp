#include <iostream>
#include "Text_Generator.h"
#include <ctime>


int main(void) {
	srand(time(NULL));


	/*
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
	*/

	std::string text("The brown lazy fox jumps over the fence");

	std::cout << text[34];

	Text_Generator test(text.c_str());

	std::cout << test.make_sentence();

}