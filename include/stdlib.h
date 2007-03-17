#ifndef STDLIB_H
#define STDLIB_H

#define NULL		((void*)0)

#define SEEK_CUR        1
#define SEEK_END        2

#define O_RDONLY        0
#define O_WRONLY        1
#define O_RDWR          2
#define O_TRUNC         0x400
#define O_CREAT         0x200

extern int	rand(void);
extern void*	srand(unsigned int seed);

//extern double log(double x);
extern float logf(float v);
extern float sqrtf(float v);

extern long strlen(const char *s);
extern long sprintf(char *s, const char *st, ...);

extern int isdigit(int c);
extern int isspace(int c);
extern int isalpha(int c);
extern int isupper(int c);

extern int strcmp(const char *s1, const char *s2);
extern int strncmp(const char *s1, const char *s2, long n);
extern char *strchr(const char *s, int c);
extern char *strcpy(char *dest, const char *src);
extern void *memcpy(void *dest, const void *src, long n);
extern void *malloc(long size);
extern void *memset(void *s, int c, int n);
extern void free(void *p);

extern long strtol(const char *nptr, char **endptr, int base);
#define atoi(n) strtol((n),NULL,0)


extern void SleepTask(long msec);
extern long mkdir(const char *dirname);
extern long taskLock();
extern long taskUnlock();

extern long Fopen_Fut(const char *filename, const char *mode);
extern void Fclose_Fut(long file);
extern long Fread_Fut(void *buf, long elsize, long count, long f);
extern long Fwrite_Fut(const void *buf, long elsize, long count, long f);
extern long Fseek_Fut(long file, long offset, long whence);

extern int creat (const char *name, int flags);
extern int open (const char *name, int flags, int mode );
extern int close (int fd);
extern int write (int fd, void *buffer, long nbytes);
extern int read (int fd, void *buffer, long nbytes);
extern int lseek (int fd, long offset, int whence);

#define fopen(a,b) Fopen_Fut(a,b)
#define fclose(a) Fclose_Fut(a)
#define fread(a,b,c,d) Fread_Fut(a,b,c,d)
#define fwrite(a,b,c,d) Fwrite_Fut(a,b,c,d)
#define fseek(a,b,c) Fseek_Fut(a,b,c)

#define DOS_ATTR_RDONLY         0x01            /* read-only file */
#define DOS_ATTR_HIDDEN         0x02            /* hidden file */
#define DOS_ATTR_SYSTEM         0x04            /* system file */
#define DOS_ATTR_VOL_LABEL      0x08            /* volume label (not a file) */
#define DOS_ATTR_DIRECTORY      0x10            /* entry is a sub-directory */
#define DOS_ATTR_ARCHIVE        0x20            /* file subject to archiving */

struct	stat
    {
    unsigned long	st_dev;		/* device ID number */
    unsigned long	st_ino;		/* file serial number */
    unsigned short	st_mode;	/* file mode (see below) */
    short		st_nlink;	/* number of links to file */
    short		st_uid;		/* user ID of file's owner */
    short		st_gid;		/* group ID of file's group */
    unsigned long	st_rdev;	/* device ID, only if special file */
    unsigned long	st_size;	/* size of file, in bytes */
    unsigned long	st_atime;	/* time of last access */
    unsigned long	st_mtime;	/* time of last modification */
    unsigned long	st_ctime;	/* time of last change of file status */
    long		st_blksize;
    long		st_blocks;
    unsigned char	st_attrib;	/* file attribute byte (dosFs only) */
    int			reserved1;	/* reserved for future use */
    int			reserved2;	/* reserved for future use */
    int			reserved3;	/* reserved for future use */
    int			reserved4;	/* reserved for future use */
    int			reserved5;	/* reserved for future use */
    int			reserved6;	/* reserved for future use */
};

struct dirent {
    char                name[100];
};

typedef struct {
    unsigned int        fd;
    unsigned int        loc;
    struct dirent       dir;
} DIR;

extern DIR*           opendir (const char* name);
extern struct dirent* readdir (DIR*);
extern int            closedir (DIR*);
extern void           rewinddir (DIR*);
extern int            stat (char *name, struct stat *pStat);


#endif
