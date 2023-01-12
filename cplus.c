#include <sys/types.h> 
#include <sys/acct.h> 
#include <stdio.h> 
#include<stdlib.h>
#define ACCTFILE "Users/kritibohra/aditya/acct"
static unsigned long compt2ulong(comp_t);
int main(void) {
    struct acct acdata; FILE *fp;
    if ( (fp = fopen(ACCTFILE, "r")) == NULL)
         printf("can't open %s", ACCTFILE);
    while (fread(&acdata, sizeof(acdata), 1, fp) == 1) {
        printf("%-*.*s e = %6ld, chars = %7ld, "
        "stat = %3u: %c %c %c %c\n", (int)sizeof(acdata.ac_comm),
        (int)sizeof(acdata.ac_comm), acdata.ac_comm,
        compt2ulong(acdata.ac_etime), compt2ulong(acdata.ac_io),
        #ifdef ACORE /* SVR4 doesn't define ACORE */
        acdata.ac_flag & ACORE ? 'D' : ' ',
        #else
        ' ',
        #endif
        #ifdef AXSIG /* SVR4 doesn't define AXSIG */
        acdata.ac_flag & AXSIG ? 'X' : ' ',
        #else
        ' ',
        #endif
        acdata.ac_flag & AFORK ? 'F' : ' ',
        acdata.ac_flag & ASU ? 'S' : ' '); // printf ends here
    } // while loop ends here
    if (ferror(fp)) printf("read error");
    exit(0); }

static unsigned long
compt2ulong (comp_t comptime) /* convert comp_t to unsigned long */
{
    unsigned long val;
    int exp;
    val = comptime & 017777; /* 13-bit fraction */
    exp = (comptime >> 13) & 7; /* 3-bit exponent (0-7) */
    while (exp-- > 0)
    val *= 8;
    return(val);
}
