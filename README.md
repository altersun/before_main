# before_main
Run code before main() starts!

## How??
Long story shory, explotation of the `static` keyword.

## ...and why?
The most pratical use case I've found is that, when writing a library, doing some setup that *must* be done for the sake of operations of said library *without* relying on the library user to have to call an `Init()` or something similar.

Other than that it's kind of a neat party trick.

## So, back to how...
The kernel of the idea is fairly simple. Variables defined at the global scope with `static` are initialized before `main()` ever begins. This includes objects, and *objects have constructors*. So the constructor of an object statically defined at global scope will run before `main()`. From there it was a matter of making a system that could take an arbitrary function and stuffing it into the constructor of a globally-scoped statically-defined ojbect.

## How to Use it
There are two macros, `BEFORE_MAIN()` and `BEFORE_MAIN_WITH_ARGS()`, available via `before_main.hpp`. Both take functions that return `void` but the former takes no-argument functions while the latter takes any number of arguments. Both must be invoked outside of any function or there will be a compilation error.

## The Details
### `top_level.hpp`
In making a macro that would run something before main I wanted to make sure it would run *only* before main and would not in main or some other function. The trick here is a static assert against the function where the `BEFORE_MAIN` macro is called using the built-in `__FUNCTION__` macro.

### `unique_name.hpp`
Since each call of the macro requires a uniquely named object under the hood there needed to be a way to name them under the hood. The name is generated based on line number where `BEFORE_MAIN` is called and use of the `__COUNTER__` macro.

### `before_main.hpp`
The heart of the operation! The `BeforeMain` class has two contstructors, one that takes a no-arg `std::function` and another that takes a more generic templated function as well as an argument list.

## The Downside
Each invocation of `BEFORE_MAIN()` or `BEFORE_MAIN_WITH_ARGS()` leaves one useless, invisible object that will forevor be part of the executable with nothing to do after main starts, unfortunately. They should be pretty small and the data size hit should be neglegable unless some maniac uses several thousand of them.

## How do I try it?
Clone this repo and just include `before_main.hpp` into whatever you're working with. Or, try out the sample program under `test/`. Just go into that directory and `make run`.
