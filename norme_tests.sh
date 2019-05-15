
#enter path below

cd ft_printf_rendu

echo "\n________________________________________________\n"
echo "\033[92m Run Norminette\033[0m"
echo "\n________________________________________________\n"
norminette -R CheckForbiddenSourceHeader

echo "\n________________________________________________\n"
echo "\033[92m Find includes stdio\033[0m"
echo "\n________________________________________________\n"
grep include\<stdio.h\> * -pr

echo "\033[92m Find all printf\033[0m"
grep printf * -pr

echo "\n________________________________________________\n"
echo "\033[92m Find all EOF w |=& and  spaces\033[0m"
echo "\n________________________________________________\n"
grep "||$" *.c
grep "==$" *.c
grep "&&$" *.c

echo "\n________________________________________________\n"
echo "\033[92m Find all mallocs and dups\033[0m"
echo "\n________________________________________________\n"
grep -R "malloc" *.c
grep -R "ft_strdup" *.c

echo "\n________________________________________________\n"
echo "\033[92m Check author of files\033[0m"
echo "\n________________________________________________\n"
grep -R "by" *.c
