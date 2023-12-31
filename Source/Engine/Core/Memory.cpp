#include "Memory.h"
#include <iostream>

using namespace std;
minimum::MemoryTracker minimum::g_memoryTracker;

void* operator new (size_t size)
{
	void* p = malloc(size);
	minimum::g_memoryTracker.Add(p, size);

	return p;
}

void operator delete (void* address, size_t size)
{
	minimum::g_memoryTracker.Remove(address, size);

	free(address);
}

namespace minimum
{
	void MemoryTracker::Add(void* address, size_t size)
	{
		m_bytesAllocated += size;
		m_numAllocations++;
	}

	void MemoryTracker::Remove(void* address, size_t size)
	{
		m_bytesAllocated -= size;
		m_numAllocations--;

	}

	void MemoryTracker::DisplayInfo()
	{
		cout << "current bytes allocated: " << m_bytesAllocated << endl;
		cout << "current number allocated: " << m_numAllocations << endl;

	}
}