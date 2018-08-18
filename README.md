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
`-p` ✅Display after pathname: `/`directory.  
`-r` ✅Reverse sort.  
`-t` 🔶Sort by time of last modification. *Works except in one case of the same time ft_ls and .*  
`-u` ✅Sort by time of last access.  
`-x` ✅Displays columns horizonaly sorted.  
`-A` ✅List all entries except for `.` and `..`.  
`-F` ✅Display after pathname: `/`directory, `*`executable, `@`sym link, `=`socket, `%`whiteout, `|`FIFO.  
`-G` 🔶Coloured output. *Operational - just need to add all colours*  
`-N` ✅Displays number of files read. *Operational but should only print when there are files to display*  
`-R` ✅Recursively search directories  
`-S` ✅Sort by file size.  
`-T` ✅Show time information in full.  
`-U` ✅Sort by time of file creation.  
`-1` ✅Force output to be one entry per line.  
***
### Using the project
***Note*** *During development, expected results* ***will*** *differ from `ls`, but will function.*  
  
To compile, run `make`. Follow development with `./ft_ls`. Any number of arguments can be supplied. Arguments should be files or directories. For example:
```console
$> ./ft_ls -l
.:
-rw-r--r--     1 dhojt  2017_paris     4412 Aug 18 14:59 Makefile
-rw-r--r--     1 dhojt  2017_paris     3026 Aug 18 16:33 README.md
-rw-r--r--     1 dhojt  2017_paris       64 Aug 15 17:56 TODO
-rw-r--r--     1 dhojt  2017_paris        6 Aug 11 17:57 author
drwxr-xr-x  1002 dhojt  2017_paris    34068 Aug 15 13:22 big
-rwxr-xr-x     1 dhojt  2017_paris    60876 Aug 18 17:07 ft_ls
drwxr-xr-x     3 dhojt  2017_paris      102 Aug 11 21:58 ft_ls.dSYM
-rw-r--r--     1 dhojt  2017_paris  1462757 Aug 11 17:57 ft_ls.en.pdf
-rw-r--r--     1 dhojt  2017_paris    38696 Aug 18 17:07 ft_printf.a
drwxr-xr-x     3 dhojt  2017_paris      102 Aug 18 16:54 includes
drwxr-xr-x     7 dhojt  2017_paris      238 Aug 15 17:38 libft
-rw-r--r--     1 dhojt  2017_paris    76336 Aug 18 17:07 libft.a
lrwxr-xr-x     1 dhojt  2017_paris       18 Aug 17 16:35 link_ft_ls -> srcs/ft_ls/ft_ls.c
lrwxr-xr-x     1 dhojt  2017_paris        4 Aug 17 16:35 link_to_todo -> TODO
drwxr-xr-x    46 dhojt  2017_paris     1564 Aug 18 17:07 obj
drwxr-xr-x     6 dhojt  2017_paris      204 Aug 11 17:57 srcs
```  
##### Bonus
* Displays all illegal options. `ls` only displays 1.
* Handles `--`
* `-N`
