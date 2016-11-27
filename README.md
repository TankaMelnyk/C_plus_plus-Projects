# Translator 15.01.2016

This course work on the courses:
- Basic programming,
- C++ and STL library,
- Fundamentals of Object-Oriented Programming

# The basic idea and motivationffd

The project was conceived as a serious practical work for the excercise of the previous topics.
 Procedural programming
 - IO base operations
  - variables
 - conditional constructions
 - cycles
 - arrays
 - function
 Structured programming
 - pointers arithmetic
 - the structures
 - complex chain of functions calls
 - Exceptions and their handling
 - File Input-Output
 Standard tempates library - STL
 - String class and working algorithms with it
 - Vector as a dynamic array
 - Associative containers - Map and Set
 - Base algorithms for work with containers
 The Object-Oriented Programming and the Object-Oriented Design
 - Base OOP concepts
 - Data abstraction
 - Encapsulation
 - Inheritance and composition as his alternative
 - Polymorphism and its types
 - Object-Oriented Design and UML class diagrams  

Application architecture and layering
 *) The project is presented as a set of three layers - Presentation Layer, Busines Logic, Data Layer
 *) The root of the application has the Application class which encapsulates one Vraperu of each layer
 *) Each layer is isolated from each other and only know about the bridge from the layer below
 *) The layer DL is represented by a simple Akksesorom and files in the operating system
 *) In the BC layer contains the basic algorithms for translating words and sentences, they add, as well as view and change the dictionary nastroeek
 *) Facade in BC layer acts TransManager
 *) UI layer is presented in the form of State Machine which switches the pre-prepared screens
 *) The screens and transitions between them are described in the manufacturing methods of UI factory
 *) Each screen is represented by an independent content, as well as custom action and move to other embodiments of the screens
 
 The build process
 The assembly process is simple - just open the file Translator.vcxproj liboy VisualStudio with support for standard C ++ 11 and compile it
