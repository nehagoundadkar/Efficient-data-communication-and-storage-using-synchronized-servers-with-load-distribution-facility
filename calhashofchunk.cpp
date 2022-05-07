string calHashofchunk(char *schunk, int length1, int shorthashflag)
{

    unsigned char hash[SHA_DIGEST_LENGTH];
    char buf[SHA_DIGEST_LENGTH * 2];
    SHA1((unsigned char *)schunk, length1, hash);

    //printf("\n*****hash ********");
    for (int i = 0; i < SHA_DIGEST_LENGTH; i++)
        sprintf((char *)&(buf[i * 2]), "%02x", hash[i]);

    //cout<<"hash : "<<buf<<endl;
    string ans;
    if (shorthashflag == 1)
    {
        for (int i = 0; i < 20; i++)
        {
            ans += buf[i];
        }
    }
    else
    {
        for (int i = 0; i < SHA_DIGEST_LENGTH * 2; i++)
        {
            ans += buf[i];
        }
    }
    return ans;
}