
class Person
{
public :
	Person(int id,int pw,int status,char *name,Person *next);
	int getPW();
	int getID();
	char* getName();
	int getStatus();
	Person* getPerson();
	void setPW(int pw);
	void setID(int id);
	void setStatus(int status);
	void setName(char *name);
	void setNext(Person *next);
	
private :
	char *name;
	int pw;
	int id;
	int status;
	Person *next;
};
