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
`-t` ✅Sort by time of last modification. *Works except in one case of the same time ft_ls and .*  
`-u` ✅Sort by time of last access.  
`-x` ✅Displays columns horizonaly sorted.  
`-A` ✅List all entries except for `.` and `..`.  
`-F` ✅Display after pathname: `/`directory, `*`executable, `@`sym link, `=`socket, `%`whiteout, `|`FIFO.  
`-G` ✅Coloured output. *Operational - just need to add all colours*  
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
$> ls -l /
total 1999
drwxrwxr-x+ 68 root  admin    2176 24 Aug 14:31 Applications
drwxr-xr-x+ 64 root  wheel    2048 20 Mar 08:00 Library
drwxr-xr-x   2 root  wheel      64 29 Dec  2017 Network
drwxr-xr-x@  4 root  wheel     128  1 Dec  2017 System
drwxr-xr-x   6 root  admin     192 29 Dec  2017 Users
drwxr-xr-x@  4 root  wheel     128 26 Aug 15:35 Volumes
drwxr-xr-x@ 38 root  wheel    1216  1 Dec  2017 bin
drwxrwxr-t   2 root  admin      64 29 Dec  2017 cores
dr-xr-xr-x   3 root  wheel    5165 27 Jul 21:49 dev
lrwxr-xr-x@  1 root  wheel      11 29 Dec  2017 etc -> private/etc
dr-xr-xr-x   2 root  wheel       1 25 Aug 14:39 home
-rw-r--r--   1 root  wheel     313  6 Oct  2017 installer.failurerequests
-rwxr-xr-x@  1 Dav   wheel  210692 17 Dec  2016 lineto-circular-pro-bold.ttf
-rwxr-xr-x@  1 Dav   wheel  197524 17 Dec  2016 lineto-circular-pro-book.ttf
-rwxr-xr-x@  1 Dav   wheel  188952 17 Dec  2016 lineto-circular-pro-bookItalic.ttf
-rwxr-xr-x@  1 Dav   wheel  204160 17 Dec  2016 lineto-circular-pro-medium.ttf
-rwxr-xr-x@  1 Dav   wheel  199380 17 Dec  2016 lineto-circular-pro-mediumItalic.ttf
dr-xr-xr-x   2 root  wheel       1 25 Aug 14:39 net
drwxr-xr-x   6 root  wheel     192 29 Dec  2017 private
drwxr-xr-x@ 63 root  wheel    2016 29 Dec  2017 sbin
lrwxr-xr-x@  1 root  wheel      11 29 Dec  2017 tmp -> private/tmp
drwxr-xr-x@ 10 root  wheel     320 29 Apr 02:51 usr
lrwxr-xr-x@  1 root  wheel      11 29 Dec  2017 var -> private/var
$> ./ft_ls -l /
total 1999
drwxrwxr-x+ 68 root  admin    2176 Aug 24 14:31 Applications
drwxr-xr-x+ 64 root  wheel    2048 Mar 20 08:00 Library
drwxr-xr-x   2 root  wheel      64 Dec 29  2017 Network
drwxr-xr-x@  4 root  wheel     128 Dec  1  2017 System
drwxr-xr-x   6 root  admin     192 Dec 29  2017 Users
drwxr-xr-x@  4 root  wheel     128 Aug 26 15:35 Volumes
drwxr-xr-x@ 38 root  wheel    1216 Dec  1  2017 bin
drwxrwxr-t   2 root  admin      64 Dec 29  2017 cores
dr-xr-xr-x   3 root  wheel    5165 Jul 27 21:49 dev
lrwxr-xr-x@  1 root  wheel      11 Dec 29  2017 etc -> private/etc
dr-xr-xr-x   2 root  wheel       1 Aug 25 14:39 home
-rw-r--r--   1 root  wheel     313 Oct  6  2017 installer.failurerequests
-rwxr-xr-x@  1 Dav   wheel  210692 Dec 17  2016 lineto-circular-pro-bold.ttf
-rwxr-xr-x@  1 Dav   wheel  197524 Dec 17  2016 lineto-circular-pro-book.ttf
-rwxr-xr-x@  1 Dav   wheel  188952 Dec 17  2016 lineto-circular-pro-bookItalic.ttf
-rwxr-xr-x@  1 Dav   wheel  204160 Dec 17  2016 lineto-circular-pro-medium.ttf
-rwxr-xr-x@  1 Dav   wheel  199380 Dec 17  2016 lineto-circular-pro-mediumItalic.ttf
dr-xr-xr-x   2 root  wheel       1 Aug 25 14:39 net
drwxr-xr-x   6 root  wheel     192 Dec 29  2017 private
drwxr-xr-x@ 63 root  wheel    2016 Dec 29  2017 sbin
lrwxr-xr-x@  1 root  wheel      11 Dec 29  2017 tmp -> private/tmp
drwxr-xr-x@ 10 root  wheel     320 Apr 29 02:51 usr
lrwxr-xr-x@  1 root  wheel      11 Dec 29  2017 var -> private/var
```  
##### Bonus
* Displays all illegal options. `ls` only displays 1.
* Replicated every error message
* Handles `--`
* `-N`
* acl
