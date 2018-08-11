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
`-x` ✅Displays columns horizonaly sorted.  
`-A` ✅List all entries except for `.` and `..`.  
`-F` ❌Display after pathname: directory, `*`executable, `@`sym link, `=`socket, `%`whiteout, `|`FIFO.  
`-G` 🔶Coloured output. *Operational - just need to add colours for links etc.*  
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
$> ./ft_ls *
.:
-rw-r--r--   1 dhojt  2017_paris     4358 11 Aug 19:59 Makefile
-rw-r--r--   1 dhojt  2017_paris     3338 11 Aug 20:26 README.md
-rw-r--r--   1 dhojt  2017_paris        6 11 Aug 17:57 author
-rwxr-xr-x   1 dhojt  2017_paris    59792 11 Aug 20:19 ft_ls
-rw-r--r--   1 dhojt  2017_paris  1462757 11 Aug 17:57 ft_ls.en.pdf
-rw-r--r--   1 dhojt  2017_paris    38688 11 Aug 20:19 ft_printf.a
drwxr-xr-x   3 dhojt  2017_paris      102 11 Aug 20:14 includes
drwxr-xr-x   7 dhojt  2017_paris      238 11 Aug 17:57 libft
-rw-r--r--   1 dhojt  2017_paris    76456 11 Aug 20:19 libft.a
drwxr-xr-x  43 dhojt  2017_paris     1462 11 Aug 20:19 obj
drwxr-xr-x   6 dhojt  2017_paris      204 11 Aug 17:57 srcs
```  
##### Bonus
* Displays all illegal options. `ls` only displays 1.
* Handles `--`
* `-N`
