# ft_ls
### [UNDER DEVELOPMENT]
Completion by mid August 2018
***
### Score [TBA]
##### Mandatory
[TBA]/100
##### Bonus
[TBA]/25
***
### Challenge  
To recode the unix list command `ls`.  
  
The function must conform to 42's norm.  
The function cannot leak. All errors must be handled carefully. In no way can the function quit in an unexpected manner (Segmentation fault, bus error, double free, etc).  
Allowed functions for the mandatory part are `write`, `opendir`, `readdir`, `closedir`, `stat`, `lstat`, `getpwuid`, `getgrgid`, `listxattr`, `getxattr`, `time`, `ctime`, `readlink`, `malloc`, `free`, `perror`, `strerror` and `exit`. Everything else is forbidden. Other functions can be used for bonus, but their use must be justified.
***
### Using the project
***Note*** *During development, expected results* ***will*** *differ from `ls`, but will function.*  
  
To compile, run `make`. Follow development with `./ft_ls`. Any number of arguments can be supplied. Arguments should be files or directories. For example:
```console
$> ./ft_ls *
./ft_ls *
8876706  100644  Dav  staff     3745  1532080065  Makefile
8345787  100644  Dav  staff       97  1531434059  README.md
8347636  100644  Dav  staff        6  1531434176  author
8933155  100755  Dav  staff    32512  1532155523  ft_ls
6948983  100644  Dav  staff  1462757  1530300255  ft_ls.en.pdf
8790699  100644  Dav  staff    38688  1532155523  ft_printf.a
8347803  40755   Dav  staff      128  1532159038  includes
8345809  40755   Dav  staff      224  1531985531  libft
8790698  100644  Dav  staff    76336  1532155523  libft.a
8790700  40755   Dav  staff      416  1532155523  obj
8347804  40755   Dav  staff      192  1532077895  srcs
