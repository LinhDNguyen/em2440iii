/*************************************

NAME:hello-c++.c++
COPYRIGHT:www.embedsky.net

*************************************/

#include <iostream>
#include <cstring>
using namespace std;

class String
{
	private:
   	    char *str;
	public:
	    String(char *s)
	    {
	        int lenght=strlen(s);
	        str = new char[lenght+1];
	        strcpy(str, s);	
	    }
	    void display()
	    {
		cout << str <<endl;
	    }
};

int main(void)
{

	String s1 = "\n########################\n";
	String s2 = "    Hello, EmbedSky!";
	String s3 = "   C++ program Test!";
	String s4 = "\n########################\n";

	s1.display();
	s2.display();
	s3.display();
	s4.display();
	return 0;
}
