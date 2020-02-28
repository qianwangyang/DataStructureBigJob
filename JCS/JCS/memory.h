#ifndef MEMORY_H
#define MEMORY_H
class Memory
{
public :
	Memory();
	int read(Person *person);
	int write(Person *person);
	int read(Assignmen *assignmen);
	int write(Assignmen *assignmen);
};

#endif