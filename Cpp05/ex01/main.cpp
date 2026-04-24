#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() 
{
	try
	{
		Bureaucrat	b("hamza", 109);
		Form 		f("l'otorizasio", 40, 30);

		std::cout << f << std::endl;
		b.signForm(f);
		std::cout << f << std::endl;

		Bureaucrat boss("lmodir", 1);
		boss.signForm(f);
		std::cout << f << std::endl;
	}

	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
