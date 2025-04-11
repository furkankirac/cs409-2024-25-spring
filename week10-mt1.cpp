// REGISTERED COURSE: CS409 or CS509
// STUDENT ID:        xxxxxxx
// STUDENT NAME:      xxxxxxx

// !!!!!!!!! FORBIDDENS !!!!!!!!!!
// - You CANNOT use any type-traits or value-traits
//   (std:is_blabla<T>::value, or std::select_xyz<T>::type) are forbidden.
// - You CANNOT use "friend" functions or classes. We didn't learn them.
// - You CANNOT USE MORE THAN 4 (four) struct or class keywords as total.
//   5 struct/class keywords --> zero points
// - You CANNOT USE MORE THAN 5 (five) template keywords as total.
//   6 template keywords --> zero points
// - The code that you filled-in (excluding the HINTS, FORBIDDENs and the main() function)
//   CANNOT CONTAIN MORE THAN 47 semicolumns.
//   (a casually written 37 semicolumn solution is available)
// - Overloading comma operator (operator,) is FORBIDDEN.
// - #define macro usage is FORBIDDEN. Any #define in your code will get zero points.
// ANY CONTRIBUTED CODE HAVING MORE THAN 47 semicolumns WILL GET ZERO POINTS.
// IT IS WISER TO SOLVE THE EXAM PARTIALLY RATHER THAN PASSING THE 47 semicolumn marker.
// ANY CODE NOT OBEYING ANY ONE OF THE FORBIDDEN RULES WILL GET ZERO POINTS.
// CHATTING ABOUT THE PROJECT WITH A LIVING BEING DURING THE EXAM PERIOD IS FORBIDDEN.
//
// HOWEVER, YOU MAY USE ANY HELPER AI SOFTWARE.
// !!!!!!!!! FORBIDDENS !!!!!!!!!!

// !!!!!!!!!!!! MUSTS !!!!!!!!!!!!
// - YOU MUST CREATE Vector by inheriting from std::vector.
//   Vector<T> must support everything std::vector<T> has.
// - YOU MUST CREATE List by inheriting from std::list.
//   List<T> must support everything std::list<T> has.
// - YOU MUST CREATE Array by inheriting from std::array<T, n>.
//   Array<T> must support everything std::array<T, n> has.
// !!!!!!!!!!!! MUSTS !!!!!!!!!!!!

// <<< Check the main() function for questions and grading >>>

// HINTS
// - comma (,) is also an operator similar to semicolumn. comma is compatible with fold expressions
//   (std::cout << "hi"), (std::cout << "there"); is a valid statement
// - std::array does not have its own initializer-list based constructor.
// - some containers have random item access iterators (such as vector),
//   some have unidirectional iterators (you can go forward one by one)
//   some have bidirectional iterators (you can go either forward or backward one by one) std::list, std::array
// - some containers have push_back, some don't

// ------------------------------------------------
//    YOU CAN'T MODIFY ANYTHING BEFORE THIS LINE
// VIOLATION WILL RESULT WITH GETTING A ZERO GRADE
// ------------------------------------------------

// SOLVE HERE

// -----------------------------------------------
//    YOU CAN'T MODIFY ANYTHING AFTER THIS LINE
// VIOLATION WILL RESULT WITH GETTING A ZERO GRADE
// -----------------------------------------------

// PROGRAM'S EXPECTED AND CORRECT CONSOLE OUTPUT IS AS BELOW:
/*
Testing Vector:
container is
0 1 2 3 4 5
> single element access both forward/reverse indexed: c[2], c[-2]
2
4
> range access with (): c($(1, 4)), c($(5, 1))
1 2 3
5 4 3 2
> range access with []: until/from end: c[$(3, end)], c[$(end, 3)]
3 4 5
5 4
I am a Vector.
Testing List:
container is
0 1.1 2.2 3.3 4.4 5.5
> single element access both forward/reverse indexed: c[2], c[-2]
2.2
4.4
> range access with (): c($(1, 4)), c($(5, 1))
1.1 2.2 3.3
5.5 4.4 3.3 2.2
> range access with []: until/from end: c[$(3, end)], c[$(end, 3)]
3.3 4.4 5.5
5.5 4.4
I am a List.
Testing Array:
container is
a b c d e f
> single element access both forward/reverse indexed: c[2], c[-2]
c
e
I am an Array.
*/


// GRADING:
// Please read the forbiddens and musts section at the top of the file first.
// You have 6 questions summing up to 67 points.
// 10 + 12 + 20 + 5 + 10 + 9 = 67
// Solving at least 5 questions correctly with at most 39 semicolumns will get a 1.5 grade multiplier.
// Solving at least 5 questions correctly with at most 42 semicolumns will get a 1.3 grade multiplier.
// Solving at least 5 questions correctly with at most 45 semicolumns will get a 1.1 grade multiplier.
// All other cases will get a 1.0 grade multiplier.
// Using more than 47 semicolumns will get zero points! (48 semicolumns and up will fail the exam)

int main()
{
    // this is an example of how we use generic lamdas with explicit typenames
    auto test_on = []<typename C>(const char* title, const C& c) {
        // Q1) (5 pts) Write print function(s) to make all the below print usages work
        print(title, "container is", c);

        // Q2) (12 pts) Single element access with +idx and -idx for 3 different containers. 2pts each.
        print("> single element access both forward/reverse indexed: c[2], c[-2]", c[2], c[-2]);
        // Program needs Vector<T>, List<T> and Array<T, n> templates to be declared.
        // Note they start with capital letters, they're not from standard library.
        // But you're allowed to use std::* namespace without doing the FORBIDDEN things listed at the top

        // isArray<C> checks if C is array-like and differentiates the code below
        if constexpr(!(isArray<C>)) {
            // Q3) (16 pts) Make container($(x, y)) syntax work both for forward and reverse iteration
            print("> range access with (): c($(1, 4)), c($(5, 1))", c($(1, 4)), c($(5, 1)));
            // Q4) (6 pts) Make container[$(x, y)] syntax work just like $(x, y) syntax
            // Q5) (10 pts) Make "end" sentinel value represent the ending index of the container
            print("> range access with []: until/from end: c[$(3, end)], c[$(end, 3)]", c[$(3, end)], c[$(end, 3)]);
        }
        // Q6) (18 pts) Make whoami() function dispatch to the correct whoami method
        c.whoami();
    };
    auto v = Vector<int>{0, 1, 2, 3, 4, 5};
    auto l = List<double>{0.0, 1.1, 2.2, 3.3, 4.4, 5.5};
    auto a = Array<char, 6>{'a', 'b', 'c', 'd', 'e', 'f'};

    test_on("Testing Vector:", v);
    test_on("Testing List:", l);
    test_on("Testing Array:", a);

    return 0;
}
