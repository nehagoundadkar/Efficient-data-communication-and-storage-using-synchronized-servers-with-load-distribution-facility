string getFileHash(char *fpath)
{
    string fileHash;
    ifstream file1(fpath, ifstream::binary);

    /* basic sanity check */
    if (!file1)
    {
        cout << "FILE DOES NOT EXITST : " << string(fpath) << endl;
        return "-1";
    }

    struct stat fstatus;
    stat(fpath, &fstatus);

    // Logic for deviding file1 into chunks
    long int total_size = fstatus.st_size;
    long int chunk_size = CSIZE;

    int total_chunks = total_size / chunk_size;
    int last_chunk_size = total_size % chunk_size;

    if (last_chunk_size != 0) // if file1 is not exactly divisible by chunks size
    {
        ++total_chunks; // add last chunk to count
    }
    else //when file1 is completely divisible by chunk size
    {
        last_chunk_size = chunk_size;
    }

    // loop to getting each chunk
    for (int chunk = 0; chunk < total_chunks; ++chunk)
    {
        int cur_cnk_size;
        if (chunk == total_chunks - 1)
            cur_cnk_size = last_chunk_size;
        else
            cur_cnk_size = chunk_size;

        char *chunk_data = new char[cur_cnk_size];
        file1.read(chunk_data,    /* address of buffer start */
                   cur_cnk_size); /* this many bytes is to be read */

        string sh1out = calHashofchunk(chunk_data, cur_cnk_size, 1);
        fileHash = fileHash + sh1out;
    }

    return fileHash;
}