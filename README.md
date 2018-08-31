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
Some macros may be modified in the header file [ft_ls.h](./includes/ft_ls.h).  
- `COLOUR`, Forces on `-G` meaning that colours are always on.
- `COLUMN`, Forces on `'x` menanig that columns are always displayed.  
The default settings are:
```c
# define COLOUR	  1
# define COLUMN	  1
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
`-x` Displays columns horizonaly sorted.  
`-A` List all entries except for `.` and `..`.  
`-F` Display after pathname: `/`directory, `*`executable, `@`sym link, `=`socket, `%`whiteout, `|`FIFO.  
`-G` Coloured output.  
`-N` *(Unique to ft_ls)* Displays number of files read.  
`-R` Recursively search directories **[MANDATORY]**  
`-S` Sort by file size.  
`-T` Show time information in full.  
`-U` Sort by time of file creation.  
`-1` Force output to be one entry per line.  
  
##### Bonus
* Displays all illegal options. `ls` only displays 1.
* Replicated every error message
* Handles `--` (Ends options parsing)
* 17 additional flags including my own `-N`.
* Handles Access Control Lists (`@` and `+` after file permissions).
