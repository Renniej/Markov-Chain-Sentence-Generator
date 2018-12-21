#include <iostream>
#include "Text_Generator.h"
#include <ctime>
#include <fstream>

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

	std::ifstream file("Example_Text");
	std::string text("The brown lazy fox jumps over the fence");

	

	Text_Generator test1(text.c_str());
	//Text_Generator test2(file);


	std::cout << "Test 1: " << test1.make_sentence() << std::endl;
	//std::cout << "Test 2: " << test2.make_sentence() << std::endl;



}