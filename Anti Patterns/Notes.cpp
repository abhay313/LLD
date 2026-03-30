/* 
Anti Patternns:


1. God Object: A class handles multiple operations, but if all work is only delegation
work then its not God Object

Class A {
    m1();
    m2();
    m3();
    etc
}

2. Spaghetti Code: A complex code, not entry point every thing almost connected to each
other, tightly coupled and prone to error

Class A --> Class B --> Class C --> Class A

3. Hard Coding things: avoid it

m1 {
string str = "hello";
}

4. Gold Platting (over engineering): trying to be perfect, all desgin patter
all solid principles, all oops concepts perfectly used --> cover complicate

5. DRY (do not repeat yourself): copying same code -> repeated code should be in common

6. Constructor Overloading: ---> use builder desing pattern

7. Over use of Getter & Setters: 

8: Pre-mature optimization: make it work then make it fast (optimize)
DSA -> Brute force -> then optimized approach

9:  Inheritance overuse:  better use (strategy, visitor, bridge pattern) to reduce hierarchy

*/