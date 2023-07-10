#include "Core/core.h"
#include "Renderer/Renderer.h"
#include <iostream>
#include <vector>

using namespace std;

class Star
{
public:
	Star(const minimum::Vector2& pos, const minimum::Vector2& vel):
		m_pos{ pos },
		m_vel{ vel }
	{}

	void Update()
	{
		m_pos += m_vel;
	}

public:
	minimum::Vector2 m_pos;
	minimum::Vector2 m_vel;
};


int main(int argc, char* argv[])
{
	minimum::seedRandom((unsigned int)time(nullptr));

	minimum::Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("CSC196", 800, 600);

	vector<Star> stars;
	for (int i = 0; i < 500; i++)
	{
		minimum::Vector2 pos(minimum::Vector2(minimum::random(renderer.GetWidth()), minimum::random(renderer.GetHeight())));
		minimum::Vector2 vel(minimum::randomf(1, 8), 0.0f);

		stars.push_back(Star(pos, vel));
	}

	vector<minimum::Vector2> points;
	for (int i = 0; i < 1000; i++ )
	{
		points.push_back(minimum::Vector2(minimum::random(renderer.GetWidth()), minimum::random(renderer.GetHeight())));
	}

	while (true)
	{

		renderer.SetColor(0, 0, 0, 0);
		renderer.BeginFrame();
		// draw
		minimum::Vector2 vel(1.0f, 0.3f);

		for (auto& star : stars) {

			star.Update();

			if (star.m_pos.x >= renderer.GetWidth()) star.m_pos.x = 0;
			if (star.m_pos.y >= renderer.GetHeight()) star.m_pos.y = 0;

			renderer.SetColor(minimum::random(256), minimum::random(256), minimum::random(256), 255);
			renderer.DrawPoint(star.m_pos.x, star.m_pos.y);
		}

		/*for (int i = 0; i < 100000; i++) {
			minimum::Vector2 pos(minimum::random(renderer.GetWidth()), minimum::random(renderer.GetHeight()));

			renderer.SetColor(minimum::random(256), minimum::random(256), minimum::random(256), 255);
			renderer.DrawPoint(pos.x, pos.y);
		}*/

		renderer.EndFrame();
	}
	
	return 0;
	
}



	/*
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

	cout << minimum::getFilePath() << endl;
	minimum::setFilePath("Assets");
	cout << minimum::getFilePath() << endl;
	
	size_t size;
	minimum::getFileSize("game.txt", size);
	cout << size << endl;

	std::string s;
	minimum::readFile("game.txt", s);
	cout << s << endl;*/
