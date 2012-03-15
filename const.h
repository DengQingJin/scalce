/// 786

#ifndef CONST_H__
#define CONST_H__

#include <time.h>
#include <stdio.h>
#include <inttypes.h>

#define GLOBALBUFSZ  5*MAXLINE
#define MIN(x,y)  (((x)<(y))?(x):(y))
#define TIME	(time(0)-_time_elapsed)
#define SZ_READ(l)\
	((l / 4) + (l % 4 > 0))
#ifdef DEBUG
#define LOG(c,...)\
	fprintf(stderr, "[%02d:%02d:%02d]: "c, TIME/3600, (TIME/60)%60, TIME%60, ##__VA_ARGS__)
#define DLOG(c,...)\
	fprintf(stderr, "[%02d:%02d:%02d]: "c, TIME/3600, (TIME/60)%60, TIME%60, ##__VA_ARGS__)
#else 
#define LOG(c,...) fprintf(stderr,c,##__VA_ARGS__)
#define DLOG(...)  ;
#endif
#define ERROR(c,...)\
	{ fprintf (stderr, "(ERROR) "c, ##__VA_ARGS__); exit (1); }

#define IO_READ  0
#define IO_WRITE 1
#define IO_SYS   10
#define IO_GZIP  20
#define IO_BZIP  30
#define IO_PGZIP 40

// Max. characters per line
#define MAXLINE 		2500
// Max. files in file pool
#define MAXOPENFILES 20
// Max. concurrent files for merging
#define MAXMERGE     (MAXOPENFILES / 2 - 1)
// Max. bin ID
#define MAXBIN       (1 << 30)
// Max. metadata file size, 200MB, will 
#define MAXMETA      (200 * 1024 * 1024)

// Global program arguments
extern int       _quality_sample_lines;
extern int       _quality_lossy_percentage;
extern char      _use_second_file;
extern char      _use_names;
extern uint64_t  _file_buffer_size;
extern uint64_t  _max_bucket_set_size;
extern char      _temp_directory[MAXLINE];
extern char      _library_name[MAXLINE];
extern int       _time_elapsed;
extern int       _split_reads;
extern int       _compression_mode;
extern int       _thread_count;
extern char      _interleave;

extern int32_t read_length[2];                 /* length of read in one fastq file */
extern int64_t reads_count;                /* total read count in all input files */

int getval (char c);
char *get_second_file (const char *c);

#endif // CONST_H__