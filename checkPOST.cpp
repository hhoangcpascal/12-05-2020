#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define tfi "POST.INP"
#define tfo "POST.OUT"
#define tfa "POST.ANS"

using namespace std;

FILE    *themis_p_in,     // problem's input
        *themis_p_out,    // problem's output
        *themis_t_out,    // tested program's output
        *themis_t_src,    // tested program's source
        *themis_score,    // score for the program, for challenge problems
        *themis_u_info,   // additional info - psetter only
        *themis_p_info;   // additional info - psetter and solution's owner

void themis_init(const char*, const char*);
void local_init(const char*, const char*, const char*);
void read_in(const char*, ...);
void read_out(const char*, ...);
void read_ans(const char*, ...);
void message(const char*, ...);

int n, m, a[1005], b[1005];
vector<int> A, B;

int main(){
	themis_init(tfi, tfo);
    read_in("%d%d", &n, &m);
    for(int i=1; i<=n; i++) read_in("%d", &a[i]);
    int ans; read_ans("%d", &ans);
    int out; read_out("%d", &out);
    message("%c%c%c", char(239), char(187), char(191));
    if (out <= ans) {
        int res = 0;
        for(int i=1; i<=m; ++i) read_out("%d", &b[i]);
        b[0] = -1000000, b[m+1] = 10000000;
        for(int i=1, l = 1; i<=n; ++i) {
            while (l <= m && b[l] < a[i]) ++l;
            res += min(a[i] - b[l-1], b[l] - a[i]);
        }
        if (res != out) {
            message("\x56\xE1\xBB\x8B\x20\x74\x72\xC3\xAD\x20\xC4\x91\xE1\xBA\xB7\x74\x20\x73\x61\x69\x21\x21\n0.00");
            return 0;
        }
        message("\x4b\xe1\xba\xbf\x74\x20\x71\x75\xe1\xba\xa3\x20\xc4\x91\xc3\xba\x6e\x67\x21\x21\x21\n1.00");
        return 0;
    } else {
        message("\x4b\xe1\xba\xbf\x74\x20\x71\x75\xe1\xba\xa3\x20\x6b\x68\xc3\xb4\x6e\x67\x20\x74\xe1\xbb\x91\x69\x20\xc6\xb0\x75\x21\x21\x21\n0.00");
        return 0;
    }
}

char TestPath[1000], CurrPath[1000];
char fINP[1000], fOUT[1000], fANS[1000];

void themis_init(const char* inName, const char* outName){
    gets(TestPath);
    gets(CurrPath);

    sprintf(fINP, "%s\\%s", TestPath, inName);
    sprintf(fANS, "%s\\%s", TestPath, outName);
    sprintf(fOUT, "%s\\%s", CurrPath, outName);

    themis_p_in     = fopen(fINP, "r");
    themis_p_out    = fopen(fANS, "r");
    themis_t_out    = fopen(fOUT, "r");
}

void local_init(const char* inName, const char* outName, const char* ansName){
    themis_p_in     = fopen(inName, "r");
    themis_p_out    = fopen(ansName, "r");
    themis_t_out    = fopen(outName, "r");
}

void read_in(const char * format, ...){
	va_list args;
	va_start (args, format);
	int res = vfscanf (themis_p_in, format, args);
	va_end (args);
	if(res == EOF){
        message("\x49\x6e\x70\x75\x74\x20\x6b\x68\xc3\xb4\x6e\x67\x20\xc4\x91\xe1\xbb\xa7!!!\n0.00");
        exit(0);
	}
}

void read_ans(const char * format, ...){
	va_list args;
	va_start (args, format);
	int res = vfscanf (themis_p_out, format, args);
	va_end (args);
	if(res == EOF) {
        message("\x41\x6e\x73\x77\x65\x72\x20\x6b\x68\xc3\xb4\x6e\x67\x20\xc4\x91\xe1\xbb\xa7!!!\n0.00");
        exit(0);
	}
}

void read_out(const char * format, ...){
	va_list args;
	va_start (args, format);
	int res = vfscanf (themis_t_out, format, args);
	va_end (args);
	if(res == EOF) {
        message("\x4f\x75\x74\x70\x75\x74\x20\x6b\x68\xc3\xb4\x6e\x67\x20\xc4\x91\xe1\xbb\xa7!!!\n0.00");
        exit(0);
	}
}

void message(const char * format, ...){
	va_list args;
	va_start (args, format);
	vfprintf (stdout, format, args);
	va_end (args);
}
