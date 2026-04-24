/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:20:11 by mobouifr          #+#    #+#             */
/*   Updated: 2025/06/14 14:35:40 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Basic Test ===" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "\n=== Destructing j and i ===" << std::endl;
    delete j; // should not leak
    delete i;

    std::cout << "\n=== Array of Animals ===" << std::endl;
    const int SIZE = 4;
    Animal* animals[SIZE];

    for (int i = 0; i < SIZE / 2; ++i)
        animals[i] = new Dog();
    for (int i = SIZE / 2; i < SIZE; ++i)
        animals[i] = new Cat();

    std::cout << "\n=== makeSound() Polymorphism ===" << std::endl;
    for (int i = 0; i < SIZE; ++i)
        animals[i]->makeSound();

    std::cout << "\n=== Cleaning up ===" << std::endl;
    for (int i = 0; i < SIZE; ++i)
        delete animals[i];

    std::cout << "\n=== Deep Copy Test ===" << std::endl;
    Dog basic;
    basic.getBrain()->setIdea(0, "Catch the ball!");

    Dog copy = basic;
    basic.getBrain()->setIdea(0, "Chase the cat!");

    std::cout << "Original idea: " << basic.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied idea:   " << copy.getBrain()->getIdea(0) << std::endl;

    return 0;
}
