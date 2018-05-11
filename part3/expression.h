#include <stdio.h>

using namespace std;



int varProcessIndex = 0;




class divideByZeroException:
    public exception{
    virtual const char* what() const throw()
    {
        return "Undefined!";
    }
};

class outOfBoundException:
public exception{
    virtual const char* what() const throw()
    {
        return "Out of bound!";
    }
};



//Comparators

template<int a,int b>
struct MIN
{
    enum 
    {
        eval =((a < b) ? a: b)
    };

};

template<int a,int b>
struct MAX
{
    enum 
    {
        eval = ((a > b) ? a : b)
    };
};




template<class a>
class VIEWBOUNDS{
public:
    static inline int eval(int input[]) {
        printf("Lower bound: %d\n", a::lowerBound);
        printf("Upper bound: %d\n", a::upperBound);

        varProcessIndex = 0;

        return a::eval(input);
    }

    enum {
        lowerBound = a::lowerBound,
        upperBound = a::upperBound
    };

};


template <int i>
class LITERALINTEGER{
	public:
	    static inline int eval(int input[]) {
	        return i;
	    }
        enum 
        {
            lowerBound = i,
            upperBound = i
        };
};

template<class b>
class VAR{
public:
    static inline int eval(int input[]) {
        if(input[varProcessIndex] < b::lowerBound 
            || input[varProcessIndex] > b::upperBound){
            throw outOfBoundException();
        }else{
            //Indicate variable processed
            varProcessIndex++;
            return input[varProcessIndex-1];
        }
    }

    enum {
        lowerBound = b::lowerBound,
        upperBound = b::upperBound
    };
};

template<int a, int b>
class BOUND{
    public:
        enum 
        {
            lowerBound = a,
            upperBound = b
        };
};

template<class a, class b>
class ADD{
    public:
        static inline int eval(int input[]){
            return a::eval(input) + b::eval(input);
        }
        enum 
        {
            lowerBound = MIN<
                            a::lowerBound + b::lowerBound, 
                            a::lowerBound + b::upperBound
                            >::eval,

            upperBound = MAX<
                            a::upperBound + b::upperBound, 
                            a::upperBound + b::lowerBound
                            >::eval
        };
};

template<class a, class b>
class MINUS{
    public:
        static inline int eval(int input[]){
            return a::eval(input) - b::eval(input);
        }
        enum 
        {
            lowerBound = MIN<
                            a::lowerBound - b::lowerBound, 
                            a::lowerBound - b::upperBound
                            >::eval,
            upperBound = MAX<
                            a::upperBound - b::upperBound, 
                            a::upperBound - b::lowerBound
                            >::eval
        };
};

template<class a, class b>
class MULTIPLY{
    public:
        static inline int eval(int input[]){
            return a::eval(input) * b::eval(input);
        }
        enum 
        {
            lowerBound = MIN<
                            MIN<
                                a::lowerBound * b::lowerBound, 
                                a::lowerBound * b::upperBound
                                >::eval,
                            MIN<
                                a::upperBound * b::lowerBound, 
                                a::upperBound * b::upperBound
                                >::eval
                            >::eval,
            upperBound = MAX<
                            MAX<
                                a::lowerBound * b::lowerBound, 
                                a::lowerBound * b::upperBound
                                >::eval,
                            MAX<
                                a::upperBound * b::lowerBound, 
                                a::upperBound * b::upperBound
                                >::eval
                            >::eval
        };
};

template<class a, class b>
class DIVIDE{
public:
    static inline int eval(int input[]) {
        if(b::eval(input) == 0){
            throw divideByZeroException();
        }else{
            return a::eval(input) / b::eval(input);
        }
        enum 
        {
            lowerBound = MIN<
                            MIN<
                                a::lowerBound / b::lowerBound, 
                                a::lowerBound / b::upperBound
                                >::eval,
                            MIN<
                                a::upperBound / b::lowerBound, 
                                a::upperBound / b::upperBound
                                >::eval
                            >::eval,
            upperBound = MAX<
                            MAX<
                                a::lowerBound / b::lowerBound, 
                                a::lowerBound / b::upperBound
                                >::eval,
                            MAX<
                                a::upperBound / b::lowerBound, 
                                a::upperBound / b::upperBound
                                >::eval
                            >::eval
        };
    }
};