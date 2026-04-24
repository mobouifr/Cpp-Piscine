/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 03:41:49 by mobouifr          #+#    #+#             */
/*   Updated: 2025/06/14 19:10:22 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() 
{
    const Animal *a = new Animal();
    const Dog d;
    const Animal* c = new Cat();
    

    std::cout << std::endl;
    
    std::cout << "Animal d type :" << d.getType() << std::endl;
    std::cout << "Animal c type :" << c->getType() << std::endl;
    std::cout << "Animal a type :" << a->getType() << std::endl;
   
    std::cout << std::endl;
    
    d.makeSound(); // Dog sound
    c->makeSound(); // Cat sound
    a->makeSound(); // Animal sound
    
    std::cout << std::endl;

    const WrongAnimal* wa = new WrongAnimal();
    const WrongAnimal* wc = new WrongCat();

    std::cout << std::endl;
    
    std::cout << "Animal wc type :" << wc->getType() << std::endl;
    std::cout << "Animal wa type :" << wa->getType() << std::endl;
    
    std::cout << std::endl;
    
    wc->makeSound(); // Will call WrongAnimal::makeSound(), NOT WrongCat's
    wa->makeSound();
   
    std::cout << std::endl;

    delete a;
    // delete d;
    delete c;
    delete wa;
    delete wc;

    return 0;
}
