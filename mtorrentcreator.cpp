

#include "clientheader.h"

#define CSIZE 512 * 1024

char *filepath, *mtorrentpath;

//***************************************************************************
// It calculate hash(SHA1) of given data chunk
// shorthashflag = 1 means return 20 character of hash
// shorthashflag = 0 means return all 40 character of hash


//***************************************************************************
// This function create mtorrent file by adding all information into it
//***************************************************************************
string createTorrentFile(char *fpath, char *mtpath, string tcksocket1, string tcksocket2)
{
    writelog("Mtorrent creater called for filepath : " + string(fpath));
    struct stat sb;
    if (stat(fpath, &sb) == -1)
    {
        cout << "FILE NOT FOUND" << endl;
        return "-1";
    }

    ofstream myfile;
    myfile.open(string(mtpath));
    myfile << tcksocket1 << endl;
    myfile << tcksocket2 << endl;
    myfile << string(fpath) << endl;
    myfile << sb.st_size << endl;
    string flhash = getFileHash(fpath);
    myfile << flhash << endl;
    myfile.close();
    writelog("Mtorrent Succesfully created");
    return flhash;
}
