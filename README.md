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
`-a` ✅Show hidden.  
`-c` ✅Sort by last status change time.  
`-d` ✅Directories are listed as plain files (not searched recursively).  
`-f` ✅Output is not sorted. Forces `-a` on.  
`-g` ✅List in long format but omit owner.  
`-i` ✅Show serial number (inode number).  
`-l` ✅List in long format.  
`-o` ✅List in long format but omit group.   
`-r` ✅Reverse sort.  
`-t` 🔶Sort by time of last modification. *Works except in one case of the same time ft_ls and .*  
`-u` ✅Sort by time of last access.  
`-A` ✅List all entries except for `.` and `..`.  
`-F` ❌Display after pathname: directory, `*`executable, `@`sym link, `=`socket, `%`whiteout, `|`FIFO.  
`-G` 🔶Coloured output. *Operational - just need to add colours for links etc.*  
`-R` ✅Recursively search directories  
`-S` ✅Sort by file size.  
`-T` ✅Show time information in full.  
`-U` ✅Sort by time of file creation.  
`-1` ❌Force output to be one entry per line.  
***
### Using the project
***Note*** *During development, expected results* ***will*** *differ from `ls`, but will function.*  
  
To compile, run `make`. Follow development with `./ft_ls`. Any number of arguments can be supplied. Arguments should be files or directories. For example:
```console
$> ./ft_ls *
.:
-rw-r--r--     1 Dav  staff     4191  7 Aug 09:10 Makefile
-rw-r--r--     1 Dav  staff     3205  7 Aug 09:16 README.md
-rw-r--r--     1 Dav  staff        6 13 Jul 01:22 author
-rwxr-xr-x  1003 Dav  staff    32096 23 Jul 11:51 big
-rwxr-xr-x     1 Dav  staff    53184  7 Aug 09:13 ft_ls
-rwxr-xr-x     3 Dav  staff       96 23 Jul 22:45 ft_ls.dSYM
-rw-r--r--     1 Dav  staff  1462757 29 Jun 22:24 ft_ls.en.pdf
-rw-r--r--     1 Dav  staff    38688  7 Aug 09:13 ft_printf.a
-rwxr-xr-x     3 Dav  staff       96  7 Aug 09:10 includes
-rwxr-xr-x     7 Dav  staff      224  5 Aug 13:09 libft
-rw-r--r--     1 Dav  staff    76336  7 Aug 09:13 libft.a
-rwxr-xr-x    40 Dav  staff     1280  7 Aug 09:13 obj
-rwxr-xr-x     6 Dav  staff      192 20 Jul 12:11 srcs
-rw-r--r--     1 Dav  staff       72 23 Jul 20:25 temp
----------     2 Dav  staff       64 21 Jul 13:39 test_directory
----------     1 Dav  staff        0  5 Aug 15:52 test_file
-rw-r--r--     1 Dav  staff        0  5 Aug  2019 time_test
```
