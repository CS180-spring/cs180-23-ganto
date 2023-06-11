[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=10833384&assignment_repo_type=AssignmentRepo)

# GantoDB

The aim of GantoDB is to create a document data store backend which is capable of CRUD operations on tables. The CRUD operations can be performed using API calls. In addition, we will have a GUI interface for easy edit access.

## Team Members
- Phoenix Winter (development lead/software architect)
- Francis Cuarteros (data structure engineer)
- Milind Devnani (algorithm and performance specialist)
- Nael Bahi (user/programming interface engineer)
- Ronny Gorani (testing lead)

## Techologies
- **Interface**: library/programming APIs; terminal/shell console; GUI
- **Languages**: C++, C #, Python

## Features
- Feature 1: Create tables
- Feature 2: Update tables
- Feature 3: Delete tables
- Feature 4: Read table metadata
- Feature 5: CRUD entries
- Feature 6: Create and remove indexes
- Feature 7: Can do above through api calls
- Feature 8: GUI for easy edit access

## Some notes for GUI (Windows)
We used Visual Studio 2022 CLR .NET framework for our GUI
There were too many files to include for the GUI executable so only the code part was pushed and it doesn't work for other computers without these extra steps:
- Create a CLR Empty Project (.NET Framework) using the directory where you saved this project in (you need to download these in the install dependencies from Visual Studio Installer)
- On the menu strip at the very top after opening the solution. Project -> <what you named the project> Properties (towards the bottom of the list)
- From there you want to change Configuration Properties -> General -> C++ Language Standard to ISO C++17 Standard(/std:c++17) to fix the problem with the variant type in our code
- As well as Configuation Properties -> C/C++ -> General -> Additional Include Directories and add the file path to the directory that you have this project saved in
- Also go to Configuation Properties -> Linker -> System -> SubSystem to Windows (/SUBSYSTEM:WINDOWS)
- And Configuation Properties -> Linker -> Advanced -> Entry Point to main
- Sometimes Visual Studio also needs you to restart the client for changes to be put into effect
- There are still many other errors that occur but these were the main ones that got it to run on at least one of our systems.
