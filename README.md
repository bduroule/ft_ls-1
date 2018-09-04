# ft_ls
***
### Score 119
##### Mandatory
100/100
##### Bonus
19/19
##### Outstanding Project
5/5
***
### Challenge  
To recode the unix list command `ls`.  
  
The function must conform to 42's norm.  
  
The function cannot leak. All errors must be handled carefully. In no way can the function quit in an unexpected manner (Segmentation fault, bus error, double free, etc).  
  
Allowed functions for the mandatory part are `write`, `opendir`, `readdir`, `closedir`, `stat`, `lstat`, `getpwuid`, `getgrgid`, `listxattr`, `getxattr`, `time`, `ctime`, `readlink`, `malloc`, `free`, `perror`, `strerror` and `exit`. Everything else is forbidden. Other functions can be used for bonus, but their use must be justified.
***
### Using the project
Some macros may be modified in the header file [ft_ls.h](./includes/ft_ls.h).  
- `COLOUR`, Forces on `-G` meaning that colours are always on.
- `COLUMN`, Forces on `'x` meannig that columns are always displayed.  
The default settings are:
```c
# define COLOUR	  true
# define COLUMN	  true
```

To compile, run `make`. This will compile **ft_ls** which can be used with the following usage:  
`usage: ./ft_ls [-AFGNRSTUacdfgiloprtux1] [file ...]`  
`-a` Show hidden. **[MANDATORY]**  
`-c` Sort by last status change time.  
`-d` Directories are listed as plain files (not searched recursively).  
`-f` Output is not sorted. Forces `-a` on.  
`-g` List in long format but omit owner.  
`-i` Show serial number (inode number).  
`-l` List in long format. **[MANDATORY]**  
`-o` List in long format but omit group.  
`-p` Display after pathname: `/`directory.  
`-r` Reverse sort. **[MANDATORY]**  
`-t` Sort by time of last modification. **[MANDATORY]**  
`-u` Sort by time of last access.  
`-x` Displays columns horizontally sorted.  
`-A` List all entries except for `.` and `..`.  
`-F` Display after pathname: `/`directory, `*`executable, `@`sym link, `=`socket, `%`whiteout, `|`FIFO.  
`-G` Coloured output.  
`-N` *(Unique to ft_ls)* Displays number of files read.  
`-R` Recursively search directories **[MANDATORY]**  
`-S` Sort by file size.  
`-T` Show time information in full.  
`-U` Sort by time of file creation.  
`-1` Force output to be one entry per line.  
  
##### Example of ft_ls:
```console
$> ./ft_ls -l /
total 1999
drwxrwxr-x+ 69 root  admin    2208 Aug 31 02:02 Applications
drwxr-xr-x+ 64 root  wheel    2048 Mar 20 08:00 Library
drwxr-xr-x   2 root  wheel      64 Dec 29  2017 Network
drwxr-xr-x@  4 root  wheel     128 Dec  1  2017 System
drwxr-xr-x   6 root  admin     192 Dec 29  2017 Users
drwxr-xr-x@  5 root  wheel     160 Aug 31 07:54 Volumes
drwxr-xr-x@ 38 root  wheel    1216 Dec  1  2017 bin
drwxrwxr-t   2 root  admin      64 Dec 29  2017 cores
dr-xr-xr-x   3 root  wheel    5298 Jul 27 21:49 dev
lrwxr-xr-x@  1 root  wheel      11 Dec 29  2017 etc -> private/etc
dr-xr-xr-x   2 root  wheel       1 Aug 30 23:22 home
dr-xr-xr-x   2 root  wheel       1 Aug 30 23:22 net
drwxr-xr-x   6 root  wheel     192 Dec 29  2017 private
drwxr-xr-x@ 63 root  wheel    2016 Dec 29  2017 sbin
lrwxr-xr-x@  1 root  wheel      11 Dec 29  2017 tmp -> private/tmp
drwxr-xr-x@ 10 root  wheel     320 Apr 29 02:51 usr
lrwxr-xr-x@  1 root  wheel      11 Dec 29  2017 var -> private/var
```
##### Bonus
* Displays all illegal options. `ls` only displays 1.
* Replicated every error message
* Handles `--` (Ends options parsing)
* 17 additional flags including my own `-N`.
* Handles Access Control Lists (`@` and `+` after file permissions).
