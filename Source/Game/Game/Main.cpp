#include "Core/random.h" //"" for same directory
#include "Core/FileIO.h" 
#include "Core/Memory.h" 
#include "Core/Time.h"
#include <iostream> //searches the system instead
#include <chrono>

using namespace std;

int main()
{
	minimum::g_memoryTracker.DisplayInfo();
	int* p = new int;
	minimum::g_memoryTracker.DisplayInfo();
	delete p;
	minimum::g_memoryTracker.DisplayInfo();

	minimum::Time timer;
	for (int i = 0; i < 100000; i++) {}
	cout << timer.GetElapsedNanoseconds() << endl;

	auto start = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < 100000; i++) {}
	auto end = std::chrono::high_resolution_clock::now();
	cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << endl;

	/*cout << minimum::getFilePath() << endl;
	minimum::setFilePath("Assets");
	cout << minimum::getFilePath() << endl;
	
	size_t size;
	minimum::getFileSize("game.txt", size);
	cout << size << endl;

	std::string s;
	minimum::readFile("game.txt", s);
	cout << s << endl;*/

}
