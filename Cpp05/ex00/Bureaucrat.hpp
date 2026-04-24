/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 11:28:09 by mobouifr          #+#    #+#             */
/*   Updated: 2025/12/21 15:21:50 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat
{
    private:
		const	std::string name;
		int					grade;
	
    public:
    // Canonical Form + Parametrized Contructor:
    			Bureaucrat();
    			Bureaucrat(const Bureaucrat& other);
    Bureaucrat&	operator=(const Bureaucrat& other);
				~Bureaucrat();
	
				Bureaucrat(const std::string& name, int garde);

	// Getters:
	const std::string&	getName() const;
	int 				getGrade() const;

	// Grade Modifiers:
	void	incrementGrade();
	void	decrementGrade();

	// Exceptions
	class GradeTooHighException : public std::exception
	{
		public:
		const char* what() const throw();	
	};
	
	class GradeTooLowException : public std::exception
	{
		public:
		const char* what() const throw();
	};
};

// Output operator overload
std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif