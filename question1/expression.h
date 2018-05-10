#include <stdio.h>

using namespace std;

class divideByZeroException:
    public exception{
    virtual const char* what() const throw()
    {
        return "Undefined!";
    }
};

template<class c>
class EXPRESSION{
	public:
	    static inline int eval(int x) {
	        return c::eval(x);
	    }
};

template <int i>
class LITERALINTEGER{
	public:
	    static inline int eval(int x) {
	        return i;
	    }
};

class VAR{
public:
    static inline int eval(int x) {
        return x;
    }
};

template<class a, class b>
class ADD{
    public:
        static inline int eval(int x){
            return a::eval(x) + b::eval(x);
        }
};

template<class a, class b>
class MINUS{
    public:
        static inline int eval(int x){
            return a::eval(x) - b::eval(x);
        }
};

template<class a, class b>
class MULTIPLY{
    public:
        static inline int eval(int x){
            return a::eval(x) * b::eval(x);
        }
};

template<class a, class b>
class DIVIDE{
public:
    static inline int eval(int x) {
        if(b::eval(x) == 0){
            throw divideByZeroException();
        }else{
            return a::eval(x) / b::eval(x);
        }
    }
};