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
### Development
The following options will be implemented.  
`-a` ❌Show hidden.  
`-c` ❌Sort by last status change time.  
`-d` ❌Directories are listed as plain files (not searched recursively).  
`-f` ✅Output is not sorted. Forces `-a` on.  
`-g` ❌List in long format but omit owner.  
`-i` 🔶Show serial number (inode number). *Operational in long view*  
`-l` ❌List in long format.  
`-o` ❌List in long format but omit group.   
`-r` 🔶Reverse sort. *Operational except were two sort values are identical*  
`-t` ❌Sort by time of last modification.  
`-u` ❌Sort by time of last access.  
`-A` ❌List all entries except for `.` and `..`.  
`-F` ❌Display after pathname: `/`directory, `*`executable, `@`sym link, `=`socket, `%`whiteout, `|`FIFO.  
`-G` ❌Coloured output.  
`-R` ✅Recursively search directories  
`-S` ❌Sort by file size.  
`-U` ❌Sort by time of file creation.  
`-1` ❌Force output to be one entry per line.  
***
### Using the project
***Note*** *During development, expected results* ***will*** *differ from `ls`, but will function.*  
  
To compile, run `make`. Follow development with `./ft_ls`. Any number of arguments can be supplied. Arguments should be files or directories. For example:
```console
$> ./ft_ls *
.:
-rwxr-xr-x      18 Dav  staff      576  Mon Jul 23 16:36:30 2018 .
-rwxr-xr-x      15 Dav  staff      480  Fri Jul 13 21:25:06 2018 ..
-rwxr-xr-x      16 Dav  staff      512  Mon Jul 23 18:11:20 2018 .git
-rw-r--r--       1 Dav  staff     3980  Mon Jul 23 15:56:04 2018 Makefile
-rw-r--r--       1 Dav  staff     1692  Sat Jul 21 17:56:12 2018 README.md
-rw-r--r--       1 Dav  staff        6  Fri Jul 13 01:22:56 2018 author
-rwxr-xr-x       1 Dav  staff    44376  Mon Jul 23 16:36:30 2018 ft_ls
-rw-r--r--       1 Dav  staff  1462757  Fri Jun 29 22:24:15 2018 ft_ls.en.pdf
-rw-r--r--       1 Dav  staff    38688  Mon Jul 23 16:36:30 2018 ft_printf.a
-rwxr-xr-x       3 Dav  staff       96  Mon Jul 23 18:06:44 2018 includes
-rwxr-xr-x       7 Dav  staff      224  Sun Jul 22 23:40:17 2018 libft
-rw-r--r--       1 Dav  staff    76336  Mon Jul 23 16:36:30 2018 libft.a
-rwxr-xr-x      25 Dav  staff      800  Mon Jul 23 16:36:30 2018 obj
-rwxr-xr-x       6 Dav  staff      192  Fri Jul 20 12:11:35 2018 srcs
----------       2 Dav  staff       64  Sat Jul 21 13:39:00 2018 test_directory
----------       1 Dav  staff        0  Sat Jul 21 13:39:34 2018 test_file
```
