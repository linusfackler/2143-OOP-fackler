## A05

- Name: Linus Fackler
- Date: 23 Feb 2021
- Class: 2143 OOP

## Definitions

#### Abstraction

> The concept of hiding unnecessary details from the user to make it as user-friendly as possible.
> The user doesn't need to see how a machine works. He just needs to know which buttons to press, not what they actually execute.
> 
><img src="https://www.onlinebuff.com/artimages/php46-abs.jpg" width=250>

#### Attributes / Properties

> Attributes is data that is stored inside a class.
> They store information about this specific instance of a class that you create
> A car has attributes like "fuel", "horsepower, "maxspeed", "fuel type", ...
> 
><img src="https://upload.wikimedia.org/wikipedia/commons/thumb/9/98/CPT-OOP-objects_and_classes_-_attmeth.svg/300px-CPT-OOP-objects_and_classes_-_attmeth.svg.png" width=250>

#### Class

> A user-defined data type holding data members and functions for those memebers.
> "Cars" is a class that has lots of different objects. Like different car models who contain properties like
> their number oh hp, speed limit, or gas milage.
>
><img src="https://ds055uzetaobb.cloudfront.net/image_optimizer/722c82aff075a14313be7fa7463f7fedad151a0a.png" width=250>

#### Class Variable

> A class variable defines a specific attribute for a class. Other than an instance variable, it only has one copy of the variable
> and therefore only hold one variable.
> 

#### Composition

> A composition is a concept where it is possible to "be apart of something", rather than actually being it.
> A car ***has*** an engine, but ***isn't*** an engine.
> This allows stronger encapsulation and makes it easier to read code.
> 
><img src="https://media.istockphoto.com/photos/car-and-chassis-xray-blueprint-picture-id182154020?k=6&m=182154020&s=612x612&w=0&h=RNtSGsbe0_eait80AN33nMNDU5HKqaU2u0DhMO7BTxQ=" width=250>

#### Constructor

> A special method to initialize an object. It is called when an instance of an object is created.
> It is used to either set initial values to attributes or set them to passed in values.
> 
><img src="https://static.wikia.nocookie.net/btb/images/6/68/BobSavestheHedgehogs105.png/revision/latest?cb=20190806061908" width=250>

#### Encapsulation

> The idea of bundling data and methods together.
> "Information hiding" -> hiding specific information from the outside.
> "Enclosing" something in a "capsule"
> 
><img src="https://data-flair.training/blogs/wp-content/uploads/sites/2/2018/02/Encapsulation-in-Java-df.jpg" width=250>

#### Friends

> A function that is not created in the class definition and therefore not in its scope, but has the right to access
> all private and protected members of a class
> 

#### Inheritance

> Classes and objects ***inherit***  properties from their parent class.
> It's like a child that inherits money from their parents without actually having to do anything.
> This prevents them from having to do the same thing that their parents already did and therefore
> making code simpler and easier to read.
> 
><img src="https://miro.medium.com/max/5536/1*CaTNbDiboMzEXuBB2AaDjg.png" width=250>

#### Instance Variable

> An instance variable are created as an instance of an object is created, in main() for example.
> They have access to all the constructors and methods in the class.
> 

#### Member Variable

> This is a variable that's part of a class definition and lives as long as "this" instance of the class
> is living
> 

#### Method

> Methods are functions in OOP. They are part of a class definition and perform actions on member variables,
> rather than just local variables. 
> A dog (class) eats, sleeps, sits, or runs.
>
><imc src="https://www.guru99.com/images/java/052016_0704_ObjectsandC5.jpg" width=250>

#### Multiple Inheritance

> A feature in OOP that allows classes to inherit from multiple classes.
> It's like a kid that has 3 different sets of parents, as it so often happens.
> 
><img src="https://media.geeksforgeeks.org/wp-content/uploads/20191222084630/multipleinh.png" width=250>

#### Object

> An object is an instance defined by its class. It contains data members and functions, so called methods.
> For example "cars" is a class, while each different model is an object, that contains attributes and
> methods.
> 
><img src="https://ds055uzetaobb.cloudfront.net/image_optimizer/722c82aff075a14313be7fa7463f7fedad151a0a.png" width=250>
><img src="https://www.miltonmarketing.com/wp-content/uploads/2018/04/oopconceptimage15345345.png" width=250>

#### Overloading

> Multiple definition for the same function name in the same scope.
> This happens most of the time in class definitions, as there are default
> and non-default constructors. Both with the same name, but different parameters etc.
> 
><img src="https://d1jnx9ba8s6j9r.cloudfront.net/blog/wp-content/uploads/2019/07/mov.png" width=250>

#### Polymorphism

> The ability of an object to take on many different forms. It can take on any form of its inherited (parent) class.
> A man can be a father, husband, employee, ...
> Just like a shape can be a triangle, circle, square, ...
> 
><img src="https://stackify.com/wp-content/uploads/2017/12/OOP-Concept-Polymorphism-1280x720.png" width=250>

#### Public / Private / Protected

> Public:     Everyone can see it
> Private:    Only the class in which it is declared can see it
> Protected:  Only the class in which it is declared can see it + by inheriting classes
> 
><img src="http://1.bp.blogspot.com/_GTJs5hsOIHA/S9sgB1KocpI/AAAAAAAAApg/xAczoUf3ezw/s1600/Private-Protected-Public.JPG" width=250>

#### Static

> If an object is static, then it is initialized once and lives until the program is terminated.
> They are allocated storage in static storage area.
> They're the opposite of local objects which are created each time during a decleration in the execution of a program.
> 

#### Virtual

> A virtual class is a class inside a class (a nested class) 
> 
> A virtual method is declared within the normal base class and re-defined by a derived class.
> They ensure that the correct function is called for an object
> 

