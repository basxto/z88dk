/*
 *	long lseek(int fd, long posn, int whence)
 *
 *	Stefano Bodrato - Feb. 2005
 *	Needs optimizations: always re-reads the record
 *
 *	0	SEEK_SET from start of file
 *	1	SEEK_CUR from current position
 *	2	SEEK_END from end of file (always -ve)
 *
 *	$Id: lseek.c $
 */

#include <fcntl.h>
#include <stdio.h>
#include <zxinterface1.h>


long lseek(int handle, long posn, int whence)
{
	struct M_CHAN *if1_file;
	int 	if1_filestatus;
	long	position;
	//unsigned char	mychar;
	
	if1_file = (void *) handle;

	switch (whence) {
		case SEEK_SET:
			if1_load_record(if1_file->drive, if1_file->name, (int)(posn / 512L), if1_file);
			if1_file->position=posn;
			// TODO: update the local record pointers for write access
			break;
		
		case SEEK_CUR:
			position = if1_file->position + posn;
			lseek(handle, position, SEEK_SET);
			break;

		case SEEK_END:
			if1_filestatus = if1_load_record(if1_file->drive, if1_file->name, 0, if1_file);
			// Move up to end of file
			while ((if1_file->recflg && 1) == 0)
				if1_filestatus = if1_load_record(if1_file->drive, if1_file->name, ++if1_file->record, if1_file);
			// now get the latest position and add the offest
			if1_file->position = (long) if1_file->record * 512L + (long) if1_file->reclen;
			//lseek(handle, position, SEEK_SET);
			break;
	}
	return (if1_file->position);
}
