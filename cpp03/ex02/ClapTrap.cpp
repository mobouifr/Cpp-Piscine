/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 02:53:56 by mobouifr          #+#    #+#             */
/*   Updated: 2025/06/14 01:22:21 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// -------------------------------------------------------------
//  Canonical Form: Constructor, Copy, Assignment, Destructor
// -------------------------------------------------------------

ClapTrap::ClapTrap()
    :  _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
:	_name(other._name), _hitPoints(other._hitPoints),
    _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
    std::cout << "ClapTrap " << _name << " is copied!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
	{
        this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
    std::cout << "ClapTrap " << _name << " assigned!" << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " is destroyed!" << std::endl;
}

// -------------------------------------------------------------
//  Parametric Constructor
// -------------------------------------------------------------

ClapTrap::ClapTrap(const std::string& name) 
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
   std::cout << "ClapTrap " << _name << " is constructed!" << std::endl; 
}

// -------------------------------------------------------------
//  Public Member Functions: Actions
// -------------------------------------------------------------

void ClapTrap::attack(const std::string& target)
{
    if (_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " is dead and can't attack." << std::endl;
        return;
    }
	
    if (_energyPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " has no energy to attack." << std::endl;
        return;
    }
	
    _energyPoints--;
    
	std::cout << "ClapTrap " << _name << " attacks " << target
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " is already dead." << std::endl;
        return;
    }
    
    _hitPoints = _hitPoints - amount;
    
    if (_hitPoints < 0)
        _hitPoints = 0;

    std::cout << "ClapTrap " << _name << " takes " << amount
              << " points of damage! Remaining HP: " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " is dead and can't repair." << std::endl;
        return;
    }

    if (_energyPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " has no energy to repair." << std::endl;
        return;
    }

    _hitPoints = _hitPoints + amount;
    _energyPoints--;

    std::cout << "ClapTrap " << _name << " repairs itself, recovering " << amount
              << " HP! Current HP: " << _hitPoints
              << ", Remaining energy: " << _energyPoints << std::endl;
}

