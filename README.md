# Cpp-Piscine

Welcome to this C++ Piscine repository.

This project is organized as a progressive path from Cpp00 to Cpp09, where each exercise folder is a small standalone program with its own Makefile and `main.cpp` test driver.

Everything in this README is based on a direct audit of repository files and real builds run on 2026-04-24.

## What Was Actually Done Here

- 10 module folders are present: Cpp00 to Cpp09
- 32 exercise folders are present (`exXX`)
- 32/32 exercise folders contain a Makefile
- 32/32 Makefiles compile with `-std=c++98`
- Build status from audited `make` runs: 32 PASS, 0 FAIL

## Learning Map (Based On Real Code In This Repo)

This section is descriptive on purpose, but each point is tied to classes, files, or language features present in the repository.

### Cpp00 - Basic I/O and Simple Class Design

- ex00 (`megaphone`): argument processing and output formatting in `megaphone.cpp`
- ex01 (`PhoneBook`): class-based data model with `Contact` and `PhoneBook`

### Cpp01 - Objects, Memory, and References

- `Zombie` exercises (`ex00`, `ex01`) show object lifecycle patterns around the `Zombie` class
- `ex03` (`Violance`) includes `Weapon`, `HumanA`, `HumanB`, demonstrating reference/pointer style APIs
- `ex05` introduces a dedicated behavior class `Harl`

### Cpp02 - Canonical Form and Numeric Type Evolution

- three iterations of class `Fixed` (`ex00`, `ex01`, `ex02`)
- structured as incremental versions via `Fixed_00`, `Fixed_01`, and `Fixed`

### Cpp03 - Inheritance Progression

- `ex00`: base gameplay-style class `ClapTrap`
- `ex01`: derived class `ScavTrap : public ClapTrap`
- `ex02`: derived class `FragTrap : public ClapTrap`

### Cpp04 - Polymorphism and Virtual Behavior

- `Animal`, `Dog`, `Cat` hierarchy across ex00/ex01/ex02
- `WrongAnimal` / `WrongCat` comparison path is present
- virtual dispatch indicators are present in headers (`virtual` destructor and `makeSound`)
- `Brain` class appears in ex01/ex02

### Cpp05 - Forms, Exceptions, and Multi-Class Interaction

- `Bureaucrat` core class in ex00
- `Form` in ex01, then `AForm` in ex02/ex03
- specialized forms in ex02/ex03:
	- `ShrubberyCreationForm`
	- `RobotomyRequestForm`
	- `PresidentialPardonForm`
- `Intern` class added in ex03

### Cpp06 - Casting and Runtime Type Identification

- ex01 (`Serializer`): `reinterpret_cast` usage in `Serializer.cpp`
- ex02 (`Identify`): `dynamic_cast` usage with `Base`, `A`, `B`, `C`

### Cpp07 - Templates

- `whatever.hpp`: template utility functions
- `iter.hpp`: template iteration helper
- `Array.hpp`: template array class

### Cpp08 - STL Containers and Generic Algorithms

- `easyfind.hpp`: generic search using `std::find`
- `Span`: vector-based span computation using STL algorithms (`sort`, `min_element`, `max_element`)
- `MutantStack`: template class extending `std::stack` with iterator access

### Cpp09 - Parsing, Algorithms, and Performance-Oriented Structures

- `BitcoinExchange`: file parsing and map-backed lookup (`std::ifstream`, `std::map`)
- `RPN`: stack-based expression evaluation (`std::stack`)
- `PmergeMe`: vector/deque implementation paths and insertion logic (`std::vector`, `std::deque`, `lower_bound`)

## How To Run Any Exercise

From repository root:

```bash
cd CppXX/exYY
make
./<binary_name>
make fclean
```

Binary names are defined by `NAME` in each Makefile.

## Executable Targets By Exercise

- Cpp00/ex00 -> `megaphone`
- Cpp00/ex01 -> `PhoneBook`
- Cpp01/ex00 -> `Zombie`
- Cpp01/ex01 -> `Zombie`
- Cpp01/ex02 -> `Brain`
- Cpp01/ex03 -> `Violance`
- Cpp01/ex04 -> `Replace`
- Cpp01/ex05 -> `Harl`
- Cpp02/ex00 -> `Fixed_00`
- Cpp02/ex01 -> `Fixed_01`
- Cpp02/ex02 -> `Fixed`
- Cpp03/ex00 -> `ClapTrap`
- Cpp03/ex01 -> `ScavTrap`
- Cpp03/ex02 -> `FragTrap`
- Cpp04/ex00 -> `Polymorph`
- Cpp04/ex01 -> `Polymorph`
- Cpp04/ex02 -> `Polymorph`
- Cpp05/ex00 -> `Bureaucrat`
- Cpp05/ex01 -> `Form`
- Cpp05/ex02 -> `AForm`
- Cpp05/ex03 -> `Intern`
- Cpp06/ex01 -> `Serializer`
- Cpp06/ex02 -> `Identify`
- Cpp07/ex00 -> `whatever`
- Cpp07/ex01 -> `iter`
- Cpp07/ex02 -> `Array`
- Cpp08/ex00 -> `easyfind`
- Cpp08/ex01 -> `span`
- Cpp08/ex02 -> `MutantStack`
- Cpp09/ex00 -> `btc`
- Cpp09/ex01 -> `RPN`
- Cpp09/ex02 -> `PmergeMe`

## Build Verification (Current)

Post-fix verification run across all exercises reports:

- Total exercises built: 32
- Pass: 32
- Fail: 0

Cpp08 now builds completely:

- Cpp08/ex00 -> PASS
- Cpp08/ex01 -> PASS
- Cpp08/ex02 -> PASS

Note on the fix applied in Cpp08/ex02:

- `Makefile` `SRCS` was corrected from `main.cpp MutantStack.cpp` to `main.cpp`
- This matches the actual folder contents (`main.cpp`, `MutantStack.hpp`, `Makefile`)

## Final Note

This README is intentionally practical for new visitors:

- where to start,
- what concepts are visible in each module,
- how to build and run,
- what currently builds and how to verify it.
