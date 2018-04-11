#include "Flags.h"

#include "List.h"
#include "Heap.h"
#include "Array.h"

#include "Core.h"

#include <iostream>
#include <Windows.h>
#include <chrono>

//#include <stack>

//using namespace std;

LARGE_INTEGER startTimer();
LARGE_INTEGER endTimer();

void main()
{

	//run_main_program();
	
#ifdef RUN_TEST_STRUCTURS

	const int size_of_structure = 100000;
	int rand_data[size_of_structure];
	std::srand(time(NULL));
	for (int i = 0; i < size_of_structure; i++)
	{
		rand_data[i] = rand() % (size_of_structure*10);
	}

	//
	//TEST ARRAY
	//
	{
		std::cout << "===================================" << std::endl;
		std::cout << "TEST ARRAY" << std::endl;
		std::cout << "===================================" << std::endl;
		Array table;

		//
		//add elements to table
		//

		std::cout << "add " << size_of_structure << " values to the array in random pleaces" << std::endl;

		chrono::steady_clock sc;   // create an object of `steady_clock` class
		auto start = sc.now();     // start timer

		for (int i = 0; i < size_of_structure; i++)
		{
			table.push_random_place(rand_data[i]);
		}

		auto end = sc.now();       // end timer (starting & ending is done by measuring the time at the moment the process started & ended respectively)
		auto time_span = static_cast<chrono::duration<double>>(end - start);   // measure time span between start & end
		std::cout << "Operation took: " << time_span.count() << " seconds !!!" << std::endl;
		std::cout << std::endl;

		//
		//delete elements to table
		//

		std::cout << "delete " << size_of_structure / 10 << " values to the table in random pleaces" << std::endl;
		start = sc.now();

		for (int i = 0; i < size_of_structure / 10; i++)
		{
			table.pop_random_place();
		}

		end = sc.now();
		time_span = static_cast<chrono::duration<double>>(end - start);
		std::cout << "Operation took: " << time_span.count() << " seconds !!!" << std::endl;
		std::cout << std::endl;
	}

	//
	//TEST LIST
	//
	{
		std::cout << "===================================" << std::endl;
		std::cout << "TEST LIST" << std::endl;
		std::cout << "===================================" << std::endl;
		List<int> list;


		//
		//add elements to table
		//
		std::cout << "add " << size_of_structure << " values to the table in random pleaces" << std::endl;

		chrono::steady_clock sc;   // create an object of `steady_clock` class
		auto start = sc.now();     // start timer

		for (int i = 0; i < size_of_structure; i++)
		{
			list.push_random_place(rand_data[i]);
		}

		auto end = sc.now();       // end timer (starting & ending is done by measuring the time at the moment the process started & ended respectively)
		auto time_span = static_cast<chrono::duration<double>>(end - start);   // measure time span between start & end
		std::cout << "Operation took: " << time_span.count() << " seconds !!!" << std::endl;
		std::cout << std::endl;

		//
		//delete elements to table
		//

		std::cout << "delete " << size_of_structure / 10 << " values to the table in random pleaces" << std::endl;
		start = sc.now();

		for (int i = 0; i < size_of_structure / 10; i++)
		{
			list.pop_random_place();
		}

		end = sc.now();
		time_span = static_cast<chrono::duration<double>>(end - start);
		std::cout << "Operation took: " << time_span.count() << " seconds !!!" << std::endl;
		std::cout << std::endl;
	}

	//
	//TEST HEAP
	//
	{
		std::cout << "===================================" << std::endl;
		std::cout << "TEST HEAP" << std::endl;
		std::cout << "===================================" << std::endl;
		Heap heap;


		//
		//add elements to table
		//
		std::cout << "add " << size_of_structure << " values to the table in random pleaces" << std::endl;

		chrono::steady_clock sc;   // create an object of `steady_clock` class
		auto start = sc.now();     // start timer

		for (int i = 0; i < size_of_structure; i++)
		{
			heap.push(rand_data[i]);
		}

		auto end = sc.now();       // end timer (starting & ending is done by measuring the time at the moment the process started & ended respectively)
		auto time_span = static_cast<chrono::duration<double>>(end - start);   // measure time span between start & end
		std::cout << "Operation took: " << time_span.count() << " seconds !!!" << std::endl;
		std::cout << std::endl;

		//
		//delete elements to table
		//

		std::cout << "delete " << size_of_structure / 10 << " values to the table in random pleaces" << std::endl;
		start = sc.now();

		for (int i = 0; i < size_of_structure / 10; i++)
		{
			heap.pop(rand_data[i]);
		}

		end = sc.now();
		time_span = static_cast<chrono::duration<double>>(end - start);
		std::cout << "Operation took: " << time_span.count() << " seconds !!!" << std::endl;
		std::cout << std::endl;
	}
#endif // RUN_TEST_STRUCTURS

	
	system("pause");
	return;
}

LARGE_INTEGER startTimer()
{
	LARGE_INTEGER start;
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&start);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
	return start;
}

LARGE_INTEGER endTimer()
{
	LARGE_INTEGER stop;
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&stop);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
	return stop;
}
