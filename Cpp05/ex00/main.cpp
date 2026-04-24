/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 11:28:06 by mobouifr          #+#    #+#             */
/*   Updated: 2025/12/21 15:02:09 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() 
{
	// Case 1: Valid bureaucrat
	try 
    {
		Bureaucrat b1("Montassir", 3);
		std::cout << b1 << std::endl;

		b1.incrementGrade();
		std::cout << "After increment: " << b1 << std::endl;
	}
    
    catch (std::exception& e)
    {
		std::cerr << "Exception: " << e.what() << std::endl;
	}	

	std::cout << "---------------------" << std::endl;

	// Case 2: Grade too low (below 150)
	try
    {
		Bureaucrat b2("Lazy", 150);
		std::cout << b2 << std::endl;

		b2.decrementGrade();
		std::cout << "After decrement: " << b2 << std::endl;
	}
    
    catch (std::exception& e)
    {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "---------------------" << std::endl;

	// Case 3: Grade too high (above 1)
	try
    {
		Bureaucrat b3("Ambitious", 1);
		std::cout << b3 << std::endl;

		b3.incrementGrade();
		std::cout << "After increment: " << b3 << std::endl;
	}

    catch (std::exception& e)
    {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "---------------------" << std::endl;

	// Case 4: Invalid grade at construction
	try 
    {
		Bureaucrat b4("InvalidGuy", 160);
		std::cout << b4 << std::endl;
	} 
    
    catch (std::exception& e)
    {
		std::cerr << "Exception while creating b4: " << e.what() << std::endl;
	}

	return 0;
}
