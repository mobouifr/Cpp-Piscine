/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:20:11 by mobouifr          #+#    #+#             */
/*   Updated: 2025/06/14 21:40:02 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define N 4 // Size of the animal array

int main()
{
    std::cout << "=== Basic polymorphic test ===" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j; // should call Dog and Brain destructors
    delete i; // should call Cat and Brain destructors

    std::cout << "\n=== Creating Animal array ===" << std::endl;
    Animal* animals[N];

    for (int idx = 0; idx < N; ++idx)
    {
        if (idx < N / 2)
            animals[idx] = new Dog();
        else
            animals[idx] = new Cat();
    }

    std::cout << "\n=== Deleting Animal array ===" << std::endl;
    for (int idx = 0; idx < N; ++idx)
        delete animals[idx];

    std::cout << "\n=== Deep Copy Test ===" << std::endl;

    Dog originalDog;
    originalDog.getBrain()->setIdea(0, "Chase cats!");
    originalDog.getBrain()->setIdea(1, "Dig holes!");

    std::cout << std::endl;
    
    Dog copyDog = originalDog; // Should deep copy
    
    std::cout << std::endl;
    
    std::cout << "Original Dog idea 0: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy Dog idea 0: " << copyDog.getBrain()->getIdea(0) << std::endl;

    // Modify original's brain to check for deep copy
    originalDog.getBrain()->setIdea(0, "Sleep all day.");

    std::cout << "\nAfter modifying original:" << std::endl;
    std::cout << "Original Dog idea 0: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy Dog idea 0: " << copyDog.getBrain()->getIdea(0) << std::endl;

    std::cout << "\n=== Done ===" << std::endl;

    return 0;
}
