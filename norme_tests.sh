echo "\n________________________________________________\n"
echo "\033[92m Find includes stdio\033[0m"
grep include\<stdio.h\> * -pr
echo "\033[92m Find all printf\033[0m"
grep printf * -pr
echo "\n________________________________________________\n"
echo "\033[92m Find all EOF w |=& and  spaces\033[0m"
grep "||$" *.c
grep "==$" *.c
grep "&&$" *.c
echo "\n________________________________________________\n"
echo "\033[92m Find all mallocs and dups\033[0m"
grep -R "malloc" *.c
grep -R "ft_strdup" *.c
