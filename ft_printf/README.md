*VA_LIST*
va_list - is a data type to store the information about the variable arguments
тип данных, используемый для хранения информации о переменных аргументах функции

va_list factor; // pointer to va_list


*VA_START*
va_start - is a macro that initializes the va_list to the begining of the argument list
(point to the first variable argument)
макрос, который инициализирует va_list на начало списка аргументов

this macro takes two arguments:
1) the name of the va_list
(имя va_list)
2) the name of the last parameter before the variable arguments
(последний известный аргумент функции, перед которым начинается переменное количество аргументов)

va_start(factor, n) // va_start (va_list, last_known_parameter)


*VA_ARG* 
va_arg - is a macro that returns the value of the next argument in the list
макрос, который возвращает значение следующего аргумента в списке
va_arg takes two arguments:
1) va_list
2) the data type of the next argument

va_arg (factor, int) // va_arg (va_list, тип_данных_следующего_аргумента)
va_list should be previously initialized by va_start


*VA_END*

va_end - is a macro that ends the processing of the variable arguments
макрос, который завершает обработку переменных аргументов

va_end (factor) // va_end (va_list)

it must be called before the function returns and after va_start and va_arg have been used
