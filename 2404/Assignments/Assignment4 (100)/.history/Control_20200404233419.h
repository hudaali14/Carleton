#pragma once

#include "List.h"
#include <vector>

class Control
{
public:
	void initStudents();
	void initDates();
	void launch();

private:
	List<Student> students;
	List<Date> dates;
	List <View> userIO;
};

