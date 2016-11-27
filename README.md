# Translator 15.01.2016

This course work on the courses:
- Basic programming,
- C++ and STL library,
- Fundamentals of Object-Oriented Programming

# The basic idea and motivation

The project was conceived as a serious practical work for the excercise of the previous studies.
1) Procedural programming
 a) IO bases
 b) variables
 c) conditional constructions
 g) Cycles
 d) arrays
 e) function
 2) Structured programming
 a) pointer arithmetic
 a) the structure
 b) complex chaining functions
 *) Exceptions and their handling
 *) Files of input-output
 3) Standard bibioteka STL templates
 *) String class and algorithms working with him
 *) Vector, a dynamic array
 *) Map and set
 *) Based on the algorithm to work with containers
 4) the PLO and the DTE
 *) Osnovyne OOP concepts
 *) Data abstraction
 *) Encapsulation
 *) Inheritance and composition as his alternative
 *) Polymorphism and its types
 *) OO design and UML class diagrams
  

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
