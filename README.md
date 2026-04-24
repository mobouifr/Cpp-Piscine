<a id="project-header"></a>

<div align="center">

# Cpp-Piscine

<p>A clean C++98 learning archive for the 42 C++ Piscine, from first console programs to templates, STL, and runtime polymorphism.</p>

<p>
  <img src="https://img.shields.io/badge/build-32%2F32%20pass-success?style=for-the-badge" alt="Build" />
  <img src="https://img.shields.io/badge/license-MIT-blue?style=for-the-badge" alt="License" />
  <img src="https://img.shields.io/badge/version-main-lightgrey?style=for-the-badge" alt="Version" />
  <img src="https://img.shields.io/badge/language-C%2B%2B98-f34b7d?style=for-the-badge" alt="Language" />
  <img src="https://img.shields.io/badge/last%20commit-bd65e82-181717?style=for-the-badge" alt="Last Commit" />
</p>

</div>

---

## Screenshot / Demo

> This repository is console-based, so there is no UI screenshot or hosted demo link.
> The useful demo is the source itself: each exercise ships with a `main.cpp` that can be built and run locally.

---

## Table of Contents

- [Project Header](#project-header)
- [Screenshot / Demo](#screenshot--demo)
- [About the Project](#about-the-project)
- [Tech Stack](#tech-stack)
- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Configuration](#configuration)
- [Contributing](#contributing)
- [License](#license)
- [Author](#author)

---

## About the Project

This repository collects the full C++ Piscine journey in one place. It is meant for students who want a compact, runnable reference for each module, and for anyone who wants to see how the curriculum grows from simple input/output to class design, inheritance, templates, and STL-heavy exercises.

The goal is practical learning, not a polished application. Every folder is self-contained, every exercise has its own Makefile, and the code is kept in the C++98 style expected by the Piscine.

---

## Tech Stack

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-98-00599C?style=for-the-badge&logo=c%2B%2B" alt="C++98" />
  <img src="https://img.shields.io/badge/Build%20Tool-Make-6D4A3D?style=for-the-badge&logo=gnu" alt="GNU Make" />
  <img src="https://img.shields.io/badge/STL-Algorithms%20%26%20Containers-4B5563?style=for-the-badge" alt="STL" />
  <img src="https://img.shields.io/badge/OOP-Inheritance%20%26%20Polymorphism-0EA5E9?style=for-the-badge" alt="OOP" />
  <img src="https://img.shields.io/badge/Templates-Generic%20Programming-F59E0B?style=for-the-badge" alt="Templates" />
  <img src="https://img.shields.io/badge/File%20I%2FO-Streams%20%26%20Parsing-10B981?style=for-the-badge" alt="File I/O" />
</p>

---

## Features

- 📚 Covers 32 standalone exercises across Cpp00 to Cpp09.
- 🧱 Shows the learning path from basic console programs to reusable abstractions.
- 🧠 Demonstrates canonical forms, copy semantics, inheritance, and virtual dispatch.
- 🧰 Uses templates, STL containers, and algorithms in the later modules.
- 📄 Keeps every exercise self-contained with its own Makefile and entry point.
- ✅ Builds cleanly with `-std=c++98` across the whole repository.
- 🔎 Acts as a navigable reference for revisiting specific curriculum topics.

---

## Getting Started

### Prerequisites

You need a C++98-capable compiler, `make`, and `git`.

```bash
c++ --version
```

```bash
make --version
```

```bash
git --version
```

### Installation

1. Clone the repository.

```bash
git clone https://github.com/mobouifr/Cpp-Piscine.git
cd Cpp-Piscine
```

2. Install the toolchain if it is missing.

```bash
# No project-specific packages are required.
# Install your system's standard C++ build tools only if c++ or make are missing.
```

3. Environment setup.

```bash
# No .env file or runtime configuration is required for this repository.
```

4. Build and run any exercise.

```bash
make -C Cpp03/ex00
./Cpp03/ex00/ClapTrap
make -C Cpp03/ex00 fclean
```

> Tip: each exercise is independent, so you can build only the folder you care about.

---

## Usage

Every exercise folder follows the same pattern: build, run the generated binary, then clean when you are done.

```cpp
#include "ClapTrap.hpp"

int main()
{
    ClapTrap bot("CT-One");   // build the class used in the exercise
    bot.attack("target");     // prints the exercise demo output
    return 0;
}
```

Common commands:

```bash
make -C Cpp08/ex01          # build the Span exercise
./Cpp08/ex01/span           # run the generated binary
make -C Cpp08/ex01 clean    # remove object files
make -C Cpp08/ex01 fclean   # remove object files and binary
make -C Cpp08/ex01 re       # rebuild from scratch
```

---

## Project Structure

```text
Cpp-Piscine/
├── Cpp00/        # Module 00: megaphone and phone book exercises
├── Cpp01/        # Module 01: zombies, references, and Harl
├── Cpp02/        # Module 02: Fixed class iterations
├── Cpp03/        # Module 03: ClapTrap, ScavTrap, FragTrap inheritance chain
├── Cpp04/        # Module 04: animals, brains, and polymorphism
├── Cpp05/        # Module 05: bureaucrats, forms, and intern logic
├── Cpp06/        # Module 06: casting and runtime type identification
├── Cpp07/        # Module 07: template exercises
├── Cpp08/        # Module 08: STL containers and algorithms
├── Cpp09/        # Module 09: parsing, stacks, and sorting performance
├── README.md     # Project overview, exercise map, and build notes
└── LICENSE       # MIT license for the repository
```

---

## Configuration

This repository does not use `.env` files or runtime configuration keys.

| Variable | Default | Description |
| --- | --- | --- |
| N/A | N/A | No repository-wide environment variables or config keys are defined. |

---

## Contributing

1. Fork the repository.
2. Create a branch for your change.
3. Make focused commits with clear messages.
4. Open a pull request against `main`.

> Conventional commits are welcome if you use them, but they are not required here.

---

## License

This project is released under the MIT License. See [LICENSE](LICENSE) for the full text.

---

## Author

Montassir Bouifraden — GitHub: [mobouifr](https://github.com/mobouifr)
