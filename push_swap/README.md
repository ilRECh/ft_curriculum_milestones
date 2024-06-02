```
Disclaimer
Every symbol, line, file, and folder contained in the present repository was created with one and the only purpose of learning new skills and obtain knowledge.
The repository may contain files which are the property of School21/School42/Éscole42, and were never meant to be neither sold, nor stolen.
```
# push_swap
> Push me<br>
> And then just swap me<br>
> Til I can get my<br>
> Least amount of actions<br>

## In general

This project had to make me sort data on a stack, with a limited set of instructions, using the lowest possible number of actions.<br>
To succeed I had to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.<br>
Turned out that the project was a waste of my precious time.
> Did I ever tell you the definition of insanity? 

## Usage

#### Requirements:
- MacOS/Linux
- make
- gcc

#### Build:
```
make
```
#### Run:
```
./push_swap [any amount of any numbers]
```
i.e.
```
./push_swap 2 4 3 5 61 
```
#### Use:
```
ARG="[any amount of any number]"; ./push_swap $ARG | checker_${your OS here} $ARG
```
Should print **OK**

#### Rules:
##### Numbers must:
1. Be only numerals `1234567890`
2. Be separated by spaces
3. NOT contain duplicates
